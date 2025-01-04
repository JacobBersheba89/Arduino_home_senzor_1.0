#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_AM2320.h>

// Inicializace senzoru
Adafruit_AM2320 am2320 = Adafruit_AM2320();

void setup() {
  Serial.begin(9600);
  Serial.println("Inicializace AM2320...");

  // Kontrola připojení senzoru
  if (!am2320.begin()) {
    Serial.println("Nepodařilo se inicializovat senzor AM2320! Zkontrolujte zapojení.");
    while (1);
  }
}

void loop() {
  // Čtení teploty a vlhkosti
  float temperature = am2320.readTemperature();
  float humidity = am2320.readHumidity();

  if (!isnan(temperature) && !isnan(humidity)) {
    Serial.print("Teplota: ");
    Serial.print(temperature);
    Serial.println(" °C");
    Serial.print("Vlhkost: ");
    Serial.print(humidity);
    Serial.println(" %");
  } else {
    Serial.println("Chyba při čtení dat ze senzoru!");
  }

  delay(2000); // Interval měření
}
