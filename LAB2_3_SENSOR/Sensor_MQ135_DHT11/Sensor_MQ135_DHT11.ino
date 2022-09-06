
/*
A0: đầu vào của cảm biến MQ135
A1: đầu vào của cảm biến DHT

*/


#include <MQ135.h>
#include <dht.h>

#define MQ135_Pin A0
#define DHT_Pin A1

dht DHT;
MQ135 MQ135_Sensor = MQ135(MQ135_Pin);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("MQ135 Hello!!!");
}

void loop() {
  // put your main code here, to run repeatedly:
  DHT.read11(DHT_Pin);
  /*Dùng hàm humidity của thư viện DHT để nhận kết quả của độ ẩm*/
  float humidity = DHT.humidity;
  /*Dùng hàm temperature của thư viện DHT để nhận kết quả của nhiệt độ*/
  float temperature = DHT.temperature;
  Serial.print("Độ ẩm = ");
  Serial.print(humidity);
  Serial.print("%  ");
  
  Serial.print("Nhiệt độ = ");
  Serial.print(temperature); 
  Serial.println("*C  ");
  
  //Lấy hệ số trung bình của thư viện
  float rZero = MQ135_Sensor.getRZero();

  //Lấy hệ số được tính từ nhiệt độ và độ ẩm
  float correctedRZero = MQ135.getCorrectedRZero(temperature, humidity);

  //Lấy khoảng cách tối đa mà cảm biến phát hiện ra
  float resistance = MQ135.getResistance();

  //Đọc giá trị ppm
  //float ppm = MQ135.getPPM();

  //
  //float correctedPPM = MQ135.getCorrectedPPM(temperature, humidity);
  
  Serial.print("MQ135 RZero: ");
  Serial.print(rZero);
  Serial.print("\t Corrected RZero: ");
  Serial.print(correctedRZero);
  Serial.print("\t Resistance: ");
  Serial.print(resistance);
  /* Serial.print("\t PPM: ");
  Serial.print(ppm);
  Serial.print("\t Corrected PPM: ");
  Serial.print(correctedPPM);
  Serial.println("ppm"); */
 
  delay(500);
}
