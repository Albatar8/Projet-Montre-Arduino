#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_GC9A01.h>

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 240

Adafruit_GC9A01 tft = Adafruit_GC9A01(SCREEN_WIDTH, SCREEN_HEIGHT);

void setup() {
  Serial.begin(115200);

  if (!tft.begin()) {
    Serial.println("Impossible d'initialiser l'écran GC9A01. Vérifiez les connexions!");
    while (1);
  }

  tft.fillScreen(GC9A01_BLACK);
  tft.setRotation(1);  // Vous pouvez ajuster la rotation en fonction de l'orientation de votre écran

  // Affichage initial de l'heure
  afficherHeure();
}

void loop() {
  // Vous pouvez ajouter d'autres fonctionnalités ici si nécessaire
}

void afficherHeure() {
  while (1) {
    tft.fillScreen(GC9A01_BLACK);

    // Obtenez l'heure actuelle
    unsigned long currentTime = millis();
    int seconds = (currentTime / 1000) % 60;
    int minutes = (currentTime / 60000) % 60;
    int hours = (currentTime / 3600000) % 24;

    // Affichez l'heure sur l'écran
    tft.setTextSize(3);
    tft.setCursor(40, 80);
    tft.setTextColor(GC9A01_WHITE);
    tft.print(String(hours < 10 ? "0" : "") + String(hours) + ":" +
              (minutes < 10 ? "0" : "") + String(minutes) + ":" +
              (seconds < 10 ? "0" : "") + String(seconds));

    delay(1000);  // Rafraîchissez l'heure toutes les secondes
  }
}
