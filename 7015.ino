 int ThermistorPin = A3;
int Vo;
float R1 = 10000;
float logR2, R2, T, Tf;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
int segmentA = A0; 
int segmentB = A1; 
int segmentC = A2; 
int segmentD = 2; 
int segmentE = 4; 
int segmentF = 7; 
int segmentG = 8; 
int segmentDP = 13;
#include <string.h>
using namespace std;

void setup() {
Serial.begin(9600);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(segmentA, OUTPUT); 
  pinMode(segmentB, OUTPUT); 
  pinMode(segmentC, OUTPUT); 
  pinMode(segmentD, OUTPUT); 
  pinMode(segmentE, OUTPUT); 
  pinMode(segmentF, OUTPUT); 
  pinMode(segmentG, OUTPUT); 
  pinMode(segmentDP, OUTPUT);
}

void loop() {
int i = 0;
 String Tc;
  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  Tc = T - 273.15; 
 char* p1 = &Tc[0];
 char* p2 = &Tc[1];
 char* p3 = &Tc[3];
 char* p4 = &Tc[4];
  int c1 = *p1;
  int c2 = *p2;
  int c3 = *p3;
  int c4 = *p4; 
  
  Serial.print("Temperature: "); 
  Serial.print(Tc);
  Serial.println(" C");
  LOOP:
  displaySegment(c1-48,5); 
  delay(2);
  displaySegment(c2-48,6); 
  delay(2);
  displaySegment(c3-48,9);
  delay(2); 
  displaySegment(c4-48,10); 
  delay(2);
  displaySegment(10,6); 
  delay(2);
  i++;
  if(i <= 250)
     {goto LOOP;}
}

void displaySegment(int T, int pos)
{
  switch (T)
  {
    case 0: 
   digitalWrite(5, LOW); 
   digitalWrite(6, LOW);
   digitalWrite(9, LOW);
   digitalWrite(10, LOW);
   digitalWrite(pos, HIGH);
  digitalWrite(segmentA, HIGH); 
  digitalWrite(segmentB, HIGH); 
  digitalWrite(segmentC, HIGH); 
  digitalWrite(segmentD, HIGH); 
  digitalWrite(segmentE, HIGH); 
  digitalWrite(segmentF, HIGH); 
  digitalWrite(segmentG, LOW); 
  break;
  case 1: 
    digitalWrite(5, LOW); 
   digitalWrite(6, LOW);
   digitalWrite(9, LOW);
   digitalWrite(10, LOW);
   digitalWrite(pos, HIGH);
  digitalWrite(segmentA, LOW);
  digitalWrite(segmentB, HIGH);
  digitalWrite(segmentC, HIGH);
  digitalWrite(segmentD, LOW);
  digitalWrite(segmentE, LOW);
  digitalWrite(segmentF, LOW);
  digitalWrite(segmentG, LOW);
  digitalWrite(segmentDP, LOW);
  break;
  case 2:  
    digitalWrite(5, LOW); 
   digitalWrite(6, LOW);
   digitalWrite(9, LOW);
   digitalWrite(10, LOW);
   digitalWrite(pos, HIGH);
  digitalWrite(segmentA, HIGH);
  digitalWrite(segmentB, HIGH);
  digitalWrite(segmentC, LOW);
  digitalWrite(segmentD, HIGH);
  digitalWrite(segmentE, HIGH);
  digitalWrite(segmentF, LOW);
  digitalWrite(segmentG, HIGH);
  digitalWrite(segmentDP, LOW);
  break;
  case 3:  
 digitalWrite(5, LOW); 
   digitalWrite(6, LOW);
   digitalWrite(9, LOW);
   digitalWrite(10, LOW);
   digitalWrite(pos, HIGH);
  digitalWrite(segmentA, HIGH);
  digitalWrite(segmentB, HIGH);
  digitalWrite(segmentC, HIGH);
  digitalWrite(segmentD, HIGH);
  digitalWrite(segmentE, LOW);
  digitalWrite(segmentF, LOW);
  digitalWrite(segmentG, HIGH);
  digitalWrite(segmentDP, LOW);
  break;
  case 4:  
   digitalWrite(5, LOW); 
   digitalWrite(6, LOW);
   digitalWrite(9, LOW);
   digitalWrite(10, LOW);
   digitalWrite(pos, HIGH);
  digitalWrite(segmentA, LOW);
  digitalWrite(segmentB, HIGH);
  digitalWrite(segmentC, HIGH);
  digitalWrite(segmentD, LOW);
  digitalWrite(segmentE, LOW);
  digitalWrite(segmentF, HIGH);
  digitalWrite(segmentG, HIGH);
  digitalWrite(segmentDP, LOW);
  break;
  case 5:
   digitalWrite(5, LOW); 
   digitalWrite(6, LOW);
   digitalWrite(9, LOW);
   digitalWrite(10, LOW);
   digitalWrite(pos, HIGH);
      digitalWrite(segmentA, HIGH); 
      digitalWrite(segmentB, LOW); 
      digitalWrite(segmentC, HIGH); 
      digitalWrite(segmentD, HIGH); 
      digitalWrite(segmentE, LOW); 
      digitalWrite(segmentF, HIGH); 
      digitalWrite(segmentG, HIGH);
      digitalWrite(segmentDP, LOW); 
      break;
     case 6:
   digitalWrite(5, LOW); 
   digitalWrite(6, LOW);
   digitalWrite(9, LOW);
   digitalWrite(10, LOW);
   digitalWrite(pos, HIGH);
      digitalWrite(segmentA, HIGH); 
      digitalWrite(segmentB, LOW); 
      digitalWrite(segmentC, HIGH); 
      digitalWrite(segmentD, HIGH); 
      digitalWrite(segmentE, HIGH); 
      digitalWrite(segmentF, HIGH); 
      digitalWrite(segmentG, HIGH);
      digitalWrite(segmentDP, LOW); 
      break;
case 7:
    digitalWrite(5, LOW); 
   digitalWrite(6, LOW);
   digitalWrite(9, LOW);
   digitalWrite(10, LOW);
   digitalWrite(pos, HIGH);
      digitalWrite(segmentA, HIGH); 
      digitalWrite(segmentB, HIGH); 
      digitalWrite(segmentC, HIGH); 
      digitalWrite(segmentD, LOW); 
      digitalWrite(segmentE, LOW); 
      digitalWrite(segmentF, LOW); 
      digitalWrite(segmentG, LOW); 
      digitalWrite(segmentDP, LOW);
      break;
     case 8:
     digitalWrite(5, LOW); 
   digitalWrite(6, LOW);
   digitalWrite(9, LOW);
   digitalWrite(10, LOW);
   digitalWrite(pos, HIGH);
      digitalWrite(segmentA, HIGH); 
      digitalWrite(segmentB, HIGH); 
      digitalWrite(segmentC, HIGH); 
      digitalWrite(segmentD, HIGH); 
      digitalWrite(segmentE, HIGH); 
      digitalWrite(segmentF, HIGH); 
      digitalWrite(segmentG, HIGH);
      digitalWrite(segmentDP, LOW); 
      break;
     case 9:
     digitalWrite(5, LOW); 
   digitalWrite(6, LOW);
   digitalWrite(9, LOW);
   digitalWrite(10, LOW);
   digitalWrite(pos, HIGH);
      digitalWrite(segmentA, HIGH); 
      digitalWrite(segmentB, HIGH); 
      digitalWrite(segmentC, HIGH); 
      digitalWrite(segmentD, HIGH); 
      digitalWrite(segmentE, LOW); 
      digitalWrite(segmentF, HIGH); 
      digitalWrite(segmentG, HIGH); 
      digitalWrite(segmentDP, LOW);
      break;
      case 10:
   digitalWrite(5, LOW); 
   digitalWrite(6, LOW);
   digitalWrite(9, LOW);
   digitalWrite(10, LOW);
   digitalWrite(pos, HIGH);;
      digitalWrite(segmentA, LOW); 
      digitalWrite(segmentB, LOW); 
      digitalWrite(segmentC, LOW); 
      digitalWrite(segmentD, LOW); 
      digitalWrite(segmentE, LOW); 
      digitalWrite(segmentF, LOW); 
      digitalWrite(segmentG, LOW);
      digitalWrite(segmentDP, HIGH); 
      break;
  } 
}
