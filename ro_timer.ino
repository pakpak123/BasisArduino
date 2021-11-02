#include "TimerOne.h"

 

int D1 = 8;

int D2 = 9;

int D3 = 10;

int D4 = 11;

int CommonAK = 1; // Common Anode set to 1, Common Cathode set to 2

 

int num[] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F };

int OnDigi = 0;

int NumberDisplay = 0;

bool ColonShow = false;

 

 

void setup() {

  // put your setup code here, to run once:

  Begin7Segment4Digi();

  NumberDisplay = 2558;

}

 

void loop() {

  

}

 

void Begin7Segment4Digi() {

  DDRD  = 0xFF;

  pinMode(D1, OUTPUT);

  pinMode(D2, OUTPUT);

  pinMode(D3, OUTPUT);

  pinMode(D4, OUTPUT);

  digitalWrite(D1, (CommonAK==1 ? LOW : HIGH));

  digitalWrite(D2, (CommonAK==1 ? LOW : HIGH));

  digitalWrite(D3, (CommonAK==1 ? LOW : HIGH));

  digitalWrite(D4, (CommonAK==1 ? LOW : HIGH));

  Timer1.initialize(1000); // 1000 = 1mS

  Timer1.attachInterrupt(NextDigi);

}

 

void NextDigi() {

  digitalWrite(D1, (CommonAK==1 ? LOW : HIGH));

  digitalWrite(D2, (CommonAK==1 ? LOW : HIGH));

  digitalWrite(D3, (CommonAK==1 ? LOW : HIGH));

  digitalWrite(D4, (CommonAK==1 ? LOW : HIGH));

  int ShowOn = 0;

  OnDigi = (OnDigi==4 ? 1 : OnDigi+1);

  if (OnDigi==1) {

    if (NumberDisplay<10)

      ShowOn = NumberDisplay;

    else

      ShowOn = NumberDisplay%10;

  } else if (OnDigi==2) {

    if (NumberDisplay<10)

      ShowOn = 0;

    if (NumberDisplay<100)

      ShowOn = NumberDisplay/10;

    if (NumberDisplay<1000)

      ShowOn = (NumberDisplay/10)%10;

    if (NumberDisplay<10000)

      ShowOn = (NumberDisplay/10)%10;

  } else if (OnDigi==3) {

    ShowOn = (NumberDisplay / 100) % 10;

  } else if (OnDigi==4) {

    ShowOn = NumberDisplay / 1000;

  }

  if (CommonAK==1)

    PORTD = ~((num[ShowOn])|(ColonShow&&OnDigi==3 ? 0x80 : 0));

  else

    PORTD = ((num[ShowOn])|(ColonShow&&OnDigi==3 ? 0x80 : 0));

  if (OnDigi==1) {

    digitalWrite(D1, (CommonAK==1 ? LOW : HIGH));

    digitalWrite(D2, (CommonAK==1 ? LOW : HIGH));

    digitalWrite(D3, (CommonAK==1 ? LOW : HIGH));

    digitalWrite(D4, (CommonAK==1 ? HIGH : LOW));

  } else if (OnDigi==2) {

    digitalWrite(D1, (CommonAK==1 ? LOW : HIGH));

    digitalWrite(D2, (CommonAK==1 ? LOW : HIGH));

    digitalWrite(D3, (CommonAK==1 ? HIGH : LOW));

    digitalWrite(D4, (CommonAK==1 ? LOW : HIGH));

  } else if (OnDigi==3) {

    digitalWrite(D1, (CommonAK==1 ? LOW : HIGH));

    digitalWrite(D2, (CommonAK==1 ? HIGH : LOW));

    digitalWrite(D3, (CommonAK==1 ? LOW : HIGH));

    digitalWrite(D4, (CommonAK==1 ? LOW : HIGH));

  } else if (OnDigi==4) {

    digitalWrite(D1, (CommonAK==1 ? HIGH : LOW));

    digitalWrite(D2, (CommonAK==1 ? LOW : HIGH));

    digitalWrite(D3, (CommonAK==1 ? LOW : HIGH));

    digitalWrite(D4, (CommonAK==1 ? LOW : HIGH));

  }

}
