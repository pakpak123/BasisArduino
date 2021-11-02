int segmentA = A1;
int segmentB = A2;
int segmentC = A3;
int segmentD = 2;
int segmentE = 4
;
int segmentF = 7;
int segmentG = 8;
int segmentDP = 13;
int digit1 = 5;
int digit2 = 6;
int digit3 = 9;
int digit4 = 10;
void setup()
{
pinMode(segmentA, OUTPUT);
pinMode(segmentB, OUTPUT);
pinMode(segmentC, OUTPUT);
pinMode(segmentD, OUTPUT);
pinMode(segmentE, OUTPUT);
pinMode(segmentF, OUTPUT);
pinMode(segmentG, OUTPUT);
pinMode(segmentDP, OUTPUT);
pinMode(digit1, OUTPUT);
pinMode(digit2, OUTPUT);
pinMode(digit3, OUTPUT);
pinMode(digit4, OUTPUT);
Serial.begin(9600);
}

void loop()
{
int sensorValue = analogRead(A0); 
float voltage = sensorValue * (10.0 / 1023.0); 
Serial.println(voltage);

int intVoltage = voltage*100;
int digit4 = intVoltage%10;
intVoltage = (intVoltage-digit4)/10;
int digit3 = intVoltage%10;
intVoltage = (intVoltage-digit3)/10;
int digit2 = intVoltage%10;
if(intVoltage<10)
{ digit1 = 0;
} else {intVoltage = (intVoltage-digit2)/10;
int digit1 = intVoltage;}


displaySegment(1,digit1,2);
displaySegment(2,digit2,2);
displaySegment(3,digit3,2);
displaySegment(4,digit4,2);

}

void displaySegment(int digitToDisplay,char numberToDisplay,int delayToDisplay)
{
switch (digitToDisplay)
{
  case 1:
  digitalWrite(digit1,HIGH);
  break;
  case 2:
  digitalWrite(digit2,HIGH);
  digitalWrite(segmentDP, HIGH);
  break;
  case 3:
  digitalWrite(digit3,HIGH);
  break;
  case 4:
  digitalWrite(digit4,HIGH);
  break;
}
switch (numberToDisplay)
{
case 0:                         //แสดงผลเลข 0
digitalWrite(segmentA, HIGH);
digitalWrite(segmentB, HIGH);
digitalWrite(segmentC, HIGH);
digitalWrite(segmentD, HIGH);
digitalWrite(segmentE, HIGH);
digitalWrite(segmentF, HIGH);
digitalWrite(segmentG, LOW);
break;
case 1:                         //แสดงผลเลข 1
digitalWrite(segmentA, LOW);
digitalWrite(segmentB, HIGH);
digitalWrite(segmentC, HIGH);
digitalWrite(segmentD, LOW);
digitalWrite(segmentE, LOW);
digitalWrite(segmentF, LOW);
digitalWrite(segmentG, LOW);
break;
case 2: ;                       //แสดงผลเลข 2
digitalWrite(segmentA, HIGH);
digitalWrite(segmentB, HIGH);
digitalWrite(segmentC, LOW);
digitalWrite(segmentD, HIGH);
digitalWrite(segmentE, HIGH);
digitalWrite(segmentF, LOW);
digitalWrite(segmentG, HIGH);
break;
case 3: ;                       //แสดงผลเลข 3
digitalWrite(segmentA, HIGH);
digitalWrite(segmentB, HIGH);
digitalWrite(segmentC, HIGH);
digitalWrite(segmentD, HIGH);
digitalWrite(segmentE, LOW);
digitalWrite(segmentF, LOW);
digitalWrite(segmentG, HIGH);
break;
case 4:                         //แสดงผลเลข 4
digitalWrite(segmentA, LOW);
digitalWrite(segmentB, HIGH);
digitalWrite(segmentC, HIGH);
digitalWrite(segmentD, LOW);
digitalWrite(segmentE, LOW);
digitalWrite(segmentF, HIGH);
digitalWrite(segmentG, HIGH);
break;
case 5:                         //แสดงผลเลข 5
digitalWrite(segmentA, HIGH);
digitalWrite(segmentB, LOW);
digitalWrite(segmentC, HIGH);
digitalWrite(segmentD, HIGH);
digitalWrite(segmentE, LOW);
digitalWrite(segmentF, HIGH);
digitalWrite(segmentG, HIGH);
break;
case 6:                         //แสดงผลเลข 6
digitalWrite(segmentA, HIGH);
digitalWrite(segmentB, LOW);
digitalWrite(segmentC, HIGH);
digitalWrite(segmentD, HIGH);
digitalWrite(segmentE, HIGH);
digitalWrite(segmentF, HIGH);
digitalWrite(segmentG, HIGH);
break;
case 7:                         //แสดงผลเลข 7
digitalWrite(segmentA, HIGH);
digitalWrite(segmentB, HIGH);
digitalWrite(segmentC, HIGH);
digitalWrite(segmentD, LOW);
digitalWrite(segmentE, LOW);
digitalWrite(segmentF, LOW);
digitalWrite(segmentG, LOW);
break;
case 8:                         //แสดงผลเลข 8
digitalWrite(segmentA, HIGH);
digitalWrite(segmentB, HIGH);
digitalWrite(segmentC, HIGH);
digitalWrite(segmentD, HIGH);
digitalWrite(segmentE, HIGH);
digitalWrite(segmentF, HIGH);
digitalWrite(segmentG, HIGH);
break;
case 9:                         //แสดงผลเลข 9
digitalWrite(segmentA, HIGH);
digitalWrite(segmentB, HIGH);
digitalWrite(segmentC, HIGH);
digitalWrite(segmentD, HIGH);
digitalWrite(segmentE, LOW);
digitalWrite(segmentF, HIGH);
digitalWrite(segmentG, HIGH);
break;
}
delay(delayToDisplay);
digitalWrite(segmentDP, LOW);
digitalWrite(digit1,LOW);
digitalWrite(digit2,LOW);
digitalWrite(digit3,LOW);
digitalWrite(digit4,LOW);
}
