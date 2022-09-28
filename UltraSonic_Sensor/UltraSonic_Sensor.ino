const int TRIG_PIN = 6; //Chân Trig = chân 6 Uno
const int ECHO_PIN = 7; //Chân Trig = chân 7 Uno

int TIME_OUT =  5000; //convert to 5s
int PIN_LED1 = 12;
int PIN_LED2 = 13;

//Hàm tính khoảng cách cm
float countDistance(int triggerPin, int echoPin){
  long duration, distance;
  digitalWrite(triggerPin,  HIGH); // Phát 1 xung 10 micro giây  từ chân Trig
  delayMicroseconds(10);
  digitalWrite(triggerPin,  LOW); // Clear
  // Thời gian tín hiệu phản hồi lại chân Echo
  duration = pulseIn(echoPin, HIGH, TIME_OUT);
  distance = duration / 29.1 / 2;
  return distance;// cm
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int distance;
  distance = countDistance(TRIG_PIN, ECHO_PIN);
  if(distance <= 0){
    digitalWrite(PIN_LED1, LOW);
    digitalWrite(PIN_LED2, LOW);
    Serial.println("Echo failed!!!");
  }
  else{
    Serial.print("Khoảng cách: ");
    Serial.print(distance);
    Serial.println(" cm");
    
    if(distance >= 10){
      digitalWrite(PIN_LED2, LOW);
      digitalWrite(PIN_LED1, HIGH);
    }
    else {
      digitalWrite(PIN_LED1, LOW);
      digitalWrite(PIN_LED2, HIGH);
    }
    
  }
  
  delay(2000);
  
  
}
