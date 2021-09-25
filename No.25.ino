#define LED_B 9 //green
#define LED_G 10 //red
#define LED_R 11 //blue



void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
 pinMode(LED_B,OUTPUT);
 pinMode(LED_G,OUTPUT);
 pinMode(LED_R,OUTPUT);
  digitalWrite(LED_B,LOW);
  digitalWrite(LED_G,LOW);
  digitalWrite(LED_R,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
int Temp = analogRead(A0);
Serial.println(Temp);



if(Temp>= 40 && Temp < 163)
{
  digitalWrite(LED_B,HIGH);
  digitalWrite(LED_G,LOW);
  digitalWrite(LED_R,HIGH);
  }
if(Temp>= 163 && Temp < 286)
{
  digitalWrite(LED_B,HIGH);
  digitalWrite(LED_G,LOW);
  digitalWrite(LED_R,LOW);
  }
  if(Temp>= 286 && Temp < 409)
  {
  digitalWrite(LED_B,HIGH);
  digitalWrite(LED_G,HIGH);
  digitalWrite(LED_R,LOW);
    }
   if(Temp>= 490 && Temp < 532)
    {
 digitalWrite(LED_B,LOW);
 digitalWrite(LED_G,HIGH);
 digitalWrite(LED_R,LOW);
      }
      if(Temp>= 532 && Temp < 655)
      {
  
 digitalWrite(LED_B,LOW);
 digitalWrite(LED_G,HIGH);
 digitalWrite(LED_R,HIGH);      }
      
      if(Temp>= 655 && Temp < 778)
      {
          
 digitalWrite(LED_B,LOW);
 digitalWrite(LED_G,LOW);
 digitalWrite(LED_R,HIGH);
        }
         if(Temp>= 901 && Temp < 1024 )
    {
 digitalWrite(LED_B,HIGH);
 digitalWrite(LED_G,HIGH);
 digitalWrite(LED_R,HIGH);
 }
  
        


}
