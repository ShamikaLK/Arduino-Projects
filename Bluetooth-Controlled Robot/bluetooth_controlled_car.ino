
char t; // Variable to store serial input character | සීරියල් ආදාන අක්ෂරය ගබඩා කිරීමට විචල්යය
 
void setup() {
pinMode(13,OUTPUT);   //left motors forward | වම් මෝටර් ඉදිරියට
pinMode(12,OUTPUT);   //left motors reverse | වම් මෝටර් පසුපසට
pinMode(11,OUTPUT);   //right motors forward | දකුණු මෝටර් ඉදිරියට
pinMode(10,OUTPUT);   //right motors reverse | දකුණු මෝටර් පසුපසට
pinMode(9,OUTPUT);    //Led | LED
Serial.begin(9600);   // Initialize serial communication at 9600 baud rate | 9600 බෝඩ් අනුපාතයෙන් සීරියල් සන්නිවේදනය ආරම්භ කරන්න
 
}
 
void loop() {
if(Serial.available()){ // Check if data is available from serial port | සීරියල් වරායෙන් දත්ත ලබා ගත හැකිදැයි පරීක්ෂා කරන්න
  t = Serial.read();   // Read the incoming character | එන අක්ෂරය කියවන්න
  Serial.println(t);   // Echo the character back for debugging | දෝෂ නිරාකරණය සඳහා අක්ෂරය ප්‍රතිප්‍රකාශනය කරන්න
}
 
if(t == 'F'){            //move forward (all motors rotate in forward direction) | ඉදිරියට ගමන් කරන්න (සියලුම මෝටර් ඉදිරි දිශාවට භ්‍රමණය වේ)
  digitalWrite(13,HIGH); // Left motor forward | වම් මෝටර් එක ඉදිරියට
  digitalWrite(11,HIGH); // Right motor forward | දකුණු මෝටර් එක ඉදිරියට
}
 
else if(t == 'B'){      //move reverse (all motors rotate in reverse direction) | පසුපසට ගමන් කරන්න (සියලුම මෝටර් පසුපස දිශාවට භ්‍රමණය වේ)
  digitalWrite(12,HIGH); // Left motor reverse | වම් මෝටර් එක පසුපසට
  digitalWrite(10,HIGH); // Right motor reverse | දකුණු මෝටර් එක පසුපසට
}
  
else if(t == 'L'){      //turn left (left side motors rotate in reverse, right side motors rotate forward) | වමට හැරෙන්න (වම් පස මෝටර් පසුපසට, දකුණු පස මෝටර් ඉදිරියට භ්‍රමණය වේ)
  digitalWrite(12,HIGH); // Left motor reverse | වම් මෝටර් එක පසුපසට
  digitalWrite(11,HIGH); // Right motor forward | දකුණු මෝටර් එක ඉදිරියට
}
 
else if(t == 'R'){      //turn right (right side motors rotate in reverse, left side motors rotate forward) | දකුණට හැරෙන්න (දකුණු පස මෝටර් පසුපසට, වම් පස මෝටර් ඉදිරියට භ්‍රමණය වේ)
  digitalWrite(13,HIGH); // Left motor forward | වම් මෝටර් එක ඉදිරියට
  digitalWrite(10,HIGH); // Right motor reverse | දකුණු මෝටර් එක පසුපසට
}

else if(t == 'W'){    //turn LED on | LED එක ඇන දමන්න
  digitalWrite(9,HIGH); // LED on | LED ඇන දමන්න
}
else if(t == 'w'){    //turn LED off | LED එක කිල්ලන්න
  digitalWrite(9,LOW);  // LED off | LED කිල්ලන්න
}
 
else if(t == 'S'){      //STOP (all motors stop) | නවත්වන්න (සියලුම මෝටර් නතර කරන්න)
  digitalWrite(13,LOW);  // Left motor forward off | වම් මෝටර් ඉදිරිය නතර කරන්න
  digitalWrite(12,LOW);  // Left motor reverse off | වම් මෝටර් පසුපස නතර කරන්න
  digitalWrite(11,LOW);  // Right motor forward off | දකුණු මෝටර් ඉදිරිය නතර කරන්න
  digitalWrite(10,LOW);  // Right motor reverse off | දකුණු මෝටර් පසුපස නතර කරන්න
}

// Note: The code currently doesn't turn off motors when switching between F/B/L/R commands
// This should be fixed by adding LOW writes for unused motor pins in each condition
// සටහන: F/B/L/R විධාන අතර මාරු වන විට මෝටර් නතර කරන ලෙස දැනට කේතය රචනා කර නැත
// එක් එක් කොන්දේසිය සඳහා භාවිතා නොකරන මෝටර් පින් සඳහා LOW ලිවීම් එකතු කිරීමෙන් මෙය නිරාකරණය කළ යුතුය
}