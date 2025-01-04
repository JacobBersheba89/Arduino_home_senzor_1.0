#include <DHT.h>

#define DHTPIN 2    // Pin-číslo do kterého je připojen senzor
#define DHTTYPE DHT22 // používáme typ senzoru DHT22 -pro měření humidity

DHT dht(DHTPIN, DHTTYPE); //DHT představuje náš senzor, pro komunikaci se senzorem

void setup() {
  Serial.begin(9600); //iniciace a spuštění programu nebo spíše senzoru, bez tohto by arduino nekomunikovalo ani nevedělo co má se senzorem dělat
  dht.begin();
}

void loop() {               //loop běží stále dokola, je to k neustálému sběru dat
  float temp = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (!isnan(temp) && !isnan(humidity)) { // toto je nějaká kontrola funkčnosti,.. zda (not a number) pokud tam je chyba.. nezobrazí data
    Serial.print("Temp: "); //tyto řádky jsou pro čtění resp vypisování a zpracování dat
    Serial.print(temp);
    Serial.print(" °C, Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
  }

  delay(2000); // Zpoždění mezi měřeními
}
