#include <Servo.h>  // Include Servo library | Servo motor control කරන්න Servo library එක include කරනවා

Servo servo1;  // Create a Servo object | Servo motor එක control කරන්න Servo object එකක් හදනවා

const int trigPin = 8;  
const int echoPin = 9;  // Ultrasonic sensor pins | Ultrasonic sensor එකේ Trig සහ Echo pins define කරනවා

long duration;  // Variable to store echo pulse duration | Echo pulse එක ආපු කාලය store කරන්න variable එකක්
int distance = 0;  // Variable to store distance | Distance (දුර) store කරන්න variable එකක්
int potPin = A0;  // Soil moisture sensor connected to analog pin A0 | Soil moisture sensor එක A0 pin එකට connect කරලා තියෙනවා
int soil = 0;  // Variable to read soil sensor value | Soil sensor value store කරන්න variable එකක්
int fsoil;  // Final soil moisture value | Average කරපු soil moisture value එක
int maxDryValue = 10; // Threshold to decide dry or wet waste | මේ value එකට වඩා moisture වැඩි නම් waste = wet
int Ultra_Distance = 15;   // Distance threshold for ultrasonic sensor (cm) | Ultrasonic sensor එක detect කරන maximum distance (cm)

void setup() {
  Serial.begin(9600);  // Start serial communication | Serial Monitor එක start කරනවා
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);  // Set ultrasonic sensor pin modes | Trig pin OUTPUT, Echo pin INPUT ලෙස set කරනවා
  servo1.attach(7);  // Attach servo motor to pin 7 | Servo motor එක pin 7 ට attach කරනවා
  Serial.println("Soil Sensor     Ultrasonic          Servo");  // Print header text | Serial Monitor එකට header එක print කරනවා
}

void loop() {
  int soil = 0;  // Reset soil value | Soil value එක reset කරනවා

  for(int i = 0; i < 2; i++) { // Trigger ultrasonic pulse | Ultrasonic sensor එක trigger කරනවා
    digitalWrite(trigPin, LOW);
    delayMicroseconds(7);
    
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    
    digitalWrite(trigPin, LOW);
    delayMicroseconds(10);
    duration = pulseIn(echoPin, HIGH);  // Read echo duration | Echo pin එක HIGH වෙලා තිබ්බ කාලය read කරනවා

    distance = duration * 0.034 / 2 + distance;  // Convert duration to distance (cm) | Duration එක distance (cm) බවට convert කරනවා

    delay(10);
  }

  distance = distance / 2;  // Take average distance | Distance average එක ගන්නවා

  if (distance < Ultra_Distance && distance > 1) { // Object detected within range | Object එක sensor range එක ඇතුලේ detect වුනොත්
    delay(1000);
    
    for(int i = 0; i < 3; i++) {
      soil = analogRead(potPin);  // Read soil moisture sensor | Soil moisture sensor value read කරනවා
      soil = constrain(soil, 485, 1023);  // Limit sensor range | Sensor value එක limit කරනවා
      fsoil = (map(soil, 485, 1023, 100, 0)) + fsoil;  // Convert sensor value to percentage | Sensor value එක percentage එකක් බවට convert කරනවා
      delay(75);
    }

    fsoil = fsoil / 3;  // Average soil moisture value | Soil moisture average value එක ගන්නවා
    Serial.print("Humidity: ");
    Serial.print(fsoil);
    Serial.print("%");
    Serial.print("    Distance: ");
    Serial.print(distance);
    Serial.print(" cm");

    if(fsoil > maxDryValue) { // Wet waste detected | Waste එක wet නම්
      delay(1000);
      Serial.println("     ==>WET Waste ");
      servo1.write(10);  // Move servo to wet position | Servo motor එක wet position එකට යවනවා
      delay(3000);
    } else { // Dry waste detected | Waste එක dry නම්
      delay(1000);
      Serial.println("     ==>Dry Waste ");
      servo1.write(170);  // Move servo to dry position | Servo motor එක dry position එකට යවනවා
      delay(3000);
    }
    servo1.write(90);  // Reset servo to middle position | Servo motor එක middle position එකට reset කරනවා
  }

  distance = 0;  
  fsoil = 0;  // Reset values | Distance සහ soil values reset කරනවා

  delay(1000);
}
