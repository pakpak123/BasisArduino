int BUTTON = 2;
int led8 = 8;
int led9 = 9;
int led10 = 10;
int led11 = 11;
int led12 = 12;
int i, j, n;
void setup()
{
  Serial.begin(9600);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  pinMode(led10, OUTPUT);
  pinMode(led11, OUTPUT);
  pinMode(led12, OUTPUT);
  pinMode(led13, OUTPUT);
  pinMode(BUTTON, INPUT);
}
void loop()
{


  for (i = 50; i > 0; i--)
  {
    for (n = 8; n <= 12; n++)
    {
      if (digitalRead(BUTTON) == LOW)
      {
        digitalWrite(n, LOw);
      }
      
      else
      {
              
        digitalWrite(n, HIGH);
        delay(i);
        digitalWrite(n, LOW);  
        
      }
    }

  }

}
