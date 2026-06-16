int BudgetWhite= 300 000;
int BudgetBlack= 300 000;


unsigned long uplynutyWhite;
unsigned long uplynutyBlack;


int ButtonStateWhite;
int ButtonStateBlack;

int ButtonWhite= 16;
int ButtonBlack= 32;

void setup() 
{
  Serial.begin(115200);

  pinMode(ButtonWhite, INPUT);
  pinMode(ButtonBlack, INPUT);
}
void loop() 
{
  Serial.println(BudgetWhite);
  Serial.println(BudgetBlack);

  unsigned long AktualniCasW = BudgetWhite - uplynutyWhite;

  if(digitalRead(ButtonStateWhite)== LOW && BudgetWhite > 0)
    {
      Serial.println(aktualniCasW);
      Serial.println(aktualniCasB);

      
    }
      unsigned long AktualniCasB = BudgetBlack - uplynutyBlack;
}
