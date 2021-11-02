int BUTTON = 2;
int led8 = 8;
int led9 = 9;
int led10 = 10;
int led11 = 11;
int led12 = 12;
int LED = 13;
int i, j, n, ch;
void setup()
{
  Serial.begin(9600);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  pinMode(led10, OUTPUT);
  pinMode(led11, OUTPUT);
  pinMode(led12, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP); //PULL UP

  attachInterrupt(digitalPinToInterrupt(BUTTON) , switch1, CHANGE);
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
}


void switch1()
{
  if (digitalRead(BUTTON) == LOW)
    digitalWrite(LED, HIGH);
  else
    digitalWrite(LED, LOW);
}
