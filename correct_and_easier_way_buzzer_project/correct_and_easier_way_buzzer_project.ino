int PIR=16;
int led=19;
int tlacitko=22;
int buzzer=32;

int AlarmState state;
enum AlarmState {DISARMED,  ARMING, ARMED, ALARM};

unsigned long StartTime;

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
switch(state)
  {
  state=DISARMEND;

  case DISARMED
    if(digitalRead(tlacitko)==HIGH)
      {
        millis()=StartTime;
        state=ARMING;
        Serial.println("DISARMED");
      }
  break;

  case ARMING
    if(millis()-StartTIme > 10000)
      {
       Serial.println("ALARMING");
       state=ARMED
      }
  break;

  case ARMED
    if(digitalRead(PIR)==HIGH)
      {
        Serial.println("ARMED");
        state=ALARM;
      }
  break;

  case ALARM
    digitalWrite(buzzer, HIGH);
    digitalWrite(led, HIGH);

  break;
  }

}
