int led8=8;
int led9=9;
int led10=10;
int led11=11;
int led12=12;
int led13=13;
int temp=0;
int i;
int j;
int n;
int BUTTON = 2;
//void switch1();
void setup() {
  pinMode(led8,OUTPUT);
  pinMode(led9,OUTPUT);
  pinMode(led10,OUTPUT);
  pinMode(led11,OUTPUT);
  pinMode(led12,OUTPUT);
  pinMode(led13,OUTPUT);
  pinMode(BUTTON,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON),switch1,CHANGE);
  Serial.begin(9600);
}

void loop() 
{
  
  for (i = 50; i > 0; i--)
  {
    for (n = 8; n <= 12; n++)
    {

      digitalWrite(n, HIGH);
      delay(i);
      digitalWrite(n, LOW);

    }
  }
  if(temp == 1)
  {
    digitalWrite(led13,HIGH);
    delay(1000);
    digitalWrite(led13,LOW);
    temp--;
  }
}

void switch1()
{
  temp=1;
}
