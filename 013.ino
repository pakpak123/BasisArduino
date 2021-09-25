int time_=50;
int yum = 9;
int led1 = 9;
int led2 = 10;
int led3 = 11;
int led4 = 12;
int led5 = 13;
void setup()
{
pinMode(yum, OUTPUT);
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(led4, OUTPUT);
pinMode(led5, OUTPUT);
}
void loop()
{
  if(yum=9){
    for(;yum<13;yum++){
      digitalWrite(yum, HIGH); 
      delay(time_);
      digitalWrite(yum, LOW);
      delay(time_);
    }
  }
   if(yum=13){
    for(;yum>9;yum--){
      digitalWrite(yum, HIGH); 
      delay(time_);
      digitalWrite(yum, LOW);
      delay(time_);
    }
  }
}
