#include <Adafruit_NeoPixel.h>

#define LED_PIN 6  
#define LED_COUNT 30  // Number of LED strips

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();  // Initialize the LED strip
  Serial.begin(9600);  
  
}


void loop() {
  if (Serial.available() > 0) {
    int brightnessValue = Serial.parseInt();
    setBrightness(brightnessValue);
  }
}

void setBrightness(int brightness) {
  strip.setBrightness(brightness);
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(brightness, 0, 0)); // LED color
  }
  strip.show();
}
