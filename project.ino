#define LED1 2
#define LED2 3
#define LED3 4
#define LED4 5
#define LED5 6
#define LED6 7

void Fantacy()
{
  int Temp = analogRead(A1);
    Serial.println(Temp);
 if (Temp >= 40 && Temp < 163)
    {
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, HIGH);
    }
    if (Temp >= 163 && Temp < 286)
    {
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);
    }
    if (Temp >= 286 && Temp < 409)
    {
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED6, LOW);
    }
    if (Temp >= 490 && Temp < 532)
    {
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED6, LOW);
    }
    if (Temp >= 532 && Temp < 655)
    {

      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED6, HIGH);
    }

    if (Temp >= 655 && Temp < 778)
    {

      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, HIGH);
    }
    if (Temp >= 901 && Temp < 1024 )
    {
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED6, HIGH);
    }
    
}

void setup()
{
  Serial.begin(9600);
}


void loop() {
  Fantacy();
  
}
