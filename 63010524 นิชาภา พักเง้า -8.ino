3int led = 9; 
void setup()
{
  pinMode(led, OUTPUT); 
}
void loop()
{
for(int i =500;10<i;i=i-200)
{
  digitalWrite(led,HIGH);
  delay(i);
  digitalWrite(led,LOW);
  delay(3*i);
}
}
