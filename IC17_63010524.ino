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
int ledkeaw = 8;
int leddaeng = 9;
int switch1 = 2;
int switch2 = 3;
byte backup[1024];
#define memorylength 1024
#include <Wire.h>
byte deviceAddress; // Address of EEPROM chip
unsigned int eepromAddress;

void writeEEPROM_page(int device, unsigned int address, byte* buffer, byte length )
{
  byte i;
  Wire.beginTransmission(device | int(address >> 8));
  Wire.write((int)(address & 0xFF)); // LSB
  for ( i = 0; i < length; i++)
    Wire.write(buffer[i]);
  Wire.endTransmission();
  delay(5);
}
void writeEEPROM_byte(int device, unsigned int address, byte data )
{
  Wire.beginTransmission(device);
  Wire.write((int)(address >> 8)); // MSB
  Wire.write((int)(address & 0xFF)); // LSB
  Wire.write(data);
  Wire.endTransmission();
  delay(5);
}
byte readEEPROM_page(int device, unsigned int address, byte *buffer, int length )
{
  byte i;
  Wire.beginTransmission(device | int(address >> 8));
  Wire.write((int)(address & 0xFF)); // LSB
  Wire.endTransmission();
  Wire.requestFrom(device, length);
  for ( i = 0; i < length; i++ )
    if (Wire.available())
      buffer[i] = Wire.read();
}
byte readEEPROM_byte(int device, unsigned int address )
{
  byte rdata = 0;
  Wire.beginTransmission(device);
  Wire.write((int)(address >> 8)); // MSB
  Wire.write((int)(address & 0xFF)); // LSB
  Wire.endTransmission();
  Wire.requestFrom(device, 1);
  if (Wire.available())
    rdata = Wire.read();
  return rdata;
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
      backup[i + j] = temp;
    }
    Serial.print("");
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
bool check = 1;
void setup()
{
  pinMode(ledkeaw, OUTPUT);
  pinMode(leddaeng, OUTPUT);
  byte eepromData;
  byte i;

  Serial.begin(9600); // Setup serial for debug
  Wire.begin(); // Start I2C bus
  eepromAddress = 0;
  deviceAddress = 0x50;
}
void loop()
{
  if (analogRead(switch1) <= 512) {
    dumpEEPROM(deviceAddress, 0, memorylength);
  }
  if (analogRead(switch2) <= 512) {
    for (int i = 0; i < 1024; i += 16)
    {
      for (int j = 0; j < 16; j++)
      {
        writeEEPROM_byte(deviceAddress, eepromAddress + i + j, backup[i + j] );
      }
    }
    if (check == 1) {
      digitalWrite(ledkeaw, 1);
      delay (2000);
      digitalWrite(ledkeaw, 0);
    }
    else
    {
      digitalWrite(leddaeng, 1);
      delay (2000);
      digitalWrite(leddaeng, 0);
    }
  }

}
