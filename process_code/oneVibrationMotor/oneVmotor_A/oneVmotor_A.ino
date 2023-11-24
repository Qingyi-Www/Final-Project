#include <Wire.h>
#include <Adafruit_DRV2605.h>

Adafruit_DRV2605 drv;

void setup() {
  Wire.begin();
  if (!drv.begin()) {
    Serial.println("Failed to find DRV2605L, check wiring!");
    while (1);
  }
  Serial.begin(9600);
}

unsigned long vibrationStartTime = 0;
int vibrationDuration = 0;

void loop() {
  if (Serial.available() > 0) {
    // Read serial port data
    String inputString = Serial.readStringUntil('\n');
    int spaceIndex = inputString.indexOf(' ');

    if (spaceIndex != -1) {
      
      // Separation of Vibration Strengh and Frequency
      String strengthString = inputString.substring(0, spaceIndex);
      String frequencyString = inputString.substring(spaceIndex + 1);

      int vibrationStrength = strengthString.toInt();
      int vibrationFrequency = frequencyString.toInt();

      if (vibrationStrength > 0) {
        vibrationStartTime = millis();  // Record the start time of the vibration
        vibrationDuration = vibrationFrequency;  // set the vibration duration
        
        // Selection of Waveforms according to Frequency
        if (vibrationFrequency < 2000) {
          // strong click -30%
          drv.setWaveform(3, vibrationStrength);
        } else if (vibrationFrequency < 5000) {
          // strong click -60%
          drv.setWaveform(2, vibrationStrength);
        } else {
          // strong click -100%
          drv.setWaveform(1, vibrationStrength);
        }
        drv.go();
      }
    }
  }

  // stop
  if (vibrationDuration > 0 && (millis() - vibrationStartTime) >= vibrationDuration) {
    drv.setWaveform(0, 0);
    drv.go();
    vibrationDuration = 0;
  }
}
