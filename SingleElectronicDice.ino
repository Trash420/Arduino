
// Define Pins
#define LED1 4
#define LED2 5
#define LED3 6
#define LED4 7
#define LED5 8
#define LED6 9
#define LED7 10


// --------------- START Configuration ---------------
int DelayTime = 10;
short ClearTime = 3000;
// --------------- STOP Configuration ---------------

int z = 0;
bool ClearingDice = false;
bool debug = true;

void setup() {
  pinMode(11, INPUT_PULLUP);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  Serial.begin(9600);
  if (debug) {
    Serial.println ("--------------- START Debug Mod ---------------");
    Serial.println ("Setup DONE !");
    Serial.println ("--------------- STOP Debug Mod ---------------");
  };
};

void loop() {
  BoutonCheck();
  ClearDice();
};

void BoutonCheck() {
  if (digitalRead(11) == LOW)
    {
       if (debug) {
          Serial.println ("--------------- START Debug Mod ---------------");
          Serial.println ("Bouton pushed !");
       };
       RollDice();
    };
};

void RollDice() {

  z = 1 + random (6);
  
  if (debug) {
    Serial.println ("Rolled dice !");
    Serial.print ("Dice make a ");
    Serial.print (z);
    Serial.println (".");
  };
  
  Result();
};

void Result() {
  
  if (debug) {
    Serial.println ("Display result on dice.");
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
  ClearingDice = true;
  if (debug) {
    Serial.print ("Waiting ");
    Serial.print (ClearTime);
    Serial.println ("ms for clear dice ...");
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
    ClearingDice = false;
    if (debug) {
      Serial.println ("Dice cleared !");
      Serial.println ("--------------- STOP Debug Mod ---------------");
    };
  };
};
