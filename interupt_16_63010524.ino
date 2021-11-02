int led8 = 8;
int led9 = 9;
int sec = 0;
int minutes = 0;
int hours = 0;
int halfSec = 0;

boolean toggle8=0;
boolean toggle9=0;

ISR(TIMER1_COMPA_vect)
{
  halfSec++;
  if(toggle8){
    digitalWrite(led8,HIGH);
    toggle8 = 0;
  }
  else{
    digitalWrite(led8,LOW);
    toggle8 = 1;
  }
  if(halfSec >= 2)
  {
    sec++;
    halfSec = 0;
    if(toggle9){
      digitalWrite(led9,LOW);
      toggle9 = 0;
    }
  }
  if(sec >= 60)
  {
    minutes++;
    sec = 0;
    digitalWrite(led9,HIGH);
    toggle9 = 1;
  }
  if(minutes >= 60)
  {
    hours++;
    minutes = 0;
  }
}

void setup() {
  pinMode(led8,OUTPUT);
  pinMode(led9,OUTPUT);
  noInterrupts();
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  OCR1A = 7812;
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS12)|(1 << CS10);
  TIMSK1 |= (1 << OCIE1A);
  interrupts();
}

void loop() {
  // put your main code here, to run repeatedly:
}
