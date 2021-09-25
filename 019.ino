
void setup() 
{
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);

}

void loop() 
{
int Temp = analogRead(A0);
Serial.println(Temp);
if(Temp<512)
{
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
}
else 
{
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
}


}
