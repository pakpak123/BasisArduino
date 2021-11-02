int led13 = 13;
int led7 = 7;
void setup() 
{
  pinMode(led13,OUTPUT);
  pinMode(led7,OUTPUT);
  noInterrupts();
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  OCR1A = 15624;
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS12)|(1 << CS10);
  TIMSK1 |= (1 << OCIE1A);
  interrupts();
}

void loop() 
{
  // put your main code here, to run repeatedly:
}
