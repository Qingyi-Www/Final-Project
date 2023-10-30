#include <Wire.h>
#include <Adafruit_DRV2605.h>
#include <Adafruit_NeoPixel.h>

#define LED_PIN 6  
#define LED_COUNT 30  // Number of LED strips

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_DRV2605 drv;

void setup() {
  strip.begin();
  strip.show();  // Initialize the LED strip and switch off all LEDs
  Wire.begin();
  if (!drv.begin()) {
    Serial.println("Failed to find DRV2605L, check wiring!");
    while (1);
  }
  Serial.begin(9600);  // Initialize serial communications
}

unsigned long vibrationStartTime = 0;
int vibrationDuration = 0;

void loop() {
  if (Serial.available() > 0) {
    int vibrationStrength = Serial.parseInt();
    int vibrationFrequency = Serial.parseInt();
    int brightnessValue = Serial.parseInt();

    if (vibrationStrength > 0) {
      vibrationStartTime = millis();  // 记录震动开始时间
      vibrationDuration = vibrationFrequency;  // 设置震动时长
      drv.setWaveform(0, vibrationStrength);
      drv.go();
    }

    // 控制LED亮度
    setBrightness(brightnessValue);
  }

  // 停止震动
  if (vibrationDuration > 0 && (millis() - vibrationStartTime) >= vibrationDuration) {
    drv.setWaveform(0, 0);
    drv.go();
    vibrationDuration = 0;
  }
}

void setBrightness(int brightness) {
  strip.setBrightness(brightness);
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(brightness, 0, 0)); // 设置LED颜色
  }
  strip.show();
}
