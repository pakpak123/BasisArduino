/*
  Use the I2C bus with EEPROM device
  EEPROM 8 (Vcc) to Vcc
  EEPROM 4 (GND) to GND
  EEPROM 5 (SDA) to Arduino Analog Pin 4(SDA)
  EEPROM 6 (SCL) to Arduino Analog Pin 5(SCL)
  EEPROM 7 (WP) to GND
  /* Memory length in bytes
  24C01 = 128
  24C02 = 256
  24C04 = 512
  24C08 = 1024
  24C16 = 2048
  24C64 = 8192
  24C128= 16384
  24C256= 32768
*/
#define memorylength 512
#include <Wire.h>
#define sw_r 8
#define sw_c 9

byte deviceAddress; // Address of EEPROM chip
int eepromAddress;
int n, j, k;



void setup()
{
  byte eepromData;
  byte i;
  int c = 0;

  Serial.begin(9600); // Setup serial for debug
  Wire.begin(); // Start I2C bus
  for (i = 1; i < 127; i++ ) // sets the value (range from 1 to 127)
  {
    Wire.beginTransmission(i); // transmit to device
    if (Wire.endTransmission() == 0) // I2C devices found
    {
      deviceAddress = i;
      Serial.print("I2C Device Address: "); // Print Device Address
      Serial.println(deviceAddress, HEX);
      break;
    }
    pinMode(LED_BUILTIN, OUTPUT);

  }

  char na[8] = {'N','i','c','h','a','p','a',' '};
  char num[8] = {'6','3','0','1','0','5','2','4'};
  char detail[20] = {'F', 'E', 'M', 'A', 'L', 'E', ' ', 'S', 'E', 'C', '1', '8'};
  
  eepromAddress = 0x20;
  for (n = 0; n < sizeof(na); n++)
  {
    writeEEPROM_page(deviceAddress, eepromAddress, (byte *)na, n);
    eepromAddress++;
  }

  eepromAddress = 0x40;
  for (n = 0; n < sizeof(num); n++)
  {
    writeEEPROM_page(deviceAddress, eepromAddress, (byte *)num, n);
    eepromAddress++;
  }

  eepromAddress = 0x60;
  for (n = 0; n < sizeof(detail); n++)
  {
    writeEEPROM_page(deviceAddress, eepromAddress, (byte *)detail, n);
    eepromAddress++;
  }

  for (k = 1; k <= 8; k++)
  {
    if (k == 1) j = 6;
    if (k == 2) j = 3;
    if (k == 3) j = 0;
    if (k == 4) j = 1;
    if (k == 5) j = 0;
    if (k == 6) j = 5;
    if (k == 7) j = 2;
    if (k == 8) j = 4;

    if (j > 0)
    {
      for (n = 1; n <= j; n++)
      {
        digitalWrite(LED_BUILTIN, HIGH);  
        delay(500);
        digitalWrite(LED_BUILTIN, LOW);
        delay(500);
      }
      delay(500);
    }
    else
    {
      delay(1000);
    }

  }

}

void loop()
{
  byte ch;
  //Serial.print(" ");
  /*eepromAddress = 0; // first address
    ch = readEEPROM_byte(deviceAddress, eepromAddress); // access the first address from the memory
    while (ch != 0xFF)
    {
    Serial.print((char) ch); // print content to serial port
    eepromAddress++; // increase address
    ch = readEEPROM_byte(deviceAddress, eepromAddress); // access an address from the memory


    }
    Serial.println(" ");*/
  dumpEEPROM(deviceAddress, 0, memorylength);
  delay(2000);

  Serial.println("\n\n");


}

byte readEEPROM_byte(int device, int address )
{
  byte rdata = 0;
  Wire.beginTransmission(device | (address >> 8));
  Wire.write((int)(address & 0xFF)); // LSB
  Wire.endTransmission();
  Wire.requestFrom(device, 1);
  if (Wire.available())
    rdata = Wire.read();

  return rdata;
}

void writeEEPROM_page(int device, int address, byte* buffer, int x )
{
  Wire.beginTransmission(device | (address >> 8));
  Wire.write((int)(address & 0xFF));
  Wire.write(buffer[x]);
  Wire.endTransmission();
  delay(10);
}

void dumpEEPROM(byte device, unsigned address, unsigned length)
{
  unsigned startAddress = address;
  unsigned stopAddress = address + length;
  for (unsigned i = startAddress; i < stopAddress; i += 16)
  {
    char buffer[16]; // page of EEPROM
    char temp[4];
    sprintf(temp, "%02x: ", i); // print address
    Serial.print(temp);
    readEEPROM_page(device, i, buffer, 16);
    for (int j = 0; j < 16; j++)
    {
      sprintf(temp, "%04x ", byte(buffer[j])); // print data (hexa)
      Serial.print(temp);
    }
    Serial.print(" ");
    for (int j = 0; j < 16; j++) // print data (ASCII)
    {
      if (isprint(buffer[j]))
        Serial.print(buffer[j]);
      else
        Serial.print('.');
    }
    Serial.println(" ");
  }
}

byte readEEPROM_page(int device, int address, byte *buffer, int length )
{
  byte i;
  Wire.beginTransmission(device | (address >> 8));
  Wire.write((int)(address & 0xFF)); // LSB
  Wire.endTransmission();
  Wire.requestFrom(device, length);
  for ( i = 0; i < length; i++ )
    if (Wire.available())
      buffer[i] = Wire.read();
}
