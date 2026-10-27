#include "DHTesp.h"

const int DHT_PIN = 13;
DHTesp dht;

void setup() {
  Serial.begin(115200);
  dht.setup(DHT_PIN, DHTesp::DHT22);
  Serial.println("Smart IoT Environmental Monitoring System");
}

void loop() {
  TempAndHumidity data = dht.getTempAndHumidity();

  if (isnan(data.temperature) || isnan(data.humidity)) {
    Serial.println("Sensor reading failed");
  } else {
    Serial.print("Temperature: ");
    Serial.print(data.temperature);
    Serial.println(" C");

    Serial.print("Humidity: ");
    Serial.print(data.humidity);
    Serial.println(" %");
  }
 {  
if (data.temperature > 30) {
  Serial.println("WARNING: High Temperature!");
} else {
  Serial.println("Temperature is Normal");
}
{ 
  if (data.humidity > 70) {
  Serial.println("WARNING: High Humidity!");
} else {
  Serial.println("Humidity is Normal");
}
}
 }
  delay(2000);
}