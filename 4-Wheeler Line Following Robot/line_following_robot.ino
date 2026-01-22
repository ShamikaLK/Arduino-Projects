#define enA 10 //Enable1 L298 Pin enA | L298 එන්ජින් 1 පින් enA
#define in1 9  //Motor1 L298 Pin in1 | මෝටර් 1 L298 පින් in1
#define in2 8  //Motor1 L298 Pin in2 | මෝටර් 1 L298 පින් in2
#define in3 7  //Motor2 L298 Pin in3 | මෝටර් 2 L298 පින් in3
#define in4 6  //Motor2 L298 Pin in4 | මෝටර් 2 L298 පින් in4
#define enB 5  //Enable2 L298 Pin enB | L298 එන්ජින් 2 පින් enB

// Make the distance between the two IR sensors slightly larger than the width of the black line you are getting.
// IR sensor දෙක අතර පරතරය ඔබ ලබා ගන්නා කලුපාට මාර්ගයේ පලලට වඩා ටිකක් වැඩියෙන් ලබා ගන්න.
#define R_S A0 //Right IR sensor | දකුණු IR සංවේදකය
#define L_S A1 //Left IR sensor | වම් IR සංවේදකය

void setup() { // put your setup code here, to run once | ඔබේ සැකසුම් කේතය මෙහි තබන්න, එක් වරක් ධාවනය කිරීමට
    pinMode(R_S, INPUT);  // declare IR sensor as input | IR සංවේදකය input ලෙස ප්‍රකාශ කරන්න
    pinMode(L_S, INPUT);  // declare IR sensor as input | IR සංවේදකය input ලෙස ප්‍රකාශ කරන්න

    pinMode(enA, OUTPUT); // declare as output for L298 Pin enA | L298 පින් enA සඳහා output ලෙස ප්‍රකාශ කරන්න
    pinMode(in1, OUTPUT); // declare as output for L298 Pin in1 | L298 පින් in1 සඳහා output ලෙස ප්‍රකාශ කරන්න
    pinMode(in2, OUTPUT); // declare as output for L298 Pin in2 | L298 පින් in2 සඳහා output ලෙස ප්‍රකාශ කරන්න
    pinMode(in3, OUTPUT); // declare as output for L298 Pin in3 | L298 පින් in3 සඳහා output ලෙස ප්‍රකාශ කරන්න
    pinMode(in4, OUTPUT); // declare as output for L298 Pin in4 | L298 පින් in4 සඳහා output ලෙස ප්‍රකාශ කරන්න
    pinMode(enB, OUTPUT); // declare as output for L298 Pin enB | L298 පින් enB සඳහා output ලෙස ප්‍රකාශ කරන්න

    analogWrite(enA, 150); // Write The Duty Cycle 0 to 255 Enable Pin A for Motor1 Speed | මෝටර් 1 වේගය සඳහා ඩියුටි සයිකල් 0 සිට 255 ලියන්න Enable පින් A
    analogWrite(enB, 150); // Write The Duty Cycle 0 to 255 Enable Pin B for Motor2 Speed | මෝටර් 2 වේගය සඳහා ඩියුටි සයිකල් 0 සිට 255 ලියන්න Enable පින් B
    delay(1000); // Wait for 1 second | තත්පර 1ක් බලාගන්න
}

void loop() {
    // Read IR sensor values and decide movement based on line detection | IR සංවේදක අගයන් කියවා රේඛා හඳුනාගැනීම මත චලනය තීරණය කරන්න
    if ((digitalRead(R_S) == 0) && (digitalRead(L_S) == 0)) { // Both sensors on white line | සංවේදක දෙකම සුදු රේඛාව මත
        forword(); // Move forward | ඉදිරියට ගමන් කරන්න
    }

    if ((digitalRead(R_S) == 1) && (digitalRead(L_S) == 0)) { // Right sensor on black line, left on white | දකුණු සංවේදකය කළු රේඛාව මත, වම් සංවේදකය සුදු රේඛාව මත
        turnRight(); // Turn right | දකුණට හැරෙන්න
    }

    if ((digitalRead(R_S) == 0) && (digitalRead(L_S) == 1)) { // Right sensor on white line, left on black | දකුණු සංවේදකය සුදු රේඛාව මත, වම් සංවේදකය කළු රේඛාව මත
        turnLeft(); // Turn left | වමට හැරෙන්න
    }

    if ((digitalRead(R_S) == 1) && (digitalRead(L_S) == 1)) { // Both sensors on black line | සංවේදක දෙකම කළු රේඛාව මත
        Stop(); // Stop | නවත්වන්න
    }
}

void forword() { // Move forward function | ඉදිරියට ගමන් කිරීමේ ශ්‍රිතය
    // Right motor forward | දකුණු මෝටර් එක ඉදිරියට
    digitalWrite(in1, HIGH); // Right Motor forward Pin | දකුණු මෝටර් ඉදිරියට පින්
    digitalWrite(in2, LOW);  // Right Motor backward Pin | දකුණු මෝටර් පසුපසට පින්

    // Left motor forward | වම් මෝටර් එක ඉදිරියට
    digitalWrite(in3, LOW);  // Left Motor backward Pin | වම් මෝටර් පසුපසට පින්
    digitalWrite(in4, HIGH); // Left Motor forward Pin | වම් මෝටර් ඉදිරියට පින්
}

void turnRight() { // Turn right function | දකුණට හැරවීමේ ශ්‍රිතය
    // Right motor backward (to turn right) | දකුණු මෝටර් එක පසුපසට (දකුණට හැරවීම සඳහා)
    digitalWrite(in1, LOW);  // Right Motor forward Pin | දකුණු මෝටර් ඉදිරියට පින්
    digitalWrite(in2, HIGH); // Right Motor backward Pin | දකුණු මෝටර් පසුපසට පින්

    // Left motor forward | වම් මෝටර් එක ඉදිරියට
    digitalWrite(in3, LOW);  // Left Motor backward Pin | වම් මෝටර් පසුපසට පින්
    digitalWrite(in4, HIGH); // Left Motor forward Pin | වම් මෝටර් ඉදිරියට පින්
}

void turnLeft() { // Turn left function | වමට හැරවීමේ ශ්‍රිතය
    // Right motor forward | දකුණු මෝටර් එක ඉදිරියට
    digitalWrite(in1, HIGH); // Right Motor forward Pin | දකුණු මෝටර් ඉදිරියට පින්
    digitalWrite(in2, LOW);  // Right Motor backward Pin | දකුණු මෝටර් පසුපසට පින්

    // Left motor backward (to turn left) | වම් මෝටර් එක පසුපසට (වමට හැරවීම සඳහා)
    digitalWrite(in3, HIGH); // Left Motor backward Pin | වම් මෝටර් පසුපසට පින්
    digitalWrite(in4, LOW);  // Left Motor forward Pin | වම් මෝටර් ඉදිරියට පින්
}

void Stop() { // Stop function | නවත්වන ශ්‍රිතය
    // Stop both motors | මෝටර් දෙකම නවත්වන්න
    digitalWrite(in1, LOW); // Right Motor forward Pin | දකුණු මෝටර් ඉදිරියට පින්
    digitalWrite(in2, LOW); // Right Motor backward Pin | දකුණු මෝටර් පසුපසට පින්
    digitalWrite(in3, LOW); // Left Motor backward Pin | වම් මෝටර් පසුපසට පින්
    digitalWrite(in4, LOW); // Left Motor forward Pin | වම් මෝටර් ඉදිරියට පින්
}