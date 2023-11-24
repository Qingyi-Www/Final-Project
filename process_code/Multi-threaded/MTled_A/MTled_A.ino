#include <Adafruit_NeoPixel.h>

#define LED_PIN_1 10  // NeoPixel LED 1
#define LED_COUNT_1 8  

#define LED_PIN_2 8   // NeoPixel LED 2
#define LED_COUNT_2 8  

#define LED_BRIGHTNESS 255

Adafruit_NeoPixel strip1(LED_COUNT_1, LED_PIN_1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2(LED_COUNT_2, LED_PIN_2, NEO_GRB + NEO_KHZ800);

void setup() {
  strip1.begin();
  strip1.setBrightness(LED_BRIGHTNESS);
  strip1.show();  // initialisation

  strip2.begin();
  strip2.setBrightness(LED_BRIGHTNESS);
  strip2.show();  // initialisation

  Serial.begin(9600);  
}

void loop() {
  if (Serial.available() > 0) {
    int brightnessValueS = Serial.parseInt();
    int brightnessValueB = Serial.parseInt();

    // Processing the values of brightnessValueS and brightnessValueB
    setBrightnessS(brightnessValueS);
    setBrightnessB(brightnessValueB);
  }
}

void setBrightnessS(int brightnessS) {
  strip1.setBrightness(brightnessS);
  for (int i = 0; i < strip1.numPixels(); i++) {
    strip1.setPixelColor(i, strip1.Color(255, 255, 0)); // yellow
  }
  strip1.show();
}

void setBrightnessB(int brightnessB) {
  strip2.setBrightness(brightnessB);
  for (int i = 0; i < strip2.numPixels(); i++) {
    strip2.setPixelColor(i, strip2.Color(255, 0, 0)); // red
  }
  strip2.show();
}
