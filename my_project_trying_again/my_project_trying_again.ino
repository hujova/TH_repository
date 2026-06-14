int PIR=16;
int led=19;
int tlacitko=22;
int buzzer=32;

enum AlarmState  {DISARMED,  ARMING, ARMED, ALARM};

unsigned long startTime;

String kod="";

void setup() 
{
pinMode(PIR, INPUT);
pinMode(buzzer, OUTPUT);
pinMode(led, OUTPUT);
pinMode(tlacitko, INPUT_PULLDOWN);

Serial.begin(115200);
}

void loop() 
{
  if(digitalRead(tlacitko)==HIGH)
   {
    startTime=millis();
    Serial.println("tlacitko je high");
      if(millis()- startTime > 3000)
       {
         
          if(digitalRead(PIR)==HIGH)
           {
             Serial.println("You have been seen");
             
             digitalWrite(led, HIGH);
             digitalWrite(buzzer, HIGH);
             Serial.println("Write the kod or your dead ");
              if(Serial.available()> 0)
               {
                kod= Serial.readStringUntil('\n');
                kod.trim();
                 if(kod=="tvoje mama")
                  {
                    Serial.println("YOu got lucky today");
                    digitalWrite(buzzer, LOW);
                    digitalWrite(led, LOW);
                   
                  }
                  else
                    {
                      Serial.println("dead");
                    }
               }
           }
       }
  }
}
