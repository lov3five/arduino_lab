#include <AntaresESP8266MQTT.h>
#include <ArduinoJson.h>
#include <PubSubClient.h>


// Thông tin Wifi
const char* ssid_WIFI = "NameWifi";
const char* password_WIFI = "PasswordWifi";

const char* MQTT_Server = "test.mosquitto.org"; //MQTT Broker free :v

//Thông tin clientID, publishing, subcribing topic
const char* clientID = "luong_iuh";
const char* outTopic = "iotiuh/myproject";

//
WiFiClient myWifi;
//
PubSubClient client(myWifi);
char msg[50];
int count = 0;


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
