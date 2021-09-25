
void setup() 
{
  Serial.begin(9600);

}

void loop() 
{
int Temp = analogRead(A0);
Serial.println(Temp);


}
