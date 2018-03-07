/*
  Erst-Version der Steuerung

  TODO: 1. Anpassen der PWM-Werte auf die tatsächlich vertraeglichen Groessen
*/


#define POWER_LEVEL_4  (255*4/4) // Level 4 = 100%
#define POWER_LEVEL_3  (255*3/4) // Level 3 =  75%
#define POWER_LEVEL_2  (255*2/4) // Level 2 =  50%
#define POWER_LEVEL_1  (255*1/4) // Level 1 =  25%


#define PIN_MOSFET_L 9  // muss ein PWM-faehiger PIN sein
#define PIN_MOSFET_R 10 // muss ein PWM-faehiger PIN sein

#define PIN_S_L_1 6     // Wahlschalter Links,  Level 1
#define PIN_S_L_2 7     // Wahlschalter Links,  Level 2
#define PIN_S_L_3 8     // Wahlschalter Links,  Level 3
#define PIN_S_R_1 11    // Wahlschalter Rechts, Level 1
#define PIN_S_R_2 12    // Wahlschalter Rechts, Level 2
#define PIN_S_R_3 13    // Wahlschalter Rechts, Level 3 - Achtung: PIN 13 ist LED_BUILTIN, dann nicht nutzbar 

#define PIN_AA_L 2      // Ein-Aus-Schalter Links
#define PIN_AA_R 3      // Ein-Aus-Schalter Rechts



// the setup routine runs once when you press reset:
void setup() {
  pinMode(PIN_MOSFET_L, OUTPUT);
  pinMode(PIN_S_L_1,    INPUT_PULLUP);
  pinMode(PIN_S_L_2,    INPUT_PULLUP);
  pinMode(PIN_S_L_3,    INPUT_PULLUP);
  pinMode(PIN_AA_L,     INPUT_PULLUP);
  pinMode(PIN_MOSFET_R, OUTPUT);
  pinMode(PIN_S_R_1,    INPUT_PULLUP);
  pinMode(PIN_S_R_2,    INPUT_PULLUP);
  pinMode(PIN_S_R_3,    INPUT_PULLUP);
  pinMode(PIN_AA_R,     INPUT_PULLUP);

  // Nur zur Sicherheit: MOSFET auf AUS
  digitalWrite(PIN_MOSFET_L, LOW);
  digitalWrite(PIN_MOSFET_R, LOW);  
}

// the loop routine runs over and over again forever:
void loop() {
  if(digitalRead(PIN_AA_L) == HIGH) { // Ok, links an
    if(digitalRead(PIN_S_L_3) == HIGH) { // Level 4 
      analogWrite( PIN_MOSFET_L, POWER_LEVEL_4);
    } else 
    if(digitalRead(PIN_S_L_2) == HIGH) { // Level 3
      analogWrite( PIN_MOSFET_L, POWER_LEVEL_3);
    } else 
    if(digitalRead(PIN_S_L_1) == HIGH) { // Level 2 
      analogWrite( PIN_MOSFET_L, POWER_LEVEL_2);
    } else                               // Level 1 
      analogWrite( PIN_MOSFET_L, POWER_LEVEL_1); 
  }
  
  if(digitalRead(PIN_AA_R) == HIGH) { // Ok, rechts an
    if(digitalRead(PIN_S_R_3) == HIGH) { // Level 4 
      analogWrite( PIN_MOSFET_R, POWER_LEVEL_4);
    } else 
    if(digitalRead(PIN_S_R_2) == HIGH) { // Level 3 
      analogWrite( PIN_MOSFET_R, POWER_LEVEL_3);
    } else 
    if(digitalRead(PIN_S_R_1) == HIGH) { // Level 2
      analogWrite( PIN_MOSFET_R, POWER_LEVEL_2);
    } else                               // Level 1 
      analogWrite( PIN_MOSFET_L, POWER_LEVEL_1); 
  }
  
  delay(100);
}
