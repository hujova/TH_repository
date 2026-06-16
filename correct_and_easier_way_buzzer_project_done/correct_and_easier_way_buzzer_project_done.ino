int PIR=16;
int led=19;
int tlacitko=22;
int buzzer=32;

enum AlarmState {DISARMED,  ARMING, ARMED, ALARM};
int AlarmStateState=DISARMED;

unsigned long StartTime;

String code= ""; 

void setup() 
{
Serial.begin(115200);

pinMode(PIR, INPUT);
pinMode(buzzer, OUTPUT);
pinMode(led, OUTPUT);
pinMode(tlacitko, INPUT_PULLDOWN);
}

void loop() 
{
switch(AlarmStateState)
  {
  

  case DISARMED: 
    
    if(digitalRead(tlacitko)==HIGH)
      {
        Serial.println("HIGH");
        StartTime=millis();
        AlarmStateState=ARMING;
        Serial.println("DISARMED");
      }
    
  break;

  case ARMING:
    if(millis()-StartTime > 10000)
      {
       Serial.println("ALARMING");
       AlarmStateState=ARMED;
      }
  break;

  case ARMED:
    if(digitalRead(PIR)==HIGH)
      {
        Serial.println("ARMED");
        AlarmStateState=ALARM;
      }
  break;

  case ALARM:
    digitalWrite(buzzer, HIGH);
    digitalWrite(led, HIGH);
  
    if(Serial.available()> 0)
      {
        code= Serial.readStringUntil('\n');
        code.trim();
          if(code== "tvoje mama")
            {
              Serial.println("saved");
              digitalWrite(buzzer, LOW);
              digitalWrite(led, LOW);
              AlarmStateState = DISARMED;
            }
          else
            {
              Serial.println("You are d**d");
            }
      }
  break; 
  }

}
