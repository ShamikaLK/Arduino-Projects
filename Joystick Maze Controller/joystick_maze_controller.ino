// Include the Servo library | Servo library එක ඇතුළත් කරන්න
#include <Servo.h>

// Create servo objects for two servos | servo එකේ දෙකක් සඳහා object එක නිර්මාණය කරන්න
Servo servo1; // First servo object | පළමු servo object එක
Servo servo2; // Second servo object | දෙවන servo object එක

// Define joystick analog input pins | ජොයිස්ටික් ඇනලොග් ආදාන පින් අර්ථ දැක්වීම
int joyX = 0; // Analog pin A0 for X-axis joystick | X-අක්ෂ ජොයිස්ටික් සඳහා A0 ඇනලොග් පින්
int joyY = 1; // Analog pin A1 for Y-axis joystick | Y-අක්ෂ ජොයිස්ටික් සඳහා A1 ඇනලොග් පින්

// Variable to store joystick reading temporarily | ජොයිස්ටික් කියවීම් තාවකාලිකව ගබඩා කිරීමට විචල්යය
int servoVal;

// Timer variables for controlling Serial output frequency | සීරියල් ප්‍රතිදාන අධික සංඛ්යාතය පාලනය කිරීම සඳහා ටයිමර් විචල්යයන්
unsigned long previousMillis = 0; // Stores the last time Serial output was printed | අවසන් වරට සීරියල් ප්‍රතිදානය මුද්‍රණය කරන ලද කාලය ගබඩා කරයි
const long interval = 500;        // Interval between Serial outputs (500 milliseconds = 0.5 seconds) | සීරියල් ප්‍රතිදාන අතර විරාමය (500 මිලිතත්පර = තත්පර 0.5)

void setup() {
  // Initialize serial communication at 9600 baud rate | බවුඩ් අනුපාත 9600 දී සීරියල් සන්නිවේදනය ආරම්භ කරන්න
  Serial.begin(9600); 
  
  // Attach servos to PWM digital pins | සර්වෝ PWM ඩිජිටල් පින් වලට අමුණන්න
  servo1.attach(3);    // Connect servo1 to digital pin 3 (PWM capable) | servo1 ඩිජිටල් පින් 3 වෙත සම්බන්ධ කරන්න (PWM හැකියාව)
  servo2.attach(5);    // Connect servo2 to digital pin 5 (PWM capable) | servo2 ඩිජිටල් පින් 5 වෙත සම්බන්ධ කරන්න (PWM හැකියාව)
}

void loop() {
  // Read and control servo1 based on X-axis joystick movement | X-අක්ෂ ජොයිස්ටික් චලනය මත පදනම්ව servo1 කියවා පාලනය කරන්න
  servoVal = analogRead(joyX); // Read X-axis joystick value (0-1023) | X-අක්ෂ ජොයිස්ටික් අගය කියවන්න (0-1023)
  
  // Map joystick value (0-1023) to servo position (180-130 degrees)
  // Note: 180 to 130 range means joystick left = 180°, right = 130°
  // ජොයිස්ටික් අගය (0-1023) සර්වෝ ස්ථානයට (180-130 අංශක) සිතියම් ගත කරන්න
  // සටහන: 180 සිට 130 පරාසය යනු ජොයිස්ටික් වම = 180°, දකුණ = 130°
  int servo1Pos = map(servoVal, 0, 1023, 180, 130);
  servo1.write(servo1Pos); // Move servo1 to calculated position | servo1 ගණනය කළ ස්ථානයට ගෙන යන්න

  // Read and control servo2 based on Y-axis joystick movement | Y-අක්ෂ ජොයිස්ටික් චලනය මත පදනම්ව servo2 කියවා පාලනය කරන්න
  servoVal = analogRead(joyY); // Read Y-axis joystick value (0-1023) | Y-අක්ෂ ජොයිස්ටික් අගය කියවන්න (0-1023)
  
  // Map joystick value (0-1023) to servo position (130-180 degrees)
  // Note: 130 to 180 range means joystick down = 130°, up = 180°
  // ජොයිස්ටික් අගය (0-1023) සර්වෝ ස්ථානයට (130-180 අංශක) සිතියම් ගත කරන්න
  // සටහන: 130 සිට 180 පරාසය යනු ජොයිස්ටික් පහල = 130°, ඉහල = 180°
  int servo2Pos = map(servoVal, 0, 1023, 130, 180);
  servo2.write(servo2Pos); // Move servo2 to calculated position | servo2 ගණනය කළ ස්ථානයට ගෙන යන්න

  // Check if it's time to print to Serial Monitor | සීරියල් මොනිටරයට මුද්‍රණය කිරීමට කාලය තිබේදැයි පරීක්ෂා කරන්න
  unsigned long currentMillis = millis(); // Get current time in milliseconds | වර්තමාන කාලය මිලිතත්පර වලින් ලබා ගන්න
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; // Update the timer for next interval | ඊළඟ විරාමය සඳහා ටයිමරය යාවත්කාලීන කරන්න

    // Print joystick and servo positions to Serial Monitor | සීරියල් මොනිටරයට ජොයිස්ටික් සහ සර්වෝ ස්ථාන මුද්‍රණය කරන්න
    Serial.print("Joystick X: ");
    Serial.print(analogRead(joyX)); // Display raw X-axis joystick value | කඩිසර X-අක්ෂ ජොයිස්ටික් අගය පෙන්වන්න
    Serial.print(" -> Servo1 Position: ");
    Serial.println(servo1Pos); // Display servo1 position in degrees | අංශක වලින් servo1 ස්ථානය පෙන්වන්න

    Serial.print("Joystick Y: ");
    Serial.print(analogRead(joyY)); // Display raw Y-axis joystick value | කඩිසර Y-අක්ෂ ජොයිස්ටික් අගය පෙන්වන්න
    Serial.print(" -> Servo2 Position: ");
    Serial.println(servo2Pos); // Display servo2 position in degrees | අංශක වලින් servo2 ස්ථානය පෙන්වන්න
  }

  delay(50); // Small delay for stable servo movement and to reduce processing load | ස්ථායී සර්වෝ චලනය සඳහා සහ ප්‍රවර්ධන බර අඩු කිරීම සඳහා කුඩා ප්‍රමාදයක්
}