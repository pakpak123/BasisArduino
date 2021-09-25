
void setup() 
{
  Serial.begin(9600);
  pinMode(10,OUTPUT);
}

void loop() 
{
int Temp = analogRead(A1);
Serial.println(Temp);
if(Temp>1000)
{
  digitalWrite(10,LOW);
}
else
{
  digitalWrite(10,HIGH);
}

} 
