
void setup() 
{
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);

}

void loop() 
{
int Temp = analogRead(A0);
Serial.println(Temp);
if(Temp<50)
{
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
}
else if(Temp<150)
{
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
}
else if(Temp<250)
{
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
}
else if(Temp<350)
{
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
}
else if(Temp<450)
{
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
}
else if(Temp<550)
{
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
}
else if(Temp<650)
{
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
}
}
