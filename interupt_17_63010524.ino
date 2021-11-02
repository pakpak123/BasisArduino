#include<Wire.h>
#include <hd44780.h>
#include<hd44780_I2Cexp.h>

hd44780_I2Cexp lcd;

const int LCD_COLS = 16;
const int LCD_ROWS = 2;
int num = 15;

int BUTTON1 = 2;
int BUTTON2 = 3;

boolean toggle = 1;

int digit[6];

int hours = 0;
int minutes = 0;
int sec = 0;

int thours = 0;
int tminutes = 0;
int tsec = 0;

ISR(TIMER1_COMPA_vect)
{
  sec++;
  if(sec >= 60)
  {
    minutes++;
    sec = 0;
  }
  if(minutes >= 60)
  {
    hours++;
    minutes = 0;
  }
}

uint8_t char0[8] = {0x00,0x00,0x04,0x00,0x00,0x04,0x00,0x00};

void setup() {
  Serial.begin(9600);
  int status;
  status = lcd.begin(LCD_COLS,LCD_ROWS);
  if(status)
  {
    hd44780::fatalError(status);
  }                  
  pinMode(BUTTON1,INPUT_PULLUP);
  pinMode(BUTTON2,INPUT_PULLUP);
  lcd.createChar(0, char0);
  attachInterrupt(digitalPinToInterrupt(BUTTON1),switch1,RISING);
  attachInterrupt(digitalPinToInterrupt(BUTTON2),switch2,RISING);
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

void loop() {
  Serial.println(toggle);
  lcd.setCursor(4,1);
  for(int i=0;i<=5;i++)
  {
    lcd.print(digit[i]);
    if(i == 1 || i == 3)
    lcd.write(0);
  }
  if(toggle == 1){ 
  digit[0] = hours/10;
  digit[1] = hours%10;
  digit[2] = minutes/10;
  digit[3] = minutes%10;
  digit[4] = sec/10;
  digit[5] = sec%10;
  }
}

void switch1(){
  if(toggle == 0){
  toggle = 1;
  sec = tsec;
  minutes = tminutes;
  hours = thours;
  }
  else{
  toggle = 0;
  thours = hours;
  tminutes = minutes;
  tsec = sec;
  }
}

void switch2(){
  sec = 0;
  minutes = 0;
  hours = 0;
  tsec = 0;
  tminutes = 0;
  thours = 0;
  for(int i = 0;i<=5;i++)
  {
    digit[i] = 0;
  }
}
