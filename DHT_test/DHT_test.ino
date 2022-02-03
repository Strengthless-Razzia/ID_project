#include "DHT.h"

#define DHTPIN 2     // Digital pin connected to the DHT sensor

#define BUTUP 4    // Digital pin connected to the pushbutton used to increment the number of people in a room
#define BUTLOW 8   // Same but decrements

#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321 --> type de capteur

DHT dht(DHTPIN, DHTTYPE);
int compteur;
int n;
int value = 0;
int nmax;
void setup() {
  Serial.begin(9600);
  Serial.println(F("Initialisation"));
  pinMode(BUTUP, INPUT);
  pinMode(BUTLOW, INPUT);
  dht.begin();
  compteur = 0;
  n = 0;
  nmax = 0;
}

void loop() {
  
  // Wait a few seconds between measurements.
  
  value = digitalRead(BUTUP);
  if(value == LOW){
    delay(10);
    compteur ++;
    if(value == LOW){
        n ++;
        delay(10);
        compteur++;
        if(n > nmax){
                  
        }
    }
  }
  value = digitalRead(BUTLOW);
  if(value == LOW){
    delay(10);
    compteur ++;
    if(value == LOW && n > 0){
        n--;
        delay(10);
        compteur++;
    }
  }
  delay(10);
  compteur ++;
  
  if(compteur%200 <1){
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)

    // Read humidity
    float h = dht.readHumidity();
    // Read temperature as Celsius (the default)
    float t = dht.readTemperature();


    // Check if any reads failed and exit early (to try again).
    if (isnan(h) || isnan(t)) {
      Serial.println(F("Failed to read from DHT sensor!"));
      return;
    }
    Serial.print(F("Humidity: "));    Serial.print(F("\n")); 

    Serial.print(h);
    Serial.print(F("%  Temperature: "));
    Serial.print(t);
    Serial.print(F("°C   "));
    Serial.print(F("Nombre de personnes dans la salle :"));
    Serial.print(n);
  }

  // Affiche le nombre max de personne qu'il y a eu en 10 s, à mettre pour 1h/ journée dans l'idée, pour avoir une idée de l'utilisation max de la salle. 
  if(compteur > 1000){
    Serial.print(F("Max de personne en 10 s :"));
    Serial.print(nmax);
    Serial.print(F("\n"));
    nmax = 0;
    compteur =0;
  }
  
  
}
