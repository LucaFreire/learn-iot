// Inserindo valores no Firebase e acende led ao atualizar database \\

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
  pinMode(2, OUTPUT);
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

int arr[] = {sensor.temperature, sensor.humidity};

int sense = sensor.temperature;
int humid = sensor.humidity;

void loop() {
  digitalWrite(2, LOW);
  sensor.read11(D15);

  sense = sensor.temperature;
  humid = sensor.humidity;

  if (sense != arr[0] || humid != arr[1])
  {
    arr[0] = sense;
    arr[1] = humid;
    digitalWrite(2, HIGH);
  }

  json.set("/Temperatura", sense);
  json.set("/Umidade", humid);
  Firebase.updateNode(firebaseData, "/Freire/Sensor", json);
  delay(200);
}