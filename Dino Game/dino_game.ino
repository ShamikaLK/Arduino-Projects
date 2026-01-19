#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // Initialize LCD with I2C address 0x27, 16 columns, 2 rows | LCD I2C ලිපිනය 0x27, 16 තීරු, 2 පේළි සමග ආරම්භ කරන්න

#define PIN_BUTTON 2 // Button pin for jumping | පනින්න බොත්තම් පින් එක
#define PIN_AUTOPLAY 1 // Autoplay control pin | ස්වයංක්‍රීය ක්‍රීඩා පාලක පින් එක
#define PIN_READWRITE 10 // Read/write control pin | කියවුම්/ලිවුම් පාලක පින් එක
#define PIN_CONTRAST 7 // LCD contrast control pin | LCD වර්ණ වෙනස් පාලක පින් එක
#define SPRITE_RUN1 1 // Sprite ID for running pose 1 | දිවීමේ ආකාරය 1 සඳහා ස්ප්‍රයිට් ID
#define SPRITE_RUN2 2 // Sprite ID for running pose 2 | දිවීමේ ආකාරය 2 සඳහා ස්ප්‍රයිට් ID
#define SPRITE_JUMP 3 // Sprite ID for jumping | පැනීම සඳහා ස්ප්‍රයිට් ID
#define SPRITE_JUMP_UPPER '.' // Use the '.' character for the head | හිස සඳහා '.' අකුර භාවිතා කරන්න
#define SPRITE_JUMP_LOWER 4 // Lower part of jumping sprite | පැනීමේ ස්ප්‍රයිට් එකේ පහළ කොටස
#define SPRITE_TERRAIN_EMPTY ' ' // Use the ' ' character | හිස් අවකාශය සඳහා ' ' අකුර භාවිතා කරන්න
#define SPRITE_TERRAIN_SOLID 5 // Solid terrain sprite | ඝන භූමිය ස්ප්‍රයිට් එක
#define SPRITE_TERRAIN_SOLID_RIGHT 6 // Right edge of solid terrain | ඝන භූමියේ දකුණු දාරය
#define SPRITE_TERRAIN_SOLID_LEFT 7 // Left edge of solid terrain | ඝන භූමියේ වම් දාරය

#define HERO_HORIZONTAL_POSITION 1 // Horizontal position of hero on screen | තිරය මත නායකයාගේ තිරස් ස්ථානය

#define TERRAIN_WIDTH 16 // Width of terrain display | භූමිය ප්‍රදර්ශනයේ පළල
#define TERRAIN_EMPTY 0 // Empty terrain type | හිස් භූමි වර්ගය
#define TERRAIN_LOWER_BLOCK 1 // Lower block terrain type | පහළ බ්ලොක් භූමි වර්ගය
#define TERRAIN_UPPER_BLOCK 2 // Upper block terrain type | ඉහළ බ්ලොක් භූමි වර්ගය

#define HERO_POSITION_OFF 0 // Hero is invisible | නායකයා දක්නට නොමැත
#define HERO_POSITION_RUN_LOWER_1 1 // Hero is running on lower row (pose 1) | නායකයා පහළ පේළියේ දිවයි (ආකාරය 1)
#define HERO_POSITION_RUN_LOWER_2 2 // Hero is running on lower row (pose 2) | නායකයා පහළ පේළියේ දිවයි (ආකාරය 2)

#define HERO_POSITION_JUMP_1 3 // Starting a jump | පැනීම ආරම්භ කරයි
#define HERO_POSITION_JUMP_2 4 // Half-way up | උඩු අර්ධයේ
#define HERO_POSITION_JUMP_3 5 // Jump is on upper row | පැනීම ඉහළ පේළියේ
#define HERO_POSITION_JUMP_4 6 // Jump is on upper row | පැනීම ඉහළ පේළියේ
#define HERO_POSITION_JUMP_5 7 // Jump is on upper row | පැනීම ඉහළ පේළියේ
#define HERO_POSITION_JUMP_6 8 // Jump is on upper row | පැනීම ඉහළ පේළියේ
#define HERO_POSITION_JUMP_7 9 // Half-way down | පහළ අර්ධයේ
#define HERO_POSITION_JUMP_8 10 // About to land | ගොඩබෑමට සූදානම් වෙමින්

#define HERO_POSITION_RUN_UPPER_1 11 // Hero is running on upper row (pose 1) | නායකයා ඉහළ පේළියේ දිවයි (ආකාරය 1)
#define HERO_POSITION_RUN_UPPER_2 12 // Hero is running on upper row (pose 2) | නායකයා ඉහළ පේළියේ දිවයි (ආකාරය 2)

static char terrainUpper[TERRAIN_WIDTH + 1]; // Upper terrain array | ඉහළ භූමි අරාව
static char terrainLower[TERRAIN_WIDTH + 1]; // Lower terrain array | පහළ භූමි අරාව
static bool buttonPushed = false; // Button push flag | බොත්තම් එබීම් කොඩිය

void initializeGraphics() {
  // Define custom character graphics for LCD | LCD සඳහා අභිරුචි අක්ෂර ග්‍රැෆික්ස් අර්ථ දක්වන්න
  static byte graphics[] = 
  {
    // Dino Run position 1 | ඩයිනෝ දිවීමේ ස්ථානය 1
    B11110,
    B10111,
    B11110,
    B11100,
    B11111,
    B11100,
    B10010,
    B11011,
    // Dino Run position 2 | ඩයිනෝ දිවීමේ ස්ථානය 2
    B11110,
    B10111,
    B11110,
    B11100,
    B11111,
    B11100,
    B01010,
    B10011,
    // Dino Jump | ඩයිනෝ පැනීම
    B11110,
    B10111,
    B11110,
    B11100,
    B11111,
    B11110,
    B10001,
    B00000,
    // Jump lower part [lower part of Dino while jumping] | පැනීමේ පහළ කොටස [පැනීමේදී ඩයිනෝවේ පහළ කොටස]
    B11111,
    B11100,
    B10010,
    B11011,
    B00000,
    B00000,
    B00000,
    B00000,
    // Cactus Center part | කටටස් මැද කොටස
    B00100,
    B11111,
    B00100,
    B00101,
    B11111,
    B00100,
    B00100,
    B00100,
    // Cactus right part | කටටස් දකුණු කොටස
    B00000,
    B00011,
    B00000,
    B00000,
    B00011,
    B00000,
    B00000,
    B00000,
    // Cactus left part | කටටස් වම් කොටස
    B00000,
    B11000,
    B00000,
    B01000,
    B11000,
    B00000,
    B00000,
    B00000,
    // Jump upper part [upper part of Dino while jumping] | පැනීමේ ඉහළ කොටස [පැනීමේදී ඩයිනෝවේ ඉහළ කොටස]
    B00000,
    B00000,
    B00000,
    B00000,
    B11110,
    B10111,
    B11110,
    B11100,
  };
  int i;
  // Create custom characters in LCD memory | LCD මතකයේ අභිරුචි අක්ෂර සාදන්න
  for (i = 0; i < 7; ++i) {
    lcd.createChar(i + 1, &graphics[i * 8]);
  }
  // Initialize terrain arrays to empty | භූමි අරා හිස් කර ආරම්භ කරන්න
  for (i = 0; i < TERRAIN_WIDTH; ++i) {
    terrainUpper[i] = SPRITE_TERRAIN_EMPTY;
    terrainLower[i] = SPRITE_TERRAIN_EMPTY;
  }
}

// Advance terrain to the left | භූමිය වමට ගෙන යන්න
void advanceTerrain(char* terrain, byte newTerrain) {
  for (int i = 0; i < TERRAIN_WIDTH; ++i) {
    char current = terrain[i]; // Current terrain at position i | i ස්ථානයේ වත්මන් භූමිය
    char next = (i == TERRAIN_WIDTH - 1) ? newTerrain : terrain[i + 1]; // Next terrain | ඊළඟ භූමිය
    // Determine new terrain appearance based on current and next | වත්මන් සහ ඊළඟ භූමිය මත නව භූමි පෙනුම තීරණය කරන්න
    switch (current) {
      case SPRITE_TERRAIN_EMPTY:
        terrain[i] = (next == SPRITE_TERRAIN_SOLID) ? SPRITE_TERRAIN_SOLID_RIGHT : SPRITE_TERRAIN_EMPTY;
        break;
      case SPRITE_TERRAIN_SOLID:
        terrain[i] = (next == SPRITE_TERRAIN_EMPTY) ? SPRITE_TERRAIN_SOLID_LEFT : SPRITE_TERRAIN_SOLID;
        break;
      case SPRITE_TERRAIN_SOLID_RIGHT:
        terrain[i] = SPRITE_TERRAIN_SOLID;
        break;
      case SPRITE_TERRAIN_SOLID_LEFT:
        terrain[i] = SPRITE_TERRAIN_EMPTY;
        break;
    }
  }
}

// Draw hero on screen and check for collisions | තිරය මත නායකයා ඇඳීම සහ ගැටීම් පරීක්ෂා කිරීම
bool drawHero(byte position, char* terrainUpper, char* terrainLower, unsigned int score) {
  bool collide = false; // Collision detection flag | ගැටීම් හඳුනාගැනීමේ කොඩිය
  char upperSave = terrainUpper[HERO_HORIZONTAL_POSITION]; // Save original upper terrain | මුල් ඉහළ භූමිය සුරකින්න
  char lowerSave = terrainLower[HERO_HORIZONTAL_POSITION]; // Save original lower terrain | මුල් පහළ භූමිය සුරකින්න
  byte upper, lower; // Hero sprite positions | නායක ස්ප්‍රයිට් ස්ථාන

  // Determine hero sprite based on position | ස්ථානය මත නායක ස්ප්‍රයිට් තීරණය කරන්න
  switch (position) {
    case HERO_POSITION_OFF:
      upper = lower = SPRITE_TERRAIN_EMPTY;
      break;
    case HERO_POSITION_RUN_LOWER_1:
      upper = SPRITE_TERRAIN_EMPTY;
      lower = SPRITE_RUN1;
      break;
    case HERO_POSITION_RUN_LOWER_2:
      upper = SPRITE_TERRAIN_EMPTY;
      lower = SPRITE_RUN2;
      break;
    case HERO_POSITION_JUMP_1:
    case HERO_POSITION_JUMP_8:
      upper = SPRITE_TERRAIN_EMPTY;
      lower = SPRITE_JUMP;
      break;
    case HERO_POSITION_JUMP_2:
    case HERO_POSITION_JUMP_7:
      upper = SPRITE_JUMP_UPPER;
      lower = SPRITE_JUMP_LOWER;
      break;
    case HERO_POSITION_JUMP_3:
    case HERO_POSITION_JUMP_4:
    case HERO_POSITION_JUMP_5:
    case HERO_POSITION_JUMP_6:
      upper = SPRITE_JUMP;
      lower = SPRITE_TERRAIN_EMPTY;
      break;
    case HERO_POSITION_RUN_UPPER_1:
      upper = SPRITE_RUN1;
      lower = SPRITE_TERRAIN_EMPTY;
      break;
    case HERO_POSITION_RUN_UPPER_2:
      upper = SPRITE_RUN2;
      lower = SPRITE_TERRAIN_EMPTY;
      break;
  }

  // Place hero on terrain and check for collisions | නායකයා භූමිය මත තබා ගැටීම් පරීක්ෂා කරන්න
  if (upper != ' ') {
    terrainUpper[HERO_HORIZONTAL_POSITION] = upper;
    collide = (upperSave == SPRITE_TERRAIN_EMPTY) ? false : true;
  }
  if (lower != ' ') {
    terrainLower[HERO_HORIZONTAL_POSITION] = lower;
    collide |= (lowerSave == SPRITE_TERRAIN_EMPTY) ? false : true;
  }

  // Calculate number of digits for score display | ලකුණු ප්‍රදර්ශනය සඳහා ඉලක්කම් ගණන ගණනය කරන්න
  byte digits = (score > 9999) ? 5 : (score > 999) ? 4 : (score > 99) ? 3 : (score > 9) ? 2 : 1;

  // Prepare terrain strings for display | ප්‍රදර්ශනය සඳහා භූමි නූල් සකස් කරන්න
  terrainUpper[TERRAIN_WIDTH] = '\0';
  terrainLower[TERRAIN_WIDTH] = '\0';
  char temp = terrainUpper[16 - digits];
  terrainUpper[16 - digits] = '\0';

  // Display upper terrain and score | ඉහළ භූමිය සහ ලකුණු ප්‍රදර්ශනය කරන්න
  lcd.setCursor(0, 0);
  lcd.print(terrainUpper);
  terrainUpper[16 - digits] = temp;
  
  // Display lower terrain | පහළ භූමිය ප්‍රදර්ශනය කරන්න
  lcd.setCursor(0, 1);
  lcd.print(terrainLower);

  // Display score at right side | දකුණු පැත්තේ ලකුණු ප්‍රදර්ශනය කරන්න
  lcd.setCursor(16 - digits, 0);
  lcd.print(score);

  // Restore original terrain | මුල් භූමිය ප්‍රතිස්ථාපනය කරන්න
  terrainUpper[HERO_HORIZONTAL_POSITION] = upperSave;
  terrainLower[HERO_HORIZONTAL_POSITION] = lowerSave;
  return collide; // Return collision status | ගැටීම් තත්වය ආපසු ලබා දෙන්න
}

// Handle the button push as an interrupt | බොත්තම් එබීම interrupt ලෙස හසුරුවන්න
void buttonPush() {
  buttonPushed = true; // Set button pushed flag | බොත්තම් එබූ කොඩිය සකසන්න
}

void setup() {
  // Initialize pins | පින් ආරම්භ කරන්න
  pinMode(PIN_READWRITE, OUTPUT);
  digitalWrite(PIN_READWRITE, LOW);
  pinMode(PIN_CONTRAST, OUTPUT);
  digitalWrite(PIN_CONTRAST, LOW);
  pinMode(PIN_BUTTON, INPUT);
  digitalWrite(PIN_BUTTON, HIGH);
  pinMode(PIN_AUTOPLAY, OUTPUT);
  digitalWrite(PIN_AUTOPLAY, HIGH);
  
  // Initialize the LCD | LCD ආරම්භ කරන්න
  lcd.begin();
  lcd.backlight();

  // Attach interrupt for button push | බොත්තම් එබීම සඳහා interrupt අනුබන්ධනය කරන්න
  attachInterrupt(digitalPinToInterrupt(PIN_BUTTON), buttonPush, FALLING);
  
  initializeGraphics(); // Initialize custom graphics | අභිරුචි ග්‍රැෆික්ස් ආරම්භ කරන්න
}

void loop() {
  static byte heroPos = HERO_POSITION_RUN_LOWER_1; // Current hero position | වත්මන් නායක ස්ථානය
  static byte newTerrainType = TERRAIN_EMPTY; // Type of new terrain to generate | ජනනය කිරීමට නව භූමි වර්ගය
  static byte newTerrainDuration = 1; // Duration of current terrain type | වත්මන් භූමි වර්ගයේ කාලසීමාව
  static bool playing = false; // Game playing state | ක්‍රීඩා කිරීමේ තත්වය
  static bool blink = false; // Blink state for start screen | ආරම්භක තිරය සඳහා මෙරවීමේ තත්වය
  static unsigned int distance = 0; // Distance traveled | ගමන් කළ දුර
  
  // Start screen display | ආරම්භක තිර ප්‍රදර්ශනය
  if (!playing) {
    drawHero((blink) ? HERO_POSITION_OFF : heroPos, terrainUpper, terrainLower, distance >> 3);
    if (blink) {
      lcd.setCursor(0,0);
      lcd.print("Press Start");
    }
    delay(250);
    blink = !blink; // Toggle blink state | මෙරවීමේ තත්වය toggle කරන්න
    if (buttonPushed) {
      initializeGraphics(); // Reset graphics | ග්‍රැෆික්ස් ප්‍රතිස්ථාපනය කරන්න
      heroPos = HERO_POSITION_RUN_LOWER_1;
      playing = true; // Start game | ක්‍රීඩාව ආරම්භ කරන්න
      buttonPushed = false;
      distance = 0; // Reset distance | දුර ප්‍රතිස්ථාපනය කරන්න
    }
    return;
  }

  // Shift the terrain to the left | භූමිය වමට මාරු කරන්න
  advanceTerrain(terrainLower, newTerrainType == TERRAIN_LOWER_BLOCK ? SPRITE_TERRAIN_SOLID : SPRITE_TERRAIN_EMPTY);
  advanceTerrain(terrainUpper, newTerrainType == TERRAIN_UPPER_BLOCK ? SPRITE_TERRAIN_SOLID : SPRITE_TERRAIN_EMPTY);
  
  // Generate new terrain | නව භූමිය ජනනය කරන්න
  if (--newTerrainDuration == 0) {
    if (newTerrainType == TERRAIN_EMPTY) {
      newTerrainType = (random(3) == 0) ? TERRAIN_UPPER_BLOCK : TERRAIN_LOWER_BLOCK;
      newTerrainDuration = 2 + random(10);
    } else {
      newTerrainType = TERRAIN_EMPTY;
      newTerrainDuration = 10 + random(10);
    }
  }
    
  // Handle jump when button is pushed | බොත්තම එබූ විට පැනීම හසුරුවන්න
  if (buttonPushed) {
    if (heroPos <= HERO_POSITION_RUN_LOWER_2) heroPos = HERO_POSITION_JUMP_1;
    buttonPushed = false;
  }  

  // Draw hero and check for collision | නායකයා අඳින්න සහ ගැටීම් පරීක්ෂා කරන්න
  if (drawHero(heroPos, terrainUpper, terrainLower, distance >> 3)) {
    playing = false; // The hero collided with something. Game over. | නායකයා යමක් සමග ගැටුණි. ක්‍රීඩාව අවසන්.
  } else {
    // Update hero position based on current state | වත්මන් තත්වය මත නායක ස්ථානය යාවත්කාලීන කරන්න
    if (heroPos == HERO_POSITION_RUN_LOWER_2 || heroPos == HERO_POSITION_JUMP_8) {
      heroPos = HERO_POSITION_RUN_LOWER_1;
    } else if ((heroPos >= HERO_POSITION_JUMP_3 && heroPos <= HERO_POSITION_JUMP_5) && terrainLower[HERO_HORIZONTAL_POSITION] != SPRITE_TERRAIN_EMPTY) {
      heroPos = HERO_POSITION_RUN_UPPER_1;
    } else if (heroPos >= HERO_POSITION_RUN_UPPER_1 && terrainLower[HERO_HORIZONTAL_POSITION] == SPRITE_TERRAIN_EMPTY) {
      heroPos = HERO_POSITION_JUMP_5;
    } else if (heroPos == HERO_POSITION_RUN_UPPER_2) {
      heroPos = HERO_POSITION_RUN_UPPER_1;
    } else {
      ++heroPos;
    }
    ++distance; // Increase distance traveled | ගමන් කළ දුර වැඩි කරන්න
    
    // Control autoplay based on terrain ahead | ඉදිරියේ ඇති භූමිය මත ස්වයංක්‍රීය ක්‍රීඩාව පාලනය කරන්න
    digitalWrite(PIN_AUTOPLAY, terrainLower[HERO_HORIZONTAL_POSITION + 2] == SPRITE_TERRAIN_EMPTY ? HIGH : LOW);
  }
  
  delay(100); // Game speed delay | ක්‍රීඩා වේග ප්‍රමාදය
}