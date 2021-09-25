int led1 = 10;
int led2 = 9;
void setup()
{
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
}
void loop()
{
digitalWrite(led1, HIGH); 
digitalWrite(led2, HIGH);
delay(500); 
digitalWrite(led1, LOW); 
delay(500); 
digitalWrite(led2, LOW); 
digitalWrite(led1, HIGH); 
delay(500); 
digitalWrite(led1, LOW); 
delay(500); 
}
