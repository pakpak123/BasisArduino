int buttonState;
int lastButtonState = LOW;   // กำหนดให้สถานะ สวิทช์ ปกติยังไม่กดปุ่มเป็นสถานะ LOW
long lastDebounceTime = 0;
long debounceDelay = 50;

#define buttonPin 12

void setup(){
  Serial.begin(9600);
  pinMode(buttonPin, INPUT); 
}
void loop(){                             // <--- วงลูปตลอดไป
  int reading = digitalRead(buttonPin);  // <---- อ่านค่าสวิทช์

  if (reading != lastButtonState) {      // <--- หากมีการกดให้เก็บค่าเวลา ณ.ตอนนั้นไว้
    lastDebounceTime = millis();        
  }

  if ((millis() - lastDebounceTime) > debounceDelay) { //<-- ตรวจว่าเวลาเกินตั้งไว้หรือเปล่า
    if (reading != buttonState) {                     // <-- หากกดหรือปล่อยสวิทช์ ก็พิพม์ผลออกหน้าจอ
      buttonState = reading;
       // แสดงผลการกด
        //  Serial.print(" buttonState ");Serial.println(buttonState);
      
       if (buttonState == 1)
        Serial.println(" SWITCH PREESSED \n");
        else
         Serial.println(" SWITCH RELEASE \n");
        
       
      }
    }
    
  lastButtonState = reading;   // <-- เอาค่าที่อ่านได้ใส่ ตัวแปรสถานะสุดท้าย

}
