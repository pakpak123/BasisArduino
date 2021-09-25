// โปรแกรมนี้มีเพิ่มการแก้ไขการ เบ้าว์ สวิทช์ ด้วย
#define LED_GREEN  2
#define LED_YELLOW 3
#define LED_RED    4
#define SW_LEFT   12
#define SW_MID    11
#define SW_RIGHT  10
bool red_st, green_st, yellow_st;
//---- debounce-------
int buttonState;
int lastButtonState = HIGH; //กำหนดให้ยังไม่กดปุ่มเป็นสถานะ HIGH
long lastDebounceTime = 0;
long debounceDelay = 50;


void setup() {
  Serial.begin(9600);
  pinMode(SW_LEFT,INPUT);
  pinMode(SW_MID,INPUT);
  pinMode(SW_RIGHT, INPUT_PULLUP);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_GREEN, LOW);
  
  Serial.println("Setting ok...");
}

void loop() {
  
  if(digitalRead(SW_RIGHT)== LOW){
    digitalWrite(LED_RED, HIGH);
    red_st = true;
    delay(1000);
    digitalWrite(LED_YELLOW, HIGH);
    yellow_st = true;
    delay(1000);
    digitalWrite(LED_GREEN, HIGH);
    green_st = true;
  }
  if(digitalRead(SW_LEFT)== HIGH){
    digitalWrite(LED_GREEN, LOW);
    green_st = false;
    delay(1000);
    digitalWrite(LED_YELLOW, LOW);
    yellow_st = false;
    delay(1000);
    digitalWrite(LED_RED, LOW);
    red_st = false;
  }
  
  //------------ debounce for SW_MID ---------
  int reading = digitalRead(SW_MID);  // <---- อ่านค่าสวิทช์

  if (reading != lastButtonState) {      // <--- หากมีการกดให้เก็บค่าเวลา ณ.ตอนนั้นไว้
    lastDebounceTime = millis();        
  }

  if ((millis() - lastDebounceTime) > debounceDelay) { //<-- ตรวจว่าเวลาเกินตั้งไว้หรือเปล่า
    if (reading != buttonState) {                     // <-- หากกดหรือปล่อยสวิทช์ ก็พิพม์ผลออกหน้าจอ
      buttonState = reading;
        Serial.print(" buttonState = ");Serial.println(buttonState);
        if(buttonState==LOW){
      Serial.print( " green_st, yellow_st, red_st = ");
    Serial.print(green_st);Serial.print(yellow_st);Serial.println(red_st);
    
    if (green_st==true){
    digitalWrite(LED_GREEN, LOW);
    green_st = !green_st;
    }else{
    digitalWrite(LED_GREEN, HIGH);
    green_st = !green_st;}
    if (yellow_st==true){
    digitalWrite(LED_YELLOW, LOW);
    yellow_st = !yellow_st;}
    else{
    digitalWrite(LED_YELLOW, HIGH);
    yellow_st = !yellow_st;}
    if (red_st==true){
    digitalWrite(LED_RED, LOW);
    red_st = !red_st;}
    else{
    digitalWrite(LED_RED, HIGH);
    red_st = !red_st;}    
        } 
     } 
    }
  lastButtonState = reading;   // <-- เอาค่าที่อ่านได้ใส่ ตัวแปรสถานะสุดท้าย
}
  
