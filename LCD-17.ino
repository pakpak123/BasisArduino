#include <Wire.h>
#include <hd44780.h> // main hd44780 header
#include <hd44780_I2Cexp.h> // i2c expander i/o class header
#include <Wire.h>
byte  data = 0x80, device, x, address;
hd44780_I2Cexp lcd; // declare lcd object: auto locate & config exapander chip
const int LCD_COLS = 16;
const int LCD_ROWS = 2;
int col , row;
int i = -3;
uint8_t char0[8] = {0x01,
                    0x01,
                    0x1F,
                    0x01,
                    0x1F,
                    0x11,
                    0x19,
                    0x19}; // Char 0 - Upper-left
uint8_t char1[8] = {0x0E,
                    0x00,
                    0x0E,
                    0x0A,
                    0x02,
                    0x02,
                    0x06,
                    0x06
                   }; // Char 1 - Upper-middle
uint8_t char2[8] = {   0x00,
                     0x00,
                     0x0A,
                     0x15,
                     0x11,
                     0x1D,
                     0x15,
                     0x1D
                   }; // Char 2 - Upper-right
uint8_t char3[8] = {0x07,
                    0x00,
                    0x0A,
                    0x15,
                    0x11,
                    0x1D,
                    0x15,
                    0x1D
                   }; // Char 3 - Lower-left
uint8_t char4[8] = {0x00, 0x11, 0x1f, 0x1f, 0x0e, 0x00, 0x1F, 0x00}; // Char 4 - Lower-middle
uint8_t char5[8] = {0x09, 0x19, 0x1b, 0x12, 0x04, 0x18, 0x00, 0x00}; // Char 5 - Lower-right
int bStatus;
void setup()
{
  pinMode(7, INPUT);
  Serial.begin(9600);
  Wire.begin();
  for (address = 1; address < 127; address++ ) // sets the value (range from 1 to 127)
  {
    Wire.beginTransmission(address); // transmit to address
    if (Wire.endTransmission() == 0) // I2C devices found
    {
      device = address;
    }
  }
}
void loop()
{
 Wire.requestFrom(device, 1); // recive 1 bytes from slave device
  x = Wire.read(); // Read pin state
  int status;
  x = x & 0x0f;
  bStatus = digitalRead(7);
  Serial.println(bStatus);
  status = lcd.begin(LCD_COLS, LCD_ROWS);
  if (status) // non zero status means it was unsuccesful
  {
    // begin() failed so blink error code using the onboard LED if possible
    hd44780::fatalError(status); // does not return
  }
  // create 6 custom characters
  lcd.createChar(0, char0);
  lcd.createChar(1, char1);
  lcd.createChar(2, char2);
  lcd.createChar(3, char3);
  lcd.clear();
  if(!digitalRead(7)){
    if (i == 16) {
      i = -3;
    }
    if (i == -3) {
      lcd.setCursor(0, 0);
      lcd.write(3);
    }
    else if (i == -2) {
      lcd.setCursor(0, 0);
      lcd.write(2);
      lcd.write(3);
    }
    else if (i == -1) {
      lcd.setCursor(0, 0);
      lcd.write(1);
      lcd.write(2);
      lcd.write(3);
    }
    else {
      lcd.setCursor(i, 0);
      lcd.write(0); // write character 0
      lcd.write(1);
      lcd.write(2); // write character 2
      lcd.write(3);
    }
    i++;
    data = 0x10 | x;
    for (int j = 1 ; j <= 4; j++) // sets the value (range from 1 to 4)
    {
      Wire.beginTransmission(device); // transmit to device
      Wire.write(data); // sends one byte
      Wire.endTransmission(); // stop transmitting
      delay(5); // wait for stepper speed

      Serial.print("\n Out = "); // Print pin state
      Serial.print(data, BIN); // print as an ASCII-encoded binary);
      data = data << 1;
      data = data & 0xf0;
      data = data | x;
      data = data | 1;
    }
    delay(200);
    }
  else  {
    if (i == -4) {
      i = 16;
    }
    if (i == -3) {
      lcd.setCursor(0, 0);
      lcd.write(3);
    }
    else if (i == -2) {
      lcd.setCursor(0, 0);
      lcd.write(2);
      lcd.write(3);
    }
    else if (i == -1) {
      lcd.setCursor(0, 0);
      lcd.write(1);
      lcd.write(2);
      lcd.write(3);
    }
    else {
      lcd.setCursor(i, 0);
      lcd.write(0); // write character 0
      lcd.write(1);
      lcd.write(2); // write character 2
      lcd.write(3);
    }
    i--;
    data = 0x80 | x;
    for (int j = 4 ; j >= 1; j--) // sets the value (range from 1 to 4)
    {
      Wire.beginTransmission(device); // transmit to device
      Wire.write(data); // sends one byte
      Wire.endTransmission(); // stop transmitting
      delay(5); // wait for stepper speed

      Serial.print("\n Out = "); // Print pin state
      Serial.print(data, BIN); // print as an ASCII-encoded binary);
      data = data >> 1;
      data = data | x;
    }
    delay(200);
  }
}
