const int TRIG_PIN = 6; //Chân Trig = chân 6 Uno
const int ECHO_PIN = 7; //Chân Trig = chân 7 Uno

int TIME_OUT =  5000; //convert to 5s

//Hàm tính khoảng cách cm
float countDistance(TRIG_PIN, ECHO_PIN){
  long duration, distance;
  digitalWrite(TRIG_PIN,  LOW); // Clear
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN,  HIGH); // Phát 1 xung 10 micro giây  từ chân Trig
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN,  LOW); // Clear

  // Thời gian tín hiệu phản hồi lại chân Echo
  duration = pulseIn(ECHO_PIN, HIGH, TIME_OUT);
  distance = duration / 29.1 / 2;
  return distance;// cm
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int distance;
  distance = countDistance(TRIG_PIN, ECHO_PIN);
  if(distance <= 0){
    Serial.println("Echo failed!!!");
  }
  else{
    Serial.print("Khoảng cách: ");
    Serial.println(distance);
  }
  delay(2000);
  
  
}
