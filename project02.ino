#include <Servo.h>
#include <Wire.h>
#define A 2
#define B 3

int shine = A0;
int IR = A1;
Servo servo;
int angle = 180;

void setup() {
  // put your setup code here, to run once:
  servo.attach(9);
  servo.write(angle);
  Serial.begin(9600);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  digitalWrite(B, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensor1 = analogRead(shine);
  int sensor2 = analogRead(IR);
  Serial.println(sensor2);

  if (sensor1 < 700)//ถ้าสว่างค่าจะน้อยกว่า 700
  {
    digitalWrite(A,LOW);
  }
  else // ถ้าคลื้มๆถึงมืดไฟจะติดจ้าา ประมาณ 700 ขึ้นไป
  {
    digitalWrite(A, HIGH);
  }
  delay(1000);
  if (sensor2 > 960) ///ค่ามากขึ้นเมื่อมือมาใกล้
  {
    servo.write(180); // สั่งให้ Servo หมุนไปองศาที่ 180
    delay(1000); // หน่วงเวลา 1000ms
  }
  else
  {
    servo.write(0); // สั่งให้ Servo หมุนไปองศาที่ 0
    delay(1000); // หน่วงเวลา 1000ms
  }
}
