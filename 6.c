// Include necessary libraries
#include <DHT.h>

// Define the pin and type of DHT sensor
#define DHTPIN 2       // DHT11 sensor connected to digital pin 2
#define DHTTYPE DHT11  // DHT11 sensor type

// Initialize the DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Start serial communication for output
  Serial.begin(9600);
  Serial.println("DHT11 Sensor Test");

  // Start the DHT sensor
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements
  delay(2000);

  // Read humidity
  float humidity = dht.readHumidity();
  
  // Read temperature in Celsius
  float temperatureC = dht.readTemperature();

  // Read temperature in Fahrenheit
  float temperatureF = dht.readTemperature(true);

  // Check if any reads failed and exit loop if so
  if (isnan(humidity) || isnan(temperatureC) || isnan(temperatureF)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print the results to the Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.print(" °C ");
  Serial.print(temperatureF);
  Serial.println(" °F");
}
