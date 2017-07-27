#include <DHT.h>
#define DHTPIN D1
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

int obs=D5;
int led=D2;
int count=0;

void setup() {
  pinMode(obs,INPUT);
  pinMode(led,OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
    int res=digitalRead(obs);
  
  Serial.println(res);
  if(res==1){
    
    Serial.println("Obstacle detected..");
    digitalWrite(led,HIGH);

    Serial.print("count: ");
    count++;
  Serial.println(count);
  delay(2000);

  float temperature, humidity;

  temperature = dht.readTemperature();
  humidity = dht.readHumidity();

  Serial.print("Temperature: ");
  Serial.println(temperature);
  Serial.print("Humidity: ");
  Serial.println(humidity);

  delay(1000);
  } else {
  
    Serial.println("Obstacle not detected..");
    digitalWrite(led,LOW);
  }

  

}
