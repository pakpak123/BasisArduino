int led = 9; // LED connected to digital pin 13
void setup()
{
pinMode(led, OUTPUT); // initialize the digital pin as an output
}
void loop()
{
digitalWrite(led, HIGH); // turn the LED on (HIGH is the voltage level)
delay(100); // wait for a second (1000 milliseconds)
digitalWrite(led, LOW); // turn the LED off by making the voltage LOW
delay(100); // wait for a second (1000 milliseconds)
}
