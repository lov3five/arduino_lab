
/*
  A0: đầu vào của cảm biến MQ135
  A1: đầu vào của cảm biến DHT

*/
#include <MQ135.h>
#include <dht.h>

#define MQ135_Pin A0
#define DHT_Pin 4

int PIN_LED1 = 12;
int PIN_LED2 = 13;

dht DHT;
MQ135 MQ135_Sensor = MQ135(MQ135_Pin);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
  Serial.println("MQ135 Hello!!!");
}

void loop() {
  // put your main code here, to run repeatedly:
  DHT.read11(DHT_Pin);
  /*Dùng hàm humidity của thư viện DHT để nhận kết quả của độ ẩm*/
  float humidity = DHT.humidity;
  /*Dùng hàm temperature của thư viện DHT để nhận kết quả của nhiệt độ*/
  float temperature = DHT.temperature;
  Serial.println("Data of DHT11:");
  Serial.print("Độ ẩm = ");
  Serial.print(humidity);
  Serial.print("%  ");

  Serial.print("Nhiệt độ = ");
  Serial.print(temperature);
  Serial.println("*C  ");

  if (temperature >= 25) {
    digitalWrite(PIN_LED1, HIGH);
  }
  else {
    digitalWrite(PIN_LED1, LOW);
  }
  if (humidity >= 60) {
    digitalWrite(PIN_LED2, HIGH);
  }
  else {
    digitalWrite(PIN_LED2, LOW);
  }

  //Lấy hệ số trung bình của thư viện
  float rZero = MQ135_Sensor.getRZero();

  //Lấy hệ số được tính từ nhiệt độ và độ ẩm
  float correctedRZero = MQ135_Sensor.getCorrectedRZero(temperature, humidity);

  //Lấy khoảng cách tối đa mà cảm biến phát hiện ra
  float resistance = MQ135_Sensor.getResistance();

  //Đọc giá trị ppm
  float ppm = MQ135_Sensor.getPPM();

  //
  float correctedPPM = MQ135_Sensor.getCorrectedPPM(temperature, humidity);

  Serial.println("Data of MQ135:");
  Serial.print("MQ135 RZero: ");
  Serial.println(rZero);
  Serial.print("Corrected RZero: ");
  Serial.println(correctedRZero);
  Serial.print("Resistance: ");
  Serial.println(resistance);
  Serial.print("PPM: ");
  Serial.println(ppm);
  Serial.print("Corrected PPM: ");
  Serial.print(correctedPPM);
  Serial.print("ppm");

  delay(4000);
  Serial.print("\n\n");
}
