// Define Pins
#define LED1 15
#define LED2 2
#define LED3 3
#define LED4 4
#define LED5 5
#define LED6 6
#define LED7 7

#define LED8 8
#define LED9 9
#define LED10 10
#define LED11 11
#define LED12 12
#define LED13 13
#define LED14 14


// --------------- START Configuration ---------------
int DelayTime = 10;     // 
short ClearTime = 3000;       // Time to wait before clear dice
bool testLED = true;        // 
bool ClearingDice = false;
bool debug = true;
// --------------- STOP Configuration ---------------

int z = 0;
int y = 0;

void setup() {
  pinMode(0, INPUT_PULLUP);
  pinMode(20, INPUT_PULLUP);
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
  pinMode(LED13, OUTPUT);
  pinMode(LED14, OUTPUT);
  
  Serial.begin(9600);
  if (debug) {
    Serial.println ("--------------- START Debug Mod ---------------");
    Serial.println ("Setup DONE !");
    if (testLED) {
      Serial.println ("Mode testLED ON");
    }
    else {
      Serial.println ("Mode testLED OFF");
    };
    
    Serial.println ("--------------- STOP Debug Mod ---------------");
  };
};

void loop() {
  BoutonCheck();
  ClearDice();
};

void BoutonCheck() {
  if (digitalRead(0) == LOW)
    {
       if (debug) {
          Serial.println ("--------------- START Debug Mod ---------------");
          Serial.println ("Bouton pushed !");
       };
       RollDice();
    };

    if (digitalRead(20) == LOW)
      {
         if (debug) {
          Serial.println ("RollDice Disabled !");
         };
      }
      else {
        Serial.println ("RollDice enabled !");
      }
};

void RollDice() {

  z = 1 + random (6);
  y = 1 + random (6);
  
  if (testLED) {
    z = 7;
    y = 7;
  };

  if (debug) {
    Serial.println ("Rolled dice 1 !");
    Serial.print ("Dice 1 make a ");
    Serial.print (z);
    Serial.println (".");
    Serial.println ("Rolled dice 2 !");
    Serial.print ("Dice 2 make a ");
    Serial.print (y);
    Serial.println (".");
  };
  
  Result();
};

void Result() {
  
  if (debug) {
    Serial.println ("Display result on dice 1.");  
    Serial.println ("Display result on dice 2.");
  };
  if (z == 7) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, HIGH);
    digitalWrite(LED6, HIGH);
    digitalWrite(LED7, HIGH);
  };
  if (z == 6) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED5, HIGH);
    digitalWrite(LED6, HIGH);
    digitalWrite(LED7, HIGH);
  };
  if (z == 5) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, HIGH);
    digitalWrite(LED7, HIGH);
  };         
  if (z == 4) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED5, HIGH);
    digitalWrite(LED7, HIGH);
  };
  if (z == 3) {
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED7, HIGH);
  };
  if (z == 2) {
    digitalWrite(LED3, HIGH);
    digitalWrite(LED7, HIGH);
  };
  if (z == 1) {
    digitalWrite(LED4, HIGH);
  };

  
  
  if (y == 7) {
    digitalWrite(LED8, HIGH);
    digitalWrite(LED9, HIGH);
    digitalWrite(LED10, HIGH);
    digitalWrite(LED11, HIGH);
    digitalWrite(LED12, HIGH);
    digitalWrite(LED13, HIGH);
    digitalWrite(LED14, HIGH);
  };
  if (y == 6) {
    digitalWrite(LED8, HIGH);
    digitalWrite(LED9, HIGH);
    digitalWrite(LED10, HIGH);
    digitalWrite(LED12, HIGH);
    digitalWrite(LED13, HIGH);
    digitalWrite(LED14, HIGH);
  };
  if (y == 5) {
    digitalWrite(LED8, HIGH);
    digitalWrite(LED10, HIGH);
    digitalWrite(LED11, HIGH);
    digitalWrite(LED12, HIGH);
    digitalWrite(LED14, HIGH);
  };         
  if (y == 4) {
    digitalWrite(LED8, HIGH);
    digitalWrite(LED10, HIGH);
    digitalWrite(LED12, HIGH);
    digitalWrite(LED14, HIGH);
  };
  if (y == 3) {
    digitalWrite(LED10, HIGH);
    digitalWrite(LED11, HIGH);
    digitalWrite(LED14, HIGH);
  };
  if (y == 2) {
    digitalWrite(LED10, HIGH);
    digitalWrite(LED14, HIGH);
  };
  if (y == 1) {
    digitalWrite(LED11, HIGH);
  };
  
  ClearingDice = true;
  if (debug) {
    Serial.print ("Waiting ");
    Serial.print (ClearTime);
    Serial.println ("ms for clear dices ...");
  };
};

void ClearDice() {
  while (ClearingDice) {
    delay (ClearTime);
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
    digitalWrite(LED13, LOW);
    digitalWrite(LED14, LOW);
    ClearingDice = false;
    if (debug) {
      Serial.println ("Dice 1 and Dice 2 cleared !");
      Serial.println ("--------------- STOP Debug Mod ---------------");
    };
  };
};
