// Include the Servo library for controlling servo motors | Servo මෝටර් පාලනය සඳහා Servo පුස්තකාලය ඇතුළත් කරන්න
#include <Servo.h>

Servo myServo;  // Create a Servo object to control the servo motor | Servo මෝටරය පාලනය කිරීම සඳහා Servo වස්තුවක් නිර්මාණය කරන්න
int rainSensorPin = A0;  // Define the analog pin for the raindrop sensor | වැසි බිංදු සංවේදකය සඳහා ඇනලොග් පින් අර්ථ දැක්වීම
int servoPin = 8;  // Define the digital pin for the servo motor | Servo මෝටරය සඳහා ඩිජිටල් පින් අර්ථ දැක්වීම
int threshold = 700;  // Set the threshold value to detect rain (adjust based on your sensor) | වැස්ස හඳුනා ගැනීම සඳහා අවම සීමා අගය සකසන්න (ඔබේ සංවේදකය මත පදනම්ව සකස් කරන්න)

void setup() {
  myServo.attach(servoPin);  // Attach the servo motor to the specified digital pin | Servo මෝටරය නියමිත ඩිජිටල් පින් වෙත අමුණන්න
  myServo.write(0);  // Initialize the servo position at 0 degrees (dry/closed position) | Servo එක ස්ථානය අංශක 0 (වියළි/වසා දමන ලද ස්ථානය) දී ආරම්භ කරන්න
  pinMode(rainSensorPin, INPUT);  // Set the raindrop sensor pin as input | වැසි බිංදු සංවේදක පින් ආදානයක් ලෙස සකසන්න
  Serial.begin(9600);  // Initialize serial communication at 9600 baud for debugging | දෝෂ නිරාකරණය සඳහා බවුඩ් අනුපාත 9600 දී සීරියල් සන්නිවේදනය ආරම්භ කරන්න
  Serial.println("Rain Sensor System Initialized"); // Startup message | ආරම්භක පණිවිඩය
  Serial.println("================================");
}

void loop() {
  // Read the analog value from the raindrop sensor (0-1023 range) | වැසි බිංදු සංවේදකයෙන් ඇනලොග් අගය කියවන්න (0-1023 පරාසය)
  int sensorValue = analogRead(rainSensorPin);
  // Higher value = drier surface, Lower value = wetter surface (rain detected)
  // ඉහළ අගය = වියළි මතුපිට, අඩු අගය = තෙත් මතුපිට (වැස්ස හඳුනාගෙන ඇත)
  
  Serial.print("Sensor Value: ");  // Print label for sensor value | සංවේදක අගය සඳහා ලේබලය මුද්‍රණය කරන්න
  Serial.println(sensorValue);  // Print the sensor value to Serial Monitor for debugging | දෝෂ නිරාකරණය සඳහා සංවේදක අගය සීරියල් මොනිටරයට මුද්‍රණය කරන්න

  int currentPos = myServo.read();  // Get the current position of the servo (0-90 degrees) | Servo එකේ වර්තමාන ස්ථානය ලබා ගන්න (0-90 අංශක)

  // Check if rain is detected by comparing sensor value with threshold | සංවේදක අගය අවම සීමාව සමඟ සංසන්දනය කිරීමෙන් වැස්ස හඳුනාගෙන ඇත්දැයි පරීක්ෂා කරන්න
  if (sensorValue < threshold) {  // If rain is detected (sensor value below threshold) | වැස්ස හඳුනාගෙන ඇත්නම් (සංවේදක අගය අවම සීමාවට වඩා අඩුය)
    Serial.println("Status: Rain Detected - Closing/Protecting");
    
    // Gradually move servo from current position to 90 degrees (rain protection position) | Servo එකේ වර්තමාන ස්ථානයේ සිට අංශක 90 දක්වා ක්‍රමයෙන් ගෙන යන්න (වැසි ආරක්ෂණ ස්ථානය)
    for (int pos = currentPos; pos <= 90; pos++) {
      myServo.write(pos); // Set servo to new position | Servo එකේ නව ස්ථානයට සකසන්න
      delay(15);  // Small delay for smooth, gradual movement | සුමට, ක්‍රමානුකූල චලනය සඳහා කුඩා ප්‍රමාදයක්
    }
    Serial.println("Servo moved to 90 degrees (Rain Protection Position)");
    
  } else {  // If no rain is detected (sensor value above threshold) | වැස්ස හඳුනාගෙන නැත්නම් (සංවේදක අගය අවම සීමාවට වඩා ඉහළය)
    Serial.println("Status: No Rain - Opening/Resetting");
    
    // Gradually move servo back to 0 degrees (normal/open position) | Servo එකේ අංශක 0 වෙත ක්‍රමයෙන් ආපසු ගෙන එන්න (සාමාන්‍ය/විවෘත ස්ථානය)
    for (int pos = currentPos; pos >= 0; pos--) {
      myServo.write(pos); // Set servo to new position | Servo එකේ නව ස්ථානයට සකසන්න
      delay(15);  // Small delay for smooth, gradual movement | සුමට, ක්‍රමානුකූල චලනය සඳහා කුඩා ප්‍රමාදයක්
    }
    Serial.println("Servo returned to 0 degrees (Normal Position)");
  }

  delay(1000);  // Wait for 1 second before reading the sensor again | සංවේදකය නැවත කියවීමට පෙර තත්පර 1ක් රැඳෙන්න
}