#include <Wire.h>
#include <Adafruit_DRV2605.h>

Adafruit_DRV2605 drv;

void setup() {
  Wire.begin();
  if (!drv.begin()) {
    Serial.println("Failed to find DRV2605L, check wiring!");
    while (1);
  }
}

unsigned long vibrationStartTime = 0;
int vibrationDuration = 0;

void loop() {
  if (Serial.available() > 0) {
    int vibrationStrength = Serial.parseInt();
    int vibrationFrequency = Serial.parseInt();

    if (vibrationStrength > 0) {
      vibrationStartTime = millis();  // 记录震动开始时间
      vibrationDuration = vibrationFrequency;  // 设置震动时长
      drv.setWaveform(0, vibrationStrength);
      drv.go();
    }
  }

  // 停止震动
  if (vibrationDuration > 0 && (millis() - vibrationStartTime) >= vibrationDuration) {
    drv.setWaveform(0, 0);
    drv.go();
    vibrationDuration = 0;
  }
}
