#include <Wire.h>
#include <hd44780.h> // main hd44780 header
#include <hd44780_I2Cexp.h> // i2c expander i/o class header
hd44780_I2Cexp lcd; //lare lcd object: auto locate & config exapander chip
const int LCD_COLS = 16;
const int LCD_ROWS = 2;
void setup()
{
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

}
