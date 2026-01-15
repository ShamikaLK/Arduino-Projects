// Define pins for ultrasonic sensor | ultrasonic සෙන්සරය සඳහා පින් අර්ථ දක්වන්න
const int trigPin = 10; // Trigger pin for ultrasonic sensor | ultrasonic සෙන්සරයේ ට්රිගර් පින් එක
const int echoPin = 9; // Echo pin for ultrasonic sensor | ultrasonic සෙන්සරයේ එකෝ පින් එක

// Define pins for buzzer and LEDs | බසර් සහ LED සඳහා පින් අර්ථ දක්වන්න
const int buzzerPin = 7; // Pin connected to the buzzer | බසර් එකට සම්බන්ධ කරන ලද පින් එක
const int led5 = 5; // Pin for LED 5 | LED 5 සඳහා පින් එක
const int led4 = 4; // Pin for LED 4 | LED 4 සඳහා පින් එක
const int led3 = 3; // Pin for LED 3 | LED 3 සඳහා පින් එක
const int led2 = 2; // Pin for LED 2 | LED 2 සඳහා පින් එක

long duration; // Variable to store echo pulse duration | Echo pulse එක ආපු කාලය store කරන්න variable එකක්
int distance; // Variable to store calculated distance | ගණනය කළ දුර store කරන්න variable එකක්
int buzzerFrequency = 500; // Lower pitch frequency (500 Hz) | අඩු පිච් සංඛ්යාතය (500 Hz)

void setup() {
  // Set pin modes | පින් මෝඩ් සකසන්න
  pinMode(trigPin, OUTPUT); // Set trigPin as output | trigPin OUTPUT ලෙස සකසන්න
  pinMode(echoPin, INPUT); // Set echoPin as input | echoPin INPUT ලෙස සකසන්න
  
  pinMode(buzzerPin, OUTPUT); // Set buzzerPin as output | buzzerPin OUTPUT ලෙස සකසන්න
  pinMode(led5, OUTPUT); // Set led5 as output | led5 OUTPUT ලෙස සකසන්න
  pinMode(led4, OUTPUT); // Set led4 as output | led4 OUTPUT ලෙස සකසන්න
  pinMode(led3, OUTPUT); // Set led3 as output | led3 OUTPUT ලෙස සකසන්න
  pinMode(led2, OUTPUT); // Set led2 as output | led2 OUTPUT ලෙස සකසන්න
  
  Serial.begin(9600); // Start serial communication for debugging | දෝෂ නිරාකරණය සඳහා සීරියල් සන්නිවේදනය අරඹන්න
}

void loop() {
  // Ultrasonic sensor measurement | ultrasonic සෙන්සර මැනීම
  digitalWrite(trigPin, LOW); // Set trigPin low to send a clean pulse | පිරිසිදු පල්ස් එකක් යැවීමට trigPin LOW කරන්න
  delayMicroseconds(2); // Wait for 2 microseconds | මයික්රොසෙකන්ඩ් 2ක් බලාගන්න
  
  digitalWrite(trigPin, HIGH); // Send 10 microsecond pulse | මයික්රොසෙකන්ඩ් 10ක පල්ස් එකක් යවන්න
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); // Stop the pulse | පල්ස් එක නවත්වන්න
  
  duration = pulseIn(echoPin, HIGH); // Read the echo pulse duration | Echo pulse එකේ කාලය කියවන්න
  
  // Calculate distance in cm | දුර සෙ.මී. වලින් ගණනය කරන්න
  distance = duration * 0.034 / 2; // Formula: distance = (duration * speed of sound) / 2 | සූත්රය: දුර = (කාලය * ශබ්දයේ වේගය) / 2
  
  Serial.print("Distance: "); // Print distance label to serial monitor | දුර ලේබල් එක සීරියල් මොනිටරයට මුද්රණය කරන්න
  Serial.println(distance);  // Print distance value for debugging | දෝෂ නිරාකරණය සඳහා දුර අගය මුද්රණය කරන්න
  
  if (distance <= 15 && distance > 12) {
    // Distance 15cm to 12cm -> LED 5 and buzzer blink with 2 seconds on/off | දුර සෙ.මී. 15 සිට 12 -> LED 5 සහ බසර් එක තත්පර 2ක් on/off වේ
    blinkLedBuzzer(led5, 2000, 2000);
  } 
  else if (distance <= 12 && distance > 9) {
    // Distance 12cm to 9cm -> LED 5 on, LED 4 and buzzer blink with 1.5 seconds on/off | දුර සෙ.මී. 12 සිට 9 -> LED 5 on, LED 4 සහ බසර් එක තත්පර 1.5ක් on/off වේ
    digitalWrite(led5, HIGH); // Turn on LED 5 | LED 5 එක ඇන දමන්න
    blinkLedBuzzer(led4, 1500, 1500);
  } 
  else if (distance <= 9 && distance > 6) {
    // Distance 9cm to 6cm -> LED 5 and LED 4 on, LED 3 and buzzer blink with 1 second on/off | දුර සෙ.මී. 9 සිට 6 -> LED 5 සහ LED 4 on, LED 3 සහ බසර් එක තත්පර 1ක් on/off වේ
    digitalWrite(led5, HIGH); // Turn on LED 5 | LED 5 එක ඇන දමන්න
    digitalWrite(led4, HIGH); // Turn on LED 4 | LED 4 එක ඇන දමන්න
    blinkLedBuzzer(led3, 1000, 1000);
  } 
  else if (distance <= 6) {
    // Distance <= 6cm -> LED 5, LED 4, and LED 3 on, LED 2 and buzzer blink with 0.5 seconds on/off | දුර <= සෙ.මී. 6 -> LED 5, LED 4, සහ LED 3 on, LED 2 සහ බසර් එක තත්පර 0.5ක් on/off වේ
    digitalWrite(led5, HIGH); // Turn on LED 5 | LED 5 එක ඇන දමන්න
    digitalWrite(led4, HIGH); // Turn on LED 4 | LED 4 එක ඇන දමන්න
    digitalWrite(led3, HIGH); // Turn on LED 3 | LED 3 එක ඇන දමන්න
    blinkLedBuzzer(led2, 500, 500);
  } 
  else {
    // No wall nearby, turn off all LEDs and buzzer | අසල කිසිදු බිත්තියක් නැත, LED සියල්ල සහ බසර් එක අක්රීය කරන්න
    digitalWrite(led5, LOW); // Turn off LED 5 | LED 5 එක කිල්ලන්න
    digitalWrite(led4, LOW); // Turn off LED 4 | LED 4 එක කිල්ලන්න
    digitalWrite(led3, LOW); // Turn off LED 3 | LED 3 එක කිල්ලන්න
    digitalWrite(led2, LOW); // Turn off LED 2 | LED 2 එක කිල්ලන්න
    noTone(buzzerPin);  // Stop buzzer sound | බසර් ශබ්දය නතර කරන්න
  }
  
  delay(100); // Small delay to avoid fast updates | වේගවත් යාවත්කාලීනවීම වැළැක්වීම සඳහා කුඩා ප්රමාදයක්
}

// Function to blink LED and control low-pitch buzzer | LED එකක් මෙරවීම සහ අඩු පිච් බසර් එක පාලනය කිරීම සඳහා ශ්රිතය
void blinkLedBuzzer(int ledPin, int onTime, int offTime) {
  digitalWrite(ledPin, HIGH); // Turn on the specified LED | නියමිත LED එක ඇන දමන්න
  tone(buzzerPin, buzzerFrequency);  // Generate low pitch sound | අඩු පිච් ශබ්දය ජනනය කරන්න
  delay(onTime); // Keep LED and buzzer on for onTime milliseconds | LED සහ බසර් එක onTime මිලි තත්පර සඳහා on තබන්න
  
  digitalWrite(ledPin, LOW); // Turn off the specified LED | නියමිත LED එක කිල්ලන්න
  noTone(buzzerPin);  // Turn off buzzer sound | බසර් ශබ්දය නතර කරන්න
  delay(offTime); // Keep LED and buzzer off for offTime milliseconds | LED සහ බසර් එක offTime මිලි තත්පර සඳහා off තබන්න
}