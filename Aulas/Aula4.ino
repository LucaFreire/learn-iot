// Inserindo valores no Firebase \\

#include <WiFi.h>
#include <FirebaseESP32.h>
#include <dht.h>

#define WIFI_SSID "Vivo-Internet-BF17"
#define WIFI_PASSWORD "78814222"

#define FIREBASE_HOST "https://teste2-9e0e2-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "6jcl24OPxl3qtun3wfDTm6S4UW1ibPuuG1xqXKmq"

FirebaseData firebaseData;
FirebaseJson json;
dht sensor;
int D15 = 22;

void setup()
{
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  Firebase.setReadTimeout(firebaseData, 1000 * 60);
  Firebase.setwriteSizeLimit(firebaseData, "tiny");

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.begin(9600);
  
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  
  Serial.print("\nConnected with IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  sensor.read11(D15);
  json.set("/Temperatura", sensor.temperature);
  json.set("/Umidade", sensor.humidity);
  Firebase.updateNode(firebaseData, "/Freire/Sensor", json);

}