//---- Exercise #4 : ไฟวิ่งซ้ายไปขวาและขวาไปซ้ายตลอด ระยะเวลาวิ่ง 500 ms ต่อการติดและดับ ตัวอย่างนี้ วิ่ง ซ้ายไปขวาเท่านั้น
//------- LED ขายาวคือ อาโนด นะ...
#define port_2  2
#define port_3  3
#define port_4  4
bool red_st, green_st, yellow_st;
void setup() {
  Serial.begin(9600);
  pinMode(port_2, OUTPUT);
  pinMode(port_3, OUTPUT);
  pinMode(port_4, OUTPUT);
  digitalWrite(port_2, LOW);
  digitalWrite(port_3, LOW);
  digitalWrite(port_4, LOW);
  Serial.println("Setting ok...");
}

void loop() {
  //--------- L1 on ------------
  pinMode(port_2, OUTPUT);
  digitalWrite(port_2, LOW);
  pinMode(port_3, OUTPUT);
  digitalWrite(port_3, HIGH);
  pinMode(port_4, INPUT);
  digitalWrite(port_4, LOW);
  delay(500);
  digitalWrite(port_2, LOW);
  digitalWrite(port_3, LOW);
  pinMode(port_4, OUTPUT);
  digitalWrite(port_4, LOW);
  delay(500);
  //--------- L2 on ------------
  digitalWrite(port_2, HIGH);
  digitalWrite(port_3, LOW);
  pinMode(port_4, INPUT);
  digitalWrite(port_4, LOW);
  delay(500);
  digitalWrite(port_2, LOW);
  digitalWrite(port_3, LOW);
  pinMode(port_4, OUTPUT);
  digitalWrite(port_4, LOW);
  delay(500);
  //--------- L3 on ------------
  pinMode(port_2, INPUT);
  digitalWrite(port_2, LOW);
  digitalWrite(port_3, LOW);
  digitalWrite(port_4, HIGH);
  delay(500);
  pinMode(port_2, OUTPUT);
  digitalWrite(port_2, LOW);
  digitalWrite(port_3, LOW);
  digitalWrite(port_4, LOW);
  delay(500);
  //--------- L4 on ------------
  pinMode(port_2, INPUT);
  digitalWrite(port_2, LOW);
  digitalWrite(port_3, HIGH);
  digitalWrite(port_4, LOW);
  delay(500);
  pinMode(port_2, OUTPUT);
  digitalWrite(port_2, LOW);
  digitalWrite(port_3, LOW);
  digitalWrite(port_4, LOW);
  delay(500);
  //--------- L5 on ------------
  digitalWrite(port_2, LOW);
  pinMode(port_3, INPUT);
  digitalWrite(port_3, LOW);
  digitalWrite(port_4, HIGH);
  delay(500);
  digitalWrite(port_2, LOW);
  pinMode(port_3, OUTPUT);
  digitalWrite(port_3, LOW);
  digitalWrite(port_4, LOW);
  delay(500);
  //--------- L6 on ------------
  digitalWrite(port_2, HIGH);
  pinMode(port_3, INPUT);
  digitalWrite(port_3, LOW);
  digitalWrite(port_4, LOW);
  delay(500);
  digitalWrite(port_2, LOW);
  pinMode(port_3, OUTPUT);
  digitalWrite(port_3, LOW);
  digitalWrite(port_4, LOW);
  delay(500);
 }
