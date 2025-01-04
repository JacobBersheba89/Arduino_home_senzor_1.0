#define ANALOG_PIN A0  // Pin připojený k analogovému výstupu senzoru
#define DIGITAL_PIN 2  // Pin připojený k digitálnímu výstupu senzoru

void setup() {
  Serial.begin(9600);
  pinMode(DIGITAL_PIN, INPUT);  // Nastavení digitálního pinu jako vstupu
  Serial.println("Půdní vlhkoměr připraven...");
}

void loop() {
  // Čtení z digitálního výstupu
  int digitalValue = digitalRead(DIGITAL_PIN);

  // Čtení z analogového výstupu
  int analogValue = analogRead(ANALOG_PIN);

  // Interpretace digitálního výstupu
  if (digitalValue == HIGH) {
    Serial.println("Půda je suchá!");
  } else {
    Serial.println("Půda je vlhká!");
  }

  // Interpretace analogového výstupu
  float moisturePercent = map(analogValue, 1023, 0, 0, 100);  // Převedení na % vlhkosti
  Serial.print("Analogová hodnota: ");
  Serial.print(analogValue);
  Serial.print(" -> Vlhkost: ");
  Serial.print(moisturePercent);
  Serial.println(" %");

  delay(2000);  // Interval měření
}
