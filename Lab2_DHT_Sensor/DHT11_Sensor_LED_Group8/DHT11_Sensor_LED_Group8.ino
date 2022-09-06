#include <dht.h>

#define dht_apin A0
int ledDo = 7;
int ledXanh = 6;
int ledVang = 5;

dht DHT;

void setup(){
  Serial.begin(9600);
  pinMode(ledDo, OUTPUT);
  pinMode(ledXanh, OUTPUT);
  pinMode(ledVang, OUTPUT);
  /*Khởi chạy kiểm tra Serial monito*/
  Serial.println("DHT11\n\n");
  delay(1000); 
}

void loop(){
  /*Dùng read11 của thư viện DHT để đọc đầu vào A0*/
  DHT.read11(dht_apin);
  float nhietdo = DHT.temperature;
  Serial.print("Nhiệt độ = ");
  /*Dùng hàm temperature của thư viện DHT để nhận kết quả của nhiệt độ*/
  Serial.print(nhietdo); 
  Serial.println("C  ");
  /*Lặp mỗi 5 giây sẽ gửi về kết quả 1 lần*/
  if(nhietdo < 20){
    digitalWrite(ledDo, LOW);
    digitalWrite(ledXanh, HIGH);
    digitalWrite(ledVang, LOW);
  } else if(nhietdo <= 27){
    digitalWrite(ledDo, LOW);
    digitalWrite(ledXanh, LOW);
    digitalWrite(ledVang, HIGH);
  } else if(nhietdo > 27){
    digitalWrite(ledDo, HIGH); 
    digitalWrite(ledXanh, LOW);
    digitalWrite(ledVang, LOW);
  } else {
    digitalWrite(ledDo, LOW);  
    digitalWrite(ledXanh, LOW);
    digitalWrite(ledVang, LOW);
  }
  delay(2000);
}
