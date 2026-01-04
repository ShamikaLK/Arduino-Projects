// LED pins definition | LED පින් අර්ථ දැක්වීම
int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int LED4 = 5;
int LED5 = 6;
int LED6 = 7;
int LED7 = 8;
int LED8 = 9;
int LED9 = 10;
int LED10 = 11;
int LED11 = 12;
int LED12 = 13;
int t=20; // Short delay time for chasing effect | පසුපස්සේ යන ආකාරය සඳහා කෙටි ප්‍රමාද කාලය
int y=100; // Longer delay time for closing effect | වසා දැමීමේ ආකාරය සඳහා දිගු ප්‍රමාද කාලය



void setup() {
   // Set all LED pins as OUTPUT | සියලු LED පින් OUTPUT ලෙස සකසන්න
   pinMode(LED1, OUTPUT);
   pinMode(LED2, OUTPUT);
   pinMode(LED3, OUTPUT); 
   pinMode(LED4, OUTPUT);
   pinMode(LED5, OUTPUT);
   pinMode(LED6, OUTPUT);
   pinMode(LED7, OUTPUT);
   pinMode(LED8, OUTPUT);
   pinMode(LED9, OUTPUT);
   pinMode(LED10, OUTPUT);
   pinMode(LED11, OUTPUT);
   pinMode(LED12, OUTPUT);
    
}


void loop() {
// First chasing pattern: Turn on LEDs one by one from right to left (LED12 to LED1) | පළමු පසුපස්සේ යන ආකාරය: LED එකින් එක දකුණේ සිට වමට (LED12 සිට LED1 දක්වා) අලුත් කරන්න                    
  digitalWrite(LED12, HIGH);    
  delay(t);                 
  digitalWrite(LED11, HIGH);    
  delay(t);                  
  digitalWrite(LED10, HIGH); 
  delay(t);                 
  digitalWrite(LED9, HIGH);  
  delay(t);                  
  digitalWrite(LED8, HIGH);    
  delay(t);                 
  digitalWrite(LED7, HIGH);    
  delay(t);                 
  digitalWrite(LED6, HIGH);  
  delay(t);               
  digitalWrite(LED5, HIGH); 
  delay(t);  
  digitalWrite(LED4, HIGH);    
  delay(t);
  digitalWrite(LED3, HIGH);    
  delay(t);
  digitalWrite(LED2, HIGH);    
  delay(t);
  digitalWrite(LED1, HIGH);    
  delay(t);
   
// Turn off LEDs one by one from right to left (LED12 to LED1) | LED එකින් එක දකුණේ සිට වමට (LED12 සිට LED1 දක්වා) නිවා දමන්න                    
  digitalWrite(LED12, LOW);    
  delay(t);                
  digitalWrite(LED11, LOW);    
  delay(t);                  
  digitalWrite(LED10, LOW);   
  delay(t);               
  digitalWrite(LED9, LOW);     
  delay(t);               
  digitalWrite(LED8, LOW);  
  delay(t);                 
  digitalWrite(LED7, LOW);  
  delay(t);                  
  digitalWrite(LED6, LOW);     
  delay(t);                  
  digitalWrite(LED5, LOW);   
  delay(t); 
  digitalWrite(LED4, LOW);    
  delay(t);
  digitalWrite(LED3, LOW);    
  delay(t);
  digitalWrite(LED2, LOW);    
  delay(t);
  digitalWrite(LED1, LOW);    
  delay(t);

// Second chasing pattern: Turn on LEDs one by one from left to right (LED1 to LED12) | දෙවන පසුපස්සේ යන ආකාරය: LED එකින් එක වමේ සිට දකුණට (LED1 සිට LED12 දක්වා) අලුත් කරන්න
  digitalWrite(LED1, HIGH);    
  delay(t);
  digitalWrite(LED2, HIGH);    
  delay(t);
  digitalWrite(LED3, HIGH);    
  delay(t);
  digitalWrite(LED4, HIGH);    
  delay(t); 
  digitalWrite(LED5, HIGH); 
  delay(t);
  digitalWrite(LED6, HIGH);  
  delay(t);
  digitalWrite(LED7, HIGH);  
  delay(t);
  digitalWrite(LED8, HIGH);  
  delay(t);
  digitalWrite(LED9, HIGH);  
  delay(t);
  digitalWrite(LED10, HIGH);  
  delay(t);
  digitalWrite(LED11, HIGH);  
  delay(t);
  digitalWrite(LED12, HIGH);  
  delay(t);

// Turn off LEDs one by one from left to right (LED1 to LED12) | LED එකින් එක වමේ සිට දකුණට (LED1 සිට LED12 දක්වා) නිවා දමන්න
  digitalWrite(LED1, LOW);    
  delay(t);
  digitalWrite(LED2, LOW);    
  delay(t);
  digitalWrite(LED3, LOW);    
  delay(t);
  digitalWrite(LED4, LOW);    
  delay(t);
  digitalWrite(LED5, LOW);    
  delay(t);
  digitalWrite(LED6, LOW);    
  delay(t);
  digitalWrite(LED7, LOW);    
  delay(t);
  digitalWrite(LED8, LOW);    
  delay(t);
  digitalWrite(LED9, LOW);    
  delay(t);
  digitalWrite(LED10, LOW);    
  delay(t);
  digitalWrite(LED11, LOW);    
  delay(t);
  digitalWrite(LED12, LOW);    
  delay(t);

// Repeat first chasing pattern (right to left) | පළමු පසුපස්සේ යන ආකාරය නැවත කරන්න (දකුණේ සිට වමට)
  digitalWrite(LED12, HIGH);    
  delay(t);                 
  digitalWrite(LED11, HIGH);    
  delay(t);                  
  digitalWrite(LED10, HIGH); 
  delay(t);                 
  digitalWrite(LED9, HIGH);  
  delay(t);                  
  digitalWrite(LED8, HIGH);    
  delay(t);                 
  digitalWrite(LED7, HIGH);    
  delay(t);                 
  digitalWrite(LED6, HIGH);  
  delay(t);               
  digitalWrite(LED5, HIGH); 
  delay(t);  
  digitalWrite(LED4, HIGH);    
  delay(t);
  digitalWrite(LED3, HIGH);    
  delay(t);
  digitalWrite(LED2, HIGH);    
  delay(t);
  digitalWrite(LED1, HIGH);    
  delay(t);
   
                    
  digitalWrite(LED12, LOW);    
  delay(t);                
  digitalWrite(LED11, LOW);    
  delay(t);                  
  digitalWrite(LED10, LOW);   
  delay(t);               
  digitalWrite(LED9, LOW);     
  delay(t);               
  digitalWrite(LED8, LOW);  
  delay(t);                 
  digitalWrite(LED7, LOW);  
  delay(t);                  
  digitalWrite(LED6, LOW);     
  delay(t);                  
  digitalWrite(LED5, LOW);   
  delay(t); 
  digitalWrite(LED4, LOW);    
  delay(t);
  digitalWrite(LED3, LOW);    
  delay(t);
  digitalWrite(LED2, LOW);    
  delay(t);
  digitalWrite(LED1, LOW);    
  delay(t);

// Repeat second chasing pattern (left to right) | දෙවන පසුපස්සේ යන ආකාරය නැවත කරන්න (වමේ සිට දකුණට)
  digitalWrite(LED1, HIGH);    
  delay(t); 
  digitalWrite(LED2, HIGH);    
  delay(t); 
  digitalWrite(LED3, HIGH);    
  delay(t); 
  digitalWrite(LED4, HIGH);    
  delay(t); 
  digitalWrite(LED5, HIGH); 
  delay(t);
  digitalWrite(LED6, HIGH);  
  delay(t);
  digitalWrite(LED7, HIGH);  
  delay(t);
  digitalWrite(LED8, HIGH);  
  delay(t);
  digitalWrite(LED9, HIGH);  
  delay(t);
  digitalWrite(LED10, HIGH);  
  delay(t);
  digitalWrite(LED11, HIGH);  
  delay(t);
  digitalWrite(LED12, HIGH);  
  delay(t);


// Turn off LEDs left to right again | LED නැවත වමේ සිට දකුණට නිවා දමන්න
  digitalWrite(LED1, LOW);    
  delay(t);
  digitalWrite(LED2, LOW);    
  delay(t);
  digitalWrite(LED3, LOW);    
  delay(t);
  digitalWrite(LED4, LOW);    
  delay(t);
  digitalWrite(LED5, LOW);    
  delay(t);
  digitalWrite(LED6, LOW);    
  delay(t);
  digitalWrite(LED7, LOW);    
  delay(t);
  digitalWrite(LED8, LOW);    
  delay(t);
  digitalWrite(LED9, LOW);    
  delay(t);
  digitalWrite(LED10, LOW);    
  delay(t);
  digitalWrite(LED11, LOW);    
  delay(t);
  digitalWrite(LED12, LOW);    
  delay(t);

// Final repetition of first chasing pattern (right to left) | පළමු පසුපස්සේ යන ආකාරය අවසන් වතාවට නැවත කරන්න (දකුණේ සිට වමට)
  digitalWrite(LED12, HIGH);    
  delay(t);                 
  digitalWrite(LED11, HIGH);    
  delay(t);                  
  digitalWrite(LED10, HIGH); 
  delay(t);                 
  digitalWrite(LED9, HIGH);  
  delay(t);                  
  digitalWrite(LED8, HIGH);    
  delay(t);                 
  digitalWrite(LED7, HIGH);    
  delay(t);                 
  digitalWrite(LED6, HIGH);  
  delay(t);               
  digitalWrite(LED5, HIGH); 
  delay(t);  
  digitalWrite(LED4, HIGH);    
  delay(t);
  digitalWrite(LED3, HIGH);    
  delay(t);
  digitalWrite(LED2, HIGH);    
  delay(t);
  digitalWrite(LED1, HIGH);    
  delay(t);
   
                    
  digitalWrite(LED12, LOW);    
  delay(t);                
  digitalWrite(LED11, LOW);    
  delay(t);                  
  digitalWrite(LED10, LOW);   
  delay(t);               
  digitalWrite(LED9, LOW);     
  delay(t);               
  digitalWrite(LED8, LOW);  
  delay(t);                 
  digitalWrite(LED7, LOW);  
  delay(t);                  
  digitalWrite(LED6, LOW);     
  delay(t);                  
  digitalWrite(LED5, LOW);   
  delay(t); 
  digitalWrite(LED4, LOW);    
  delay(t);
  digitalWrite(LED3, LOW);    
  delay(t);
  digitalWrite(LED2, LOW);    
  delay(t);
  digitalWrite(LED1, LOW);    
  delay(t);

// Final repetition of second chasing pattern (left to right) | දෙවන පසුපස්සේ යන ආකාරය අවසන් වතාවට නැවත කරන්න (වමේ සිට දකුණට)
  digitalWrite(LED1, HIGH);    
  delay(t);
  digitalWrite(LED2, HIGH);    
  delay(t);
  digitalWrite(LED3, HIGH);    
  delay(t);
  digitalWrite(LED4, HIGH);    
  delay(t); 
  digitalWrite(LED5, HIGH); 
  delay(t);
  digitalWrite(LED6, HIGH);  
  delay(t);
  digitalWrite(LED7, HIGH);  
  delay(t);
  digitalWrite(LED8, HIGH);  
  delay(t);
  digitalWrite(LED9, HIGH);  
  delay(t);
  digitalWrite(LED10, HIGH);  
  delay(t);
  digitalWrite(LED11, HIGH);  
  delay(t);
  digitalWrite(LED12, HIGH);  
  delay(t);

// Turn off all LEDs after final chase | අවසන් පසුපස්සේ යන ආකාරයෙන් පසු සියලු LED නිවා දමන්න
  digitalWrite(LED1, LOW);    
  delay(t);
  digitalWrite(LED2, LOW);    
  delay(t);
  digitalWrite(LED3, LOW);    
  delay(t);
  digitalWrite(LED4, LOW);    
  delay(t);
  digitalWrite(LED5, LOW);    
  delay(t);
  digitalWrite(LED6, LOW);    
  delay(t);
  digitalWrite(LED7, LOW);    
  delay(t);
  digitalWrite(LED8, LOW);    
  delay(t);
  digitalWrite(LED9, LOW);    
  delay(t);
  digitalWrite(LED10, LOW);    
  delay(t);
  digitalWrite(LED11, LOW);    
  delay(t);
  digitalWrite(LED12, LOW);    
  delay(t);

// Turn on all LEDs simultaneously for 3 seconds | සියලු LED එකවර 3 තත්පරයක් අලුත් කරන්න
  digitalWrite(LED1, HIGH); 
  digitalWrite(LED2, HIGH); 
  digitalWrite(LED3, HIGH); 
  digitalWrite(LED4, HIGH);    
  digitalWrite(LED5, HIGH); 
  digitalWrite(LED6, HIGH);  
  digitalWrite(LED7, HIGH);  
  digitalWrite(LED8, HIGH);  
  digitalWrite(LED9, HIGH);  
  digitalWrite(LED10, HIGH);  
  digitalWrite(LED11, HIGH);  
  digitalWrite(LED12, HIGH);  
  delay(3000);

// Closing effect: Turn off LEDs in pairs from outside to inside | වසා දැමීමේ ආකාරය: LED යුගල වශයෙන් පිටතේ සිට ඇතුළට නිවා දමන්න
  digitalWrite(LED12, LOW);
  digitalWrite(LED1, LOW);
  delay(y);
  digitalWrite(LED11, LOW);
  digitalWrite(LED2, LOW);
  delay(y);
  digitalWrite(LED10, LOW);
  digitalWrite(LED3, LOW);
  delay(y);
  digitalWrite(LED9, LOW);
  digitalWrite(LED4, LOW);
  delay(y);
  digitalWrite(LED8, LOW);
  digitalWrite(LED5, LOW);
  delay(y);
  digitalWrite(LED7, LOW);
  digitalWrite(LED6, LOW);
  delay(y);
   
// Ensure all LEDs are off | සියලු LED නිවී ඇති බවට වග බලා ගන්න
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);    
  digitalWrite(LED5, LOW);    
  digitalWrite(LED6, LOW);    
  digitalWrite(LED7, LOW);    
  digitalWrite(LED8, LOW);    
  digitalWrite(LED9, LOW);    
  digitalWrite(LED10, LOW);    
  digitalWrite(LED11, LOW);    
  digitalWrite(LED12, LOW); 
  delay(2000);   // Final pause before repeating the loop | ලූපය නැවත ආරම්භ කිරීමට පෙර අවසාන විරාමය
   
}
