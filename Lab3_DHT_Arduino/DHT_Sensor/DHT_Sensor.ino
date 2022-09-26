#include <dht.h>
dht DHT;
//Khai báo chân Pin cho DHT11 = 4
#define DHT11_PIN 4

int PIN_LED1 = 12
int PIN_LED2 = 13

//Hàm khởi tạo
void setup()
{
//Đặt tốc độ dữ liệu = 1152000 tính bằng bit trên giây (baud) để truyền dữ liệu nối tiếp.
Serial.begin(115200);
//In ra màn hình title
Serial.println("Type\tstatus\tHumidity (%)\tTemperature (C)");
}

//Hàm lặp
void loop()
{
Serial.print("DHT11, \t");
int chk = DHT.read11(DHT11_PIN);
Serial.print(DHT.humidity, 1);
Serial.print(",\t");
Serial.println(DHT.temperature, 1);
if(DHT.temperature >= 25){
  digitalWrite(PIN_LED1, HIGH);  
}
else {
  digitalWrite(PIN_LED1, LOW);
}
if(DHT.humidity >= 50){
  digitalWrite(PIN_LED2, HIGH);
}
else {
  digitalWrite(PIN_LED2, LOW);
}
delay(2000);
}
