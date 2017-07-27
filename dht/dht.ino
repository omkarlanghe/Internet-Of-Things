#include <DHT.h>
#define DHTPIN D1
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
}

void loop() {
  float temperature, humidity;

  temperature = dht.readTemperature();
  humidity = dht.readHumidity();

  Serial.print("Temperature: ");
  Serial.println(temperature);
  Serial.print("Humidity: ");
  Serial.println(humidity);

  delay(1000);
}
