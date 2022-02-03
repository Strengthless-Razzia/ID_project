const int Pushbutton = 4; //bouton-poussoir connecté à la broche D4

int value = 0;     // Variable pour lire l'état du bouton-poussoir

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(F("Test"));
  pinMode (Pushbutton, INPUT); //La broche du bouton-poussoir est configurée comme entrée avec une resistance pull-up externe
}

void loop() {
  // mettre votre code principal ici, qui va s'exécuter de façon répétée:
  value = digitalRead(Pushbutton); //Lire l'état du bouton-poussoir
  if (value == HIGH) //Si le bouton est appuyé
      {
         delay(10); //10 milliseconds anti-rebond
         if (value == HIGH) //vérifier encore so le bouton est toujours appuyé
      {
          Serial.println(F("Oui"));
          delay(5000); //pause de 5 Second 
      }
      }
  Serial.println(F("\n"));
}
