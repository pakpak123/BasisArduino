#include <Wire.h>
#include <hd44780.h> // main hd44780 header
#include <hd44780_I2Cexp.h> // i2c expander i/o class header
hd44780_I2Cexp lcd; //lare lcd object: auto locate & config exapander chip
int col;
int row;

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
lcd.lineWrap();
uint8_t char0[8] = {0x00,0x0E,0x00,0x1A,0x0A,0x0A,0x0F,0x0B}; // Char 0 
uint8_t char1[8] = {0x00,0x01,0x02,0x1C,0x0A,0x0A,0x0A,0x0E}; // Char 1 
uint8_t char2[8] = {0x00,0x00,0x00,0x0E,0x02,0x02,0x02,0x02}; // Char 2 
uint8_t char3[8] = {0x00,0x00,0x00,0x1E,0x0A,0x0A,0x0A,0x1A}; // Char 3 
uint8_t char4[8] = {0x00,0x00,0x00,0x0E,0x02,0x02,0x02,0x02}; // Char 4 

lcd.clear();

lcd.createChar(0, char0);
lcd.createChar(1, char1);
lcd.createChar(2, char2);
lcd.createChar(3, char3);
lcd.createChar(4, char4);


}

void loop()
{
for(int x=11 ; x>=0 ; x--)
{
lcd.clear();
lcd.setCursor(x, 0);
lcd.write(0); // write character 0
lcd.write(1); // write character 1
lcd.write(2); // write character 2
lcd.write(3); // write character 3
lcd.write(4); // write character 4

delay(500);
lcd.clear();
}
}
