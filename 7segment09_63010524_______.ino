int segmentA = A0;
int segmentB = A1;
int segmentC = A2;
int segmentD = 2;
int segmentE = 4;
int segmentF = 7;
int segmentG = 8;
int segmentDP = 13;
int digit1 = 5;
int digit2 = 6;
int digit3 = 9;
int digit4 = 10;
int digit = 0;

void setup()
{
  Serial.begin(9600);
 pinMode(segmentA, OUTPUT);
 pinMode(segmentB, OUTPUT);
 pinMode(segmentC, OUTPUT);
 pinMode(segmentD, OUTPUT);
 pinMode(segmentE, OUTPUT);
 pinMode(segmentF, OUTPUT);
 pinMode(segmentG, OUTPUT);
 pinMode(digit1, OUTPUT);
 pinMode(digit2, OUTPUT);
 pinMode(digit3, OUTPUT);
 pinMode(digit4, OUTPUT);
 Serial.println("start");
}

void loop()
{
  digitalWrite(digit1,HIGH);
  digitalWrite(digit2,HIGH);
  digitalWrite(digit3,HIGH);
  digitalWrite(digit4,HIGH);
    displayNumber();
}

void displayNumber()
{
 for( digit = 1 ; digit <= 4 ; digit++)
 {
   displaySegment(digit); // แสดงผลบน 7-Segment ขนาด 1 หลัก
   delay(500); // หน่วงเวลา 0.5 วินาที
   switch(digit) {
     case 1:
      digitalWrite(digit1, HIGH);
      break;
     case 2:
      digitalWrite(digit2, HIGH);
      break;
     case 3:
      digitalWrite(digit3, HIGH);
      break;
     case 4:
      digitalWrite(digit4, HIGH);
      break;
      }
   digitalWrite(digit1, LOW);
   digitalWrite(digit2, LOW);
   digitalWrite(digit3, LOW);
   digitalWrite(digit4, LOW);
   delay(500);
   
 }
}


void displaySegment(int numberToDisplay)
{
 switch (numberToDisplay)
 {
  case 0: // แสดงผลเลข 0
    digitalWrite(segmentA, HIGH);
    digitalWrite(segmentB, HIGH);
    digitalWrite(segmentC, HIGH);
    digitalWrite(segmentD, HIGH);
    digitalWrite(segmentE, HIGH);
    digitalWrite(segmentF, HIGH);
    digitalWrite(segmentG, LOW);
  break;
 case 1: // แสดงผลเลข 1
  digitalWrite(digit1, HIGH);
  digitalWrite(digit2, LOW);
  digitalWrite(digit3, LOW);
  digitalWrite(digit4, LOW);
  digitalWrite(segmentA, LOW);
  digitalWrite(segmentB, HIGH);
  digitalWrite(segmentC, HIGH);
  digitalWrite(segmentD, LOW);
  digitalWrite(segmentE, LOW);
  digitalWrite(segmentF, LOW);
  digitalWrite(segmentG, LOW);
 break;

 case 2: // แสดงผลเลข 2
 digitalWrite(digit2, HIGH);
 digitalWrite(segmentA, HIGH);
 digitalWrite(segmentB, HIGH);
 digitalWrite(segmentC, LOW);
 digitalWrite(segmentD, HIGH);
 digitalWrite(segmentE, HIGH);
 digitalWrite(segmentF, LOW);
 digitalWrite(segmentG, HIGH);
 break;

 case 3: // แสดงผลเลข 3
 digitalWrite(digit3, HIGH);
 digitalWrite(segmentA, HIGH);
 digitalWrite(segmentB, HIGH);
 digitalWrite(segmentC, HIGH);
 digitalWrite(segmentD, HIGH);
 digitalWrite(segmentE, LOW);
 digitalWrite(segmentF, LOW);
 digitalWrite(segmentG, HIGH);
 break;
 case 4: // แสดงผลเลข 4
 digitalWrite(digit4, HIGH);
 digitalWrite(segmentA, LOW);
 digitalWrite(segmentB, HIGH);
 digitalWrite(segmentC, HIGH);
 digitalWrite(segmentD, LOW);
 digitalWrite(segmentE, LOW);
 digitalWrite(segmentF, HIGH);
 digitalWrite(segmentG, HIGH);
 break;}}
