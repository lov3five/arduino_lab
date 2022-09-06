#include <dht.h>

#define dht_apin A0

dht DHT;

void setup(){
  Serial.begin(9600);
  delay(500);
  /*Khởi chạy kiểm tra Serial monito*/
  Serial.println("DHT11\n\n");
  delay(1000); 
}

void loop(){
  /*Dùng read11 của thư viện DHT để đọc đầu vào A0*/
  DHT.read11(dht_apin);
  Serial.print("Độ ẩm = ");
  /*Dùng hàm humidity của thư viện DHT để nhận kết quả của độ ẩm*/
  Serial.print(DHT.humidity);
  Serial.print("%  ");
  Serial.print("Nhiệt độ = ");
  /*Dùng hàm temperature của thư viện DHT để nhận kết quả của nhiệt độ*/
  Serial.print(DHT.temperature); 
  Serial.println("C  ");
  /*Lặp mỗi 5 giây sẽ gửi về kết quả 1 lần*/
  delay(5000);
}
