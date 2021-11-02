#include <Wire.h>
#include <hd44780.h> // main hd44780 header
#include <hd44780_I2Cexp.h> // i2c expander i/o class header
hd44780_I2Cexp lcd; // declare lcd object: auto locate & config exapander chip
const int LCD_COLS = 16;
const int LCD_ROWS = 2;
int vcc = 7;
int state ;
int i = 16;
void setup()
{
Serial.begin(9600);
  int status;
uint8_t char0[8] = {0x00,0x0E,0x00,0x1A,0x0A,0x0A,0x0F,0x0B}; // Char 0 
uint8_t char1[8] = {0x00,0x01,0x02,0x1C,0x0A,0x0A,0x0A,0x0E}; // Char 1 
uint8_t char2[8] = {0x00,0x00,0x00,0x0E,0x02,0x02,0x02,0x02}; // Char 2 
uint8_t char3[8] = {0x00,0x00,0x00,0x1E,0x0A,0x0A,0x0A,0x1A}; // Char 3 
uint8_t char4[8] = {0x00,0x00,0x00,0x0E,0x02,0x02,0x02,0x02}; // Char 4 
  pinMode(vcc, INPUT_PULLUP);
  pinMode(vcc, OUTPUT);


  status = lcd.begin(LCD_COLS, LCD_ROWS);
  //lcd.lineWrap();  // ถ้าเดิน 16 หลักจะขึ้นบรรทัดใหม่ทันที
lcd.createChar(0, char0);
lcd.createChar(1, char1);
lcd.createChar(2, char2);
lcd.createChar(3, char3);
lcd.createChar(4, char4);


  if (status) // non zero status means it was unsuccesful
  {
    // begin() failed so blink error code using the onboard LED if possible
    hd44780::fatalError(status); // does not return
  }


  // lcd.print("LCD I2C");

}
void loop()
{
Serial.println(digitalRead(7));
  state = digitalRead(7)==0;
// digi เป็นการเช็คว่าค่าที่กดเท่ากับ 0 ไหม ถ้าเท่าก็เป็นจริง คือ 1 ออกมา ดังนั้น state ก็จะเท่ากับ 1 ด้วยแล้วเข้า เคสที่เท่ากับ 1 ด้านล่าง

  if (state == 0)
  {
    i--;
    if (i == -1)
    {
      i = 16;
    }
    lcd.clear();
    lcd.setCursor(i, 0);  // แถว , หลัก  ตอนเริ่ม
    lcd.write(0); // write character 0
    lcd.write(1); // write character 1
    lcd.write(2); // write character 2
    lcd.write(3); // write character 3
    lcd.write(4); // write character 4
    
  }
  if (state == 1)
  {
    i++;
    if (i == 16)
    {
      i = 0;
    }

    lcd.clear();
    lcd.setCursor(i, 0);  // แถว , หลัก  ตอนเริ่ม
    lcd.write(0); // write character 0
    lcd.write(1); // write character 1
    lcd.write(2); // write character 2
    lcd.write(3); // write character 3
    lcd.write(4); // write character 4

  }

delay(500);
}
