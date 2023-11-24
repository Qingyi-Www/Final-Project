#include <Wire.h>
#include <Adafruit_DRV2605.h>
#include <Adafruit_NeoPixel.h>

#define LED_PIN 10        // Define the pin to which the NeoPixel LED strip is connected
#define NUM_LEDS 8      // Define the number of LEDs in your strip

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

Adafruit_DRV2605 drv;

void setup() {
  Wire.begin();
  if (!drv.begin()) {
    Serial.println("Failed to find DRV2605L, check wiring!");
    while (1);
  }
  Serial.begin(9600);

  // Initialize NeoPixel with the LED configuration
  strip.begin();
  strip.show();  // Initialize all pixels to 'off'

  // Initialise TCA9548
  initTCA9548(1);
  initTCA9548(3);
}


unsigned long vibrationStartTime = 0;
int vibrationDuration = 0;

void loop() {
  if (Serial.available() > 0) {
    String inputString = Serial.readStringUntil('\n');
    int spaceIndex = inputString.indexOf(' ');

    if (spaceIndex != -1) {
      String strengthString = inputString.substring(0, spaceIndex);
      inputString.remove(0, spaceIndex + 1);

      spaceIndex = inputString.indexOf(' ');
      String frequencyString = inputString.substring(0, spaceIndex);
      String brightnessString = inputString.substring(spaceIndex + 1);

      int vibrationStrength = strengthString.toInt();
      int vibrationFrequency = frequencyString.toInt();
      int brightnessValue = brightnessString.toInt();

      if (vibrationStrength > 0) {
        vibrationStartTime = millis();  // 记录震动开始时间
        vibrationDuration = 3 * 60 * 1000;   // 设置震动时长，可以根据需要调整
        
        // Choose TCA9548 channel based on vibration strength
        if (vibrationStrength > 20) {
          initTCA9548(3);
          } else if (vibrationStrength > 0 && vibrationStrength <= 20) {
            initTCA9548(1);
            }
            
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

        // LED brightness
        if (brightnessValue > 0) {
          setNeoPixelBrightness(brightnessValue);
          }else {
            // If the brightness value is 0, the light is extinguished
            setNeoPixelBrightness(0);
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

void setNeoPixelBrightness(int brightness) {
  strip.setBrightness(brightness);
  for (int i = 0; i < strip.numPixels(); i++) {
    // Keep the color constant (yellow) and adjust only the brightness
    strip.setPixelColor(i, strip.Color(255, 255, 0)); 
  }
  strip.show();
}


void initTCA9548(uint8_t channel) {
  Wire.beginTransmission(0x70);  // 设置TCA9548的I2C地址（根据硬件配置可能不同）
  Wire.write(1 << channel);     // 选择要连接的通道
  Wire.endTransmission();
}
