#include <AFMotor.h>
#include <NewPing.h>
#include <Servo.h>

// Pin definitions and constants | පින් අර්ථ දැක්වීම් සහ නියතයන්
#define TRIG_PIN A1  
#define ECHO_PIN A2
#define MAX_DISTANCE 200
#define MAX_SPEED 150
#define MAX_SPEED_OFFSET 20

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE); // Ultrasonic sensor object

AF_DCMotor motor1(1, MOTOR12_1KHZ); // Motor 1 connected to M1 | M1 වෙත සම්බන්ධ කරන ලද Motor 1
AF_DCMotor motor2(2, MOTOR12_1KHZ); // Motor 2 connected to M2 | M2 වෙත සම්බන්ධ කරන ලද Motor 2
Servo myservo;   // Servo motor object | සර්වෝ මෝටර් වස්තුව

// Global variables | ගෝලීය විචල්යයන්
boolean goesForward = false; // Direction flag | දිශාව පෙන්වන flag
int distance = 100; // Current distance reading | වර්තමාන දුර කියවීම
int speedSet = 0; // Current speed setting | වර්තමාන වේග සැකසුම

void setup() {
  // Initialize Serial Monitor for debugging | දෝෂ නිරාකරණය සඳහා Serial Monitor ආරම්භ කරන්න
  Serial.begin(9600);
  myservo.attach(10);
  myservo.write(115);
  delay(2000);
  
  // Initial distance measurement and Serial output | ආරම්භක දුර මැනීම සහ Serial output
  distance = readPing();
  Serial.print("Initial distance: ");
  Serial.println(distance);
  delay(100);
}

void loop() {
  int distanceR = 0; // Distance to the right | දකුණු පස දුර
  int distanceL =  0; // Distance to the left | වම් පස දුර
  delay(40);
  
  Serial.print("Current distance: ");
  Serial.println(distance);

  // Obstacle detection and avoidance logic | බාධක හඳුනාගැනීම සහ වැළකීමේ තර්කය
  if(distance <= 25) {
    Serial.println("Obstacle detected, stopping and reversing...");
    moveStop();
    delay(100);
    moveBackward();
    delay(200);
    moveStop();
    delay(200);
    
    // Look right and measure distance | දකුණු පස බලා දුර මැනීම
    distanceR = lookRight();
    Serial.print("Right distance: ");
    Serial.println(distanceR);
    delay(200);
    
    // Look left and measure distance | වම් පස බලා දුර මැනීම
    distanceL = lookLeft();
    Serial.print("Left distance: ");
    Serial.println(distanceL);
    delay(200);

    // Decide direction based on which side has more space | වැඩි ඉඩක් ඇති පැත්ත මත පදනම්ව දිශාව තීරණය කරන්න
    if(distanceR >= distanceL) {
      Serial.println("Turning right...");
      turnRight();
      moveStop();
    } else {
      Serial.println("Turning left...");
      turnLeft();
      moveStop();
    }
  } else {
    // No obstacle detected, continue forward | බාධක හඳුනාගෙන නැත, ඉදිරියට ගමන් කරන්න
    Serial.println("Moving forward...");
    moveForward();
  }

  distance = readPing(); // Update distance reading | දුර කියවීම යාවත්කාලීන කරන්න
}

// Function to look right and measure distance | දකුණු පස බලා දුර මැනීමේ ශ්‍රිතය
int lookRight() {
  myservo.write(50); // Rotate servo to 50 degrees (right) | servo 50 අංශක වලට භ්‍රමණය කරන්න (දකුණ)
  delay(500);
  int distance = readPing();
  delay(100);
  myservo.write(115); // Return servo to center position | servo මධ්‍ය ස්ථානයට ආපසු ගෙන එන්න
  return distance;
}

// Function to look left and measure distance | වම් පස බලා දුර මැනීමේ ශ්‍රිතය
int lookLeft() {
  myservo.write(170); // Rotate servo to 170 degrees (left) | servo 170 අංශක වලට භ්‍රමණය කරන්න (වම)
  delay(500);
  int distance = readPing();
  delay(100);
  myservo.write(115); // Return servo to center position | servo මධ්‍ය ස්ථානයට ආපසු ගෙන එන්න
  return distance;
}

// Function to read distance from ultrasonic sensor | ultrasonic sensor දුර කියවීමේ ශ්‍රිතය
int readPing() { 
  delay(70);
  int cm = sonar.ping_cm();
  if(cm == 0) {
    cm = 250; // If no echo received, set to max distance | ප්‍රතිචාරයක් ලැබෙන්නේ නැතිනම්, උපරිම දුරට සකසන්න
  }
  return cm;
}

// Function to stop both motors | motors දෙකම නතර කිරීමේ ශ්‍රිතය
void moveStop() {
  motor1.run(RELEASE); 
  motor2.run(RELEASE);
} 

// Function to move the robot forward | robot ව ඉදිරියට ගෙනයාමේ ශ්‍රිතය
void moveForward() {
  if(!goesForward) {
    goesForward = true;
    motor1.run(FORWARD);      
    motor2.run(FORWARD);  
    for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) {
      motor1.setSpeed(speedSet);
      motor2.setSpeed(speedSet);
      delay(5);
    }
  }
}

// Function to move the robot backward | robot ව පසුපසට ගෙනයාමේ ශ්‍රිතය
void moveBackward() {
  goesForward = false;
  motor1.run(BACKWARD);      
  motor2.run(BACKWARD);
  for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) {
    motor1.setSpeed(speedSet);
    motor2.setSpeed(speedSet);
    delay(5);
  }
}  

// Function to turn the robot right | robot ව දකුණට හැරවීමේ ශ්‍රිතය
void turnRight() {
  motor1.run(FORWARD);
  motor2.run(BACKWARD);    
  delay(450);
  motor1.run(FORWARD);      
  motor2.run(FORWARD);    
} 

// Function to turn the robot left | robot ව වමට හැරවීමේ ශ්‍රිතය
void turnLeft() {
  motor1.run(BACKWARD);     
  motor2.run(FORWARD); 
  delay(450);
  motor1.run(FORWARD);     
  motor2.run(FORWARD);
}
