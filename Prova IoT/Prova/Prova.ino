#include <FirebaseESP32.h>
#include <WiFi.h>
#include <dht.h>
#include <LiquidCrystal.h>

#define WIFI_SSID "Vivo-Internet-BF17"
#define WIFI_PASSWORD "78814222"

#define FIREBASE_HOST "https://prova-84054-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "av3QCOpj5Grar9gFcGs6Vv7yyKF4ns5xtsIH3TkH"

//              D15,RX2,TX2,D18,D19,D23
LiquidCrystal lcd(19, 23, 18, 17, 16, 15);


FirebaseData firebaseData;
FirebaseJson json;
dht Sensor;


int pin_Sensor = 4;
float temp;
float hum;

int led1 = 2;
int led2 = 21;
int led3 = 5;
int led4 = 13;


void setup()
{
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  lcd.begin(16, 2);

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  Firebase.setReadTimeout(firebaseData, 1000 * 60);
  Firebase.setwriteSizeLimit(firebaseData, "tiny");
}

void loop()
{
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);

  Sensor.read11(pin_Sensor);

  temp = Sensor.temperature;
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp, 0);

  hum = Sensor.humidity;
  lcd.setCursor(0, 1);
  lcd.print("Umidade: ");
  lcd.print(hum);


  if (temp <= 25)
  {
    digitalWrite(led1, HIGH);
  }
  else if (temp < 27)
  {
    digitalWrite(led2, HIGH);
  }
  else
  {
    digitalWrite(led3, HIGH);
  }

  json.set("/Temperatura", temp);
  json.set("/Umidade", hum);
  Firebase.updateNode(firebaseData, "/Freire/Sensor", json);
  digitalWrite(led4, LOW);

  delay(30000);
  digitalWrite(led4, HIGH);
  lcd.clear();
}
