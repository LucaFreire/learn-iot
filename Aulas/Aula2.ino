// Sensor de Temeperatura e humidade

#include <dht.h>

dht sensor;
int D15 = 15;

void setup() {
  Serial.begin(9600);
  delay(2000);
}
void loop() {
  sensor.read11(D15);
  Serial.print("Humidade: ");
  Serial.println(sensor.humidity);
  Serial.print("Temperatura: ");
  Serial.println(sensor.temperature, 0);
}

                                                                                                                                                                        