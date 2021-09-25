
void setup() 
{
  Serial.begin(9600);

}

void loop() 
{
int Temp = analogRead(A1);
Serial.println(Temp);


}
