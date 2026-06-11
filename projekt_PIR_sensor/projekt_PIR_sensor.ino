int tlacitko=16;
int PIR=2;
int led=32;
int buzzer=17;

String code="";

unsigned long startTime=millis;
int waitingTime=30000;

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);

pinMode(tlacitko, INPUT_PULLDOWN);
pinMode(PIR, INPUT);
pinMode(led, OUTPUT);
pinMode(buzzer, OUTPUT);
}

void loop() 
{
if(digitalRead(tlacitko)== HIGH)
  {
  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(led, LOW);
  delay(500);
  
    while(digitalRead(PIR)==HIGH && startTime > waitingTime )
      {
      digitalWrite(buzzer, HIGH);
         if(Serial.available()>0)
          {
          code = Serial.readStringUntil('\n');
          code.trim();
            if(code== "I wanna money")
              {
              Serial.println("lucky this time man");
              digitalWrite(buzzer, LOW);
              digitalWrite(led, LOW);
              }
            else
            {
            Serial.println("youre a dead man darling");
            }
          }
      }
}
}
