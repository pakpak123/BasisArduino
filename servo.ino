#include <Servo.h>
#include <Wire.h>
#include <hd44780.h> // main hd44780 header
#include <hd44780_I2Cexp.h> // i2c expander i/o class header
hd44780_I2Cexp lcd; //lare lcd object: auto locate & config exapander chip
const int LCD_COLS = 16;
const int LCD_ROWS = 2;
Servo myservo; //ประกาศตัวแปรแทน Servo
const int pingPin = 7;
int inPin = 8;
void setup()
{
Serial.begin(9600);
myservo.attach(9); // กำหนดขา 9 ควบคุม Servo
int status;
status = lcd.begin(LCD_COLS, LCD_ROWS);
if(status) // non zero status means it was unsuccesful
{
// begin() failed so blink error code using the onboard LED if possible
hd44780::fatalError(status); // does not return
}
lcd.print("LCD I2C");
}

void loop()
{
long duration, cm;
pinMode(pingPin, OUTPUT);
digitalWrite(pingPin, LOW);
delayMicroseconds(2);
digitalWrite(pingPin, HIGH);
delayMicroseconds(5);
digitalWrite(pingPin, LOW);
pinMode(inPin, INPUT);
duration = pulseIn(inPin, HIGH);

cm = microsecondsToCentimeters(duration);

Serial.print(cm);
Serial.print("cm");
Serial.println();
delay(100);  

if(cm<10)
{
myservo.write(180); // สั่งให้ Servo หมุนไปองศาที่ 180
delay(1000); // หน่วงเวลา 1000ms
}
else
{
myservo.write(0); // สั่งให้ Servo หมุนไปองศาที่ 0
delay(1000); // หน่วงเวลา 1000ms
}
}

long microsecondsToCentimeters(long microseconds)
{
return microseconds / 29 / 2;
}
