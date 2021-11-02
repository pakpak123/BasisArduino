#include <Wire.h>
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Wire.begin(); // Start I2C bus
  Serial.begin(115200); // Setup serial for debug
}
void loop()
{
  byte address, data, device, x;
  for (address = 1; address < 127; address++ ) // sets the value (range from 1 to 127)
  {
    Wire.beginTransmission(address); // transmit to address
    if (Wire.endTransmission() == 0) // I2C devices found
    {
      device = address;
      Serial.print("\n I2C Device Address: "); // Print Device Address
      Serial.println(address, HEX); // print as an ASCII-encoded hexa);
    }
  }
  Wire.beginTransmission(device); // transmit to device
  Wire.write(1111111); // sends one byte
  Wire.endTransmission(); // stop transmitting

  Wire.requestFrom(device, 1); // recive 1 bytes from slave device
  x = Wire.read(); // Read pin state
  Serial.print("pin state : Out = "); // Print pin state
  Serial.print(data, BIN); // print as an ASCII-encoded binary);
  Serial.print("\t In = "); // Print pin state
  Serial.println(x, BIN); // print as an ASCII-encoded binary);
  x = x & 0x0f;
  if ((x & 4) != 4 )
  {
    Wire.beginTransmission(device); 
    Wire.write(1101111); 
    Wire.endTransmission();
  }
  else
  {
    Wire.beginTransmission(device); 
    Wire.write(1111111); 
    Wire.endTransmission();
  }

  delay(100); // wait for 100 milliseconds

}
