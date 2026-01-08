// Pin Definitions | පින් අර්ථ දැක්වීම්
const int led1 = 4;       // LED 1 connected to pin 4 | LED 1 පින් 4 වෙත සම්බන්ධ කර ඇත
const int led2 = 5;       // LED 2 connected to pin 5 | LED 2 පින් 5 වෙත සම්බන්ධ කර ඇත
const int led3 = 6;       // LED 3 connected to pin 6 | LED 3 පින් 6 වෙත සම්බන්ධ කර ඇත
const int led4 = 7;       // LED 4 connected to pin 7 | LED 4 පින් 7 වෙත සම්බන්ධ කර ඇත
const int buzzer = 12;    // Buzzer connected to pin 12 | බසරය පින් 12 වෙත සම්බන්ධ කර ඇත
const int ldrPin = A0;    // LDR Sensor connected to analog pin A0 | LDR Sensor එකේ ඇනලොග් පින් A0 වෙත සම්බන්ධ කර ඇත

// Threshold for LDR (adjust based on your laser intensity and room light) | LDR සඳහා අවම සීමාව (ඔබේ ලේසර් තීව්‍රතාව සහ කාමර ආලෝකය මත පදනම්ව සකසන්න)
int threshold = 500; // Default threshold value - adjust as needed | පෙරනිමි අවම සීමා අගය - අවශ්‍ය පරිදි සකසන්න

void setup() {
  // Initialize LED pins as output | LED පින් ප්‍රතිදාන ලෙස ආරම්භ කරන්න
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  // Initialize buzzer pin as output | බසර් පින් ප්‍රතිදාන ලෙස ආරම්භ කරන්න
  pinMode(buzzer, OUTPUT);

  // Initialize LDR pin as input | LDR පින් ආදානයක් ලෙස ආරම්භ කරන්න
  pinMode(ldrPin, INPUT);

  // Begin Serial communication for debugging | දෝෂ නිරාකරණය සඳහා සීරියල් සන්නිවේදනය ආරම්භ කරන්න
  Serial.begin(9600); // 9600 baud rate | බවුඩ් අනුපාත 9600
}

void loop() {
  // Read LDR value | LDR අගය කියවන්න
  int ldrValue = analogRead(ldrPin); // Reads value from 0 to 1023 | 0 සිට 1023 දක්වා අගය කියවයි
  
  // Print LDR value to the Serial Monitor | LDR අගය සීරියල් මොනිටරයට මුද්‍රණය කරන්න
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  // Print the current threshold value | වර්තමාන අවම සීමා අගය මුද්‍රණය කරන්න
  Serial.print("Threshold Value: ");
  Serial.println(threshold);

  // Check if LDR value is below the threshold (laser beam interrupted) | LDR අගය අවම සීමාවට වඩා අඩුදැයි පරීක්ෂා කරන්න (ලේසර් කදම්භය බාධා වී ඇත)
  if (ldrValue < threshold) {
    
    // Trigger the alarm | ඇඟවීම් පද්ධතිය ක්‍රියාත්මක කරන්න
    digitalWrite(buzzer, HIGH); // Turn on the buzzer (audible alarm) | බසරය ක්‍රියාත්මක කරන්න (ශ්‍රව්‍ය ඇඟවීම)

    // LED chasing pattern (one by one lighting) - Visual alarm effect | LED අනුගාමි රටාව (එකින් එක ආලෝකකරණය) - දෘශ්‍ය ඇඟවීම් ආකාරය
    digitalWrite(led1, HIGH); // Turn on LED 1 | LED 1 ක්‍රියාත්මක කරන්න
    delay(200);  // Wait for 200 milliseconds | මිලිතත්පර 200ක් රැඳෙන්න
    digitalWrite(led2, HIGH); // Turn on LED 2 | LED 2 ක්‍රියාත්මක කරන්න
    delay(200);
    digitalWrite(led3, HIGH); // Turn on LED 3 | LED 3 ක්‍රියාත්මක කරන්න
    delay(200);
    digitalWrite(led4, HIGH); // Turn on LED 4 | LED 4 ක්‍රියාත්මක කරන්න
    delay(200);
    
    // Turn LEDs off one by one (for a looping effect) | LED එකින් එක නිවා දමන්න (චක්‍රීය ආකාරයක් සඳහා)
    digitalWrite(led1, LOW); // Turn off LED 1 | LED 1 නිවා දමන්න
    delay(200);
    digitalWrite(led2, LOW); // Turn off LED 2 | LED 2 නිවා දමන්න
    delay(200);
    digitalWrite(led3, LOW); // Turn off LED 3 | LED 3 නිවා දමන්න
    delay(200);
    digitalWrite(led4, LOW); // Turn off LED 4 | LED 4 නිවා දමන්න
    delay(200);
    
  } else {
    // No interruption, system normal - turn everything off | කිසිදු බාධාවක් නැත, පද්ධතිය සාමාන්‍යයි - සියල්ල නිවා දමන්න
    digitalWrite(buzzer, LOW);  // Turn off the buzzer (silent) | බසරය නිවා දමන්න (නිශ්ශබ්ද)
    digitalWrite(led1, LOW);    // Turn off all LEDs | සියලුම LED නිවා දමන්න
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  
  delay(100);  // Short delay to avoid overloading the microcontroller and for stable readings | මයික්‍රොකොන්ට්‍රෝලරය අධිබර කිරීම වළක්වා ගැනීම සඳහා සහ ස්ථායී කියවීම් සඳහා කෙටි ප්‍රමාදයක්
}