#include <Wire.h>
#include <hd44780.h> // main hd44780 header
#include <hd44780_I2Cexp.h> // i2c expander i/o class header
hd44780_I2Cexp lcd; // declare lcd object: auto locate & config exapander chip
const int LCD_COLS = 16;
const int LCD_ROWS = 2;

byte address,data,x,device1=0x25,device2=0x20;

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  int count = 0;
  int status;
  status = lcd.begin(LCD_COLS, LCD_ROWS);
  if(status) // non zero status means it was unsuccesful
  {
     // begin() failed so blink error code using the onboard LED if possible
    hd44780::fatalError(status); // does not return
  }
}
void loop()
{ 
  lcd.scrollDisplayLeft();
  lcd.setCursor(9, 0);
  lcd.write("<"); // write character 1
  lcd.write("N"); // write character 2
  //lcd.write(" ");
  lcd.write("I"); // write character 3
  lcd.write("C"); // write character 3
  lcd.write("H"); // write character 3
  lcd.write("I"); // write character 3
  lcd.write("P"); // write character 4
  lcd.write("A"); // write character 5
  lcd.write(">"); // write character 6
  delay(100);

  
  data = 0x80; //1000 0000 --> 0100 0000
  for (int i = 1 ; i <= 4; i++) // sets the value (range from 1 to 8)
  {
    Wire.beginTransmission(device1); // transmit to device
    Wire.write(data); // sends one byte
    Wire.endTransmission(); // stop transmitting
    Serial.print("pin state : Out = "); // Print pin state
    Serial.print(data, BIN); // print as an ASCII-encoded binary);
   
    Serial.print("\t, In = "); // Print pin state
    Serial.println(x, BIN); // print as an ASCII-encoded binary);
    delay(10); // wait for stepper speed
    data = data >> 1;
    
  }
}
