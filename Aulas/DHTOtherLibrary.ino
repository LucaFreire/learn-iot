#include <DHT.h>
#include <LiquidCrystal.h>

//              D15,RX2,TX2,D18,D19,D23
LiquidCrystal lcd(19, 23, 18, 17, 16, 15);

DHT sensor(22, DHT11);

float temp, hum;
void setup() {
  lcd.begin(16,2);
  sensor.begin(); 
}

void loop() {
  temp = sensor.readTemperature();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print("C");

  hum = sensor.readHumidity();
  lcd.setCursor(0,1);
  lcd.print("Umidade: ");
  lcd.print(hum, 0);
  lcd.print("%");
}
