#define LED_GREEN  2
#define SW_LEFT   12
bool red_st, green_st, yellow_st;
void setup() {
  Serial.begin(9600);
  pinMode(SW_LEFT,INPUT);
  pinMode(LED_GREEN, OUTPUT);
  digitalWrite(LED_GREEN, LOW);
  
  Serial.println("Setting ok...");
}

void loop() {
  
  if(digitalRead(SW_LEFT)== HIGH){
    digitalWrite(LED_GREEN, HIGH);
    Serial.println( " SWITCH = PRESSED  \n");
  }else{
    digitalWrite(LED_GREEN, LOW);
  }
 // delay(500);
}
