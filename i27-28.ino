// Write data to I2C slave device
#include <Wire.h>
byte address,data,device,x;
void setup()
{
 Wire.begin(); // Start I2C bus
 Serial.begin(115200); // Setup serial for debug

for(address = 1; address < 127; address++ ) // sets the value (range from 1 to 127)
 {
    Wire.beginTransmission(address); // transmit to address
    if (Wire.endTransmission() == 0) // I2C devices found
    {
        device = address;
        Serial.print("\n I2C Device Address: "); // Print Device Address
        Serial.println(address, HEX); // print as an ASCII-encoded hexa);
    }
 }
   
}
void loop()
{

 Wire.requestFrom(device, 1); // recive 1 bytes from slave device
 x = Wire.read(); // Read pin state

 Serial.print("\t pin state : In = "); // Print pin state
 Serial.println(x, BIN); // print as an ASCII-encoded binary);
 x = x & 0x0f;
 Serial.print("\t pin state : In = "); // Print pin state
 Serial.println(x, BIN); // print as an ASCII-encoded binary);
  if ((x & 2) != 2)
  {
    data = 0x80 | x;
    for (int i = 1 ; i <= 4; i++) // sets the value (range from 1 to 4)
    {
        Wire.beginTransmission(device); // transmit to device
        Wire.write(data); // sends one byte
        Wire.endTransmission(); // stop transmitting
        delay(5); // wait for stepper speed

        Serial.print("\n Out = "); // Print pin state
        Serial.println(data, BIN); // print as an ASCII-encoded binary);
        data = data >> 1;
        data = data | x;
    }  
 }
 

 

}
