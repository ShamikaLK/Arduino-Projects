// Include the Servo library for controlling servo motors | සර්වෝ මෝටර් පාලනය සඳහා Servo පුස්තකාලය ඇතුළත් කරන්න
#include <Servo.h>

// Define our servo objects | අපගේ සර්වෝ වස්තූන් අර්ථ දැක්වීම
Servo servo1; // First servo for X-axis control | X-අක්ෂ පාලනය සඳහා පළමු සර්වෝව
Servo servo2; // Second servo for Y-axis control | Y-අක්ෂ පාලනය සඳහා දෙවන සර්වෝව

// Define joystick analog input pins | ජොයිස්ටික් ඇනලොග් ආදාන පින් අර්ථ දැක්වීම
int joyX = 0; // X-axis connected to analog pin A0 | X-අක්ෂය ඇනලොග් පින් A0 වෙත සම්බන්ධ කර ඇත
int joyY = 1; // Y-axis connected to analog pin A1 | Y-අක්ෂය ඇනලොග් පින් A1 වෙත සම්බන්ධ කර ඇත

// Variables to read values from analog pins and store current positions | ඇනලොග් පින් වලින් අගයන් කියවීම සහ වර්තමාන ස්ථාන ගබඩා කිරීම සඳහා විචල්යයන්
int joyValX, joyValY; // Store joystick read values | ජොයිස්ටික් කියවන අගයන් ගබඩා කරයි
int currentPos1 = 90; // Initial servo1 position (center: 90 degrees) | ආරම්භක servo1 ස්ථානය (මධ්‍යය: අංශක 90)
int currentPos2 = 90; // Initial servo2 position (center: 90 degrees) | ආරම්භක servo2 ස්ථානය (මධ්‍යය: අංශක 90)

void setup()
{ 
  // Attach our servos to PWM pins 3 and 5 | අපගේ සර්වෝ PWM පින් 3 සහ 5 වලට අමුණන්න
  servo1.attach(3); // Servo1 connected to digital pin 3 (PWM capable) | Servo1 ඩිජිටල් පින් 3 වෙත සම්බන්ධ කර ඇත (PWM හැකියාව)
  servo2.attach(5); // Servo2 connected to digital pin 5 (PWM capable) | Servo2 ඩිජිටල් පින් 5 වෙත සම්බන්ධ කර ඇත (PWM හැකියාව)
  
  // Initialize servos to the middle position (90 degrees) | සර්වෝ මධ්‍ය ස්ථානයට (අංශක 90) ආරම්භ කරන්න
  servo1.write(currentPos1); // Set servo1 to initial position | servo1 ආරම්භක ස්ථානයට සකසන්න
  servo2.write(currentPos2); // Set servo2 to initial position | servo2 ආරම්භක ස්ථානයට සකසන්න
  
  delay(1000); // Give servos time to reach initial position | සර්වෝ ආරම්භක ස්ථානයට ළඟා වන තෙක් කාලය දෙන්න
}

void loop()
{
  // Read the value of joystick X-axis (between 0-1023) | ජොයිස්ටික් X-අක්ෂයේ අගය කියවන්න (0-1023 අතර)
  joyValX = analogRead(joyX); // Read raw analog value from joystick X-axis | ජොයිස්ටික් X-අක්ෂයෙන් කඩිසර ඇනලොග් අගය කියවන්න
  joyValX = map(joyValX, 0, 1023, 0, 180); // Map value from 0-1023 range to 0-180 degrees for servo | සර්වෝ සඳහා අගය 0-1023 පරාසයේ සිට 0-180 අංශක දක්වා සිතියම් ගත කරන්න
  // Note: 0 = leftmost joystick, 180 = rightmost joystick | සටහන: 0 = ජොයිස්ටික් වම්පස, 180 = ජොයිස්ටික් දකුණුපස

  // Read the value of joystick Y-axis (between 0-1023) | ජොයිස්ටික් Y-අක්ෂයේ අගය කියවන්න (0-1023 අතර)
  joyValY = analogRead(joyY); // Read raw analog value from joystick Y-axis | ජොයිස්ටික් Y-අක්ෂයෙන් කඩිසර ඇනලොග් අගය කියවන්න
  joyValY = map(joyValY, 0, 1023, 0, 180); // Map value from 0-1023 range to 0-180 degrees for servo | සර්වෝ සඳහා අගය 0-1023 පරාසයේ සිට 0-180 අංශක දක්වා සිතියම් ගත කරන්න
  // Note: 0 = lowest joystick position, 180 = highest joystick position | සටහන: 0 = ජොයිස්ටික් අවම ස්ථානය, 180 = ජොයිස්ටික් උපරිම ස්ථානය

  // Smooth movement for servo1 (X-axis control) | servo1 සඳහා සුමට චලනය (X-අක්ෂ පාලනය)
  if (joyValX > currentPos1) {
    // If target position is greater than current position, move up incrementally | ඉලක්කගත ස්ථානය වර්තමාන ස්ථානයට වඩා විශාල නම්, ක්‍රමයෙන් ඉහළට ගෙන යන්න
    for (int pos = currentPos1; pos <= joyValX; pos++) {
      servo1.write(pos); // Set servo to new position | සර්වෝව නව ස්ථානයට සකසන්න
      delay(15); // Delay for smooth movement (adjust this value for speed) | සුමට චලනය සඳහා ප්‍රමාදය (වේගය සඳහා මෙම අගය සකස් කරන්න)
    }
  } else {
    // If target position is less than current position, move down incrementally | ඉලක්කගත ස්ථානය වර්තමාන ස්ථානයට වඩා අඩු නම්, ක්‍රමයෙන් පහළට ගෙන යන්න
    for (int pos = currentPos1; pos >= joyValX; pos--) {
      servo1.write(pos); // Set servo to new position | සර්වෝව නව ස්ථානයට සකසන්න
      delay(15); // Delay for smooth movement (adjust this value for speed) | සුමට චලනය සඳහා ප්‍රමාදය (වේගය සඳහා මෙම අගය සකස් කරන්න)
    }
  }
  
  // Smooth movement for servo2 (Y-axis control) | servo2 සඳහා සුමට චලනය (Y-අක්ෂ පාලනය)
  if (joyValY > currentPos2) {
    // If target position is greater than current position, move up incrementally | ඉලක්කගත ස්ථානය වර්තමාන ස්ථානයට වඩා විශාල නම්, ක්‍රමයෙන් ඉහළට ගෙන යන්න
    for (int pos = currentPos2; pos <= joyValY; pos++) {
      servo2.write(pos); // Set servo to new position | සර්වෝව නව ස්ථානයට සකසන්න
      delay(15); // Delay for smooth movement (adjust this value for speed) | සුමට චලනය සඳහා ප්‍රමාදය (වේගය සඳහා මෙම අගය සකස් කරන්න)
    }
  } else {
    // If target position is less than current position, move down incrementally | ඉලක්කගත ස්ථානය වර්තමාන ස්ථානයට වඩා අඩු නම්, ක්‍රමයෙන් පහළට ගෙන යන්න
    for (int pos = currentPos2; pos >= joyValY; pos--) {
      servo2.write(pos); // Set servo to new position | සර්වෝව නව ස්ථානයට සකසන්න
      delay(15); // Delay for smooth movement (adjust this value for speed) | සුමට චලනය සඳහා ප්‍රමාදය (වේගය සඳහා මෙම අගය සකස් කරන්න)
    }
  }

  // Update current positions with new target positions | නව ඉලක්කගත ස්ථාන සමඟ වර්තමාන ස්ථාන යාවත්කාලීන කරන්න
  currentPos1 = joyValX; // Store current servo1 position for next comparison | ඊළඟ සංසන්දනය සඳහා වත්මන් servo1 ස්ථානය ගබඩා කරන්න
  currentPos2 = joyValY; // Store current servo2 position for next comparison | ඊළඟ සංසන්දනය සඳහා වත්මන් servo2 ස්ථානය ගබඩා කරන්න
  
  // Small delay before next reading to reduce processing load | ඊළඟ කියවීමට පෙර කුඩා ප්‍රමාදයක් (ප්‍රවර්ධන බර අඩු කිරීම සඳහා)
  delay(10);
}