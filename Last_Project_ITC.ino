
const int pingPin = 7; //trig
int inPin = 8;
int BUTTON = 2;
int Press = 0;
#include <Servo.h>
#include <Wire.h>

const int LCD_COLS = 16;
const int LCD_ROWS = 2;
Servo myservo; //ประกาศตัวแปรแทน Servo


void switch1()
{
  if (digitalRead(BUTTON) == LOW)
  {
    Press++;

    if (Press > 1)
    {
      Press = 0;
    }
    Serial.println(Press);

  }
  delay(200);

}

void setup() {

  int status;
  Serial.begin(9600);

  myservo.attach(9);
  attachInterrupt(digitalPinToInterrupt(BUTTON) , switch1, CHANGE);
  pinMode(BUTTON, INPUT_PULLUP);

}



void loop()
{

  if (Press == 1)
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

    if (cm < 12)
    {
      myservo.write(90); // สั่งให้ Servo หมุนไปองศาที่ 180
      delay(500); // หน่วงเวลา 1000ms
    }
    else
    {
      myservo.write(180); // สั่งให้ Servo หมุนไปองศาที่ 0
      delay(500); // หน่วงเวลา 1000ms
    }
  }
  else if (Press == 0)
  {
    
  }

}
long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
