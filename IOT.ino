#include <Servo.h>
#include <Wire.h>
#include <hd44780.h> // main hd44780 header
#include <hd44780_I2Cexp.h> // i2c expander i/o class header
hd44780_I2Cexp lcd; // declare lcd object: auto locate & config exapander chip
int col;
int row;
const int LCD_COLS = 16 ;
const int LCD_ROWS = 2 ;
const int pingPin = 13; //วัดระยะทางตอนเข้า
int inPin = 12;  //วัดระยะทางตอนเข้า
int BUTTON = 2;
int buzzer_module = 8;
int Press = 0;


Servo myservo;

void setup()
{
  Serial.begin(9600);
  myservo.attach(9);
  pinMode(buzzer_module, OUTPUT);
  int status;
  status = lcd.begin(LCD_COLS, LCD_ROWS);
  if (status) // non zero status means it was unsuccesful
  {
    // begin() failed so blink error code using the onboard LED if possible
    hd44780::fatalError(status); // does not return
  }

  pinMode(BUTTON, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON) , switch1, CHANGE);
}

void loop()
{
  if (Press == 1)
  {
    int Temp = analogRead(A1);
    Serial.println(Temp);


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

   


    if (cm <= 30 || Temp <= 1015)
    {

      digitalWrite(buzzer_module, HIGH);
      lcd.print("DOOR IS OPEN!");
      myservo.write(180);
      delay(500);
      digitalWrite(buzzer_module, LOW);
      delay(1000);
      lcd.clear();
    }
    else if (cm > 30 || Temp > 1015)
    {
      myservo.write(90);
      delay(1000);
      digitalWrite(buzzer_module, LOW);
      delay(1000);
    }
  }
  else if(Press==0)
  {
      lcd.print("Program CLOSE");
      delay(1000);
      lcd.clear();
  }
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

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

}
