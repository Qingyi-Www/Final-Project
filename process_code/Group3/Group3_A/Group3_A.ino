#include <Wire.h>
#include <Adafruit_DRV2605.h>
#include <Adafruit_NeoPixel.h>

Adafruit_DRV2605 drvS;  // Sound effect
Adafruit_DRV2605 drvB;  // Background music

#define LED_PIN_1 10  // NeoPixel LED 1
#define LED_COUNT_1 8  
#define LED_PIN_2 8   // NeoPixel LED 2
#define LED_COUNT_2 8  
#define LED_BRIGHTNESS 255

Adafruit_NeoPixel strip1(LED_COUNT_1, LED_PIN_1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2(LED_COUNT_2, LED_PIN_2, NEO_GRB + NEO_KHZ800);

void setup() {
  Wire.begin();
  if (!drvS.begin()) {
    Serial.println("Failed to find DRV2605L for sound effect, check wiring!");
    while (1);
  }

  if (!drvB.begin()) {
    Serial.println("Failed to find DRV2605L for background music, check wiring!");
    while (1);
  }

  // Initialize serial communication
  Serial.begin(9600);

  // Initialize NeoPixel with the LED configuration
  strip1.begin();
  strip1.setBrightness(LED_BRIGHTNESS);
  strip1.show();  // initialisation

  strip2.begin();
  strip2.setBrightness(LED_BRIGHTNESS);
  strip2.show();  // initialisation

  // Initialize TCA9548, select channels
  initTCA9548(1);
  initTCA9548(2); 
  initTCA9548(3);
  initTCA9548(6); 
  initTCA9548(7);  
}

void initTCA9548(uint8_t channel) {
  Wire.beginTransmission(0x70);  // Set the I2C address of TCA9548 (may vary based on hardware configuration)
  Wire.write(1 << channel);     // Select the channel to connect
  Wire.endTransmission();
}

unsigned long vibrationStartTimeS = 0;
unsigned long vibrationStartTimeB = 0;
int vibrationDurationS = 0;
int vibrationDurationB = 0;
float vibrationFrequencyS = 0;
float vibrationFrequencyB = 0;

void loop() {
  if (Serial.available() > 0) {
    String inputString = Serial.readStringUntil('\n');
    int commaIndex = inputString.indexOf(',');

    if (commaIndex != -1) {
      // data of soundS
      String data1 = inputString.substring(0, commaIndex);
      int spaceIndex1 = data1.indexOf(' ');
      int vibrationStrengthS = data1.substring(0, spaceIndex1).toInt();
      int vibrationFrequencyS = data1.substring(spaceIndex1 + 1).toInt();
      int brightnessS = vibrationFrequencyS;

      // data of soundB
      String data2 = inputString.substring(commaIndex + 1);
      int spaceIndex2 = data2.indexOf(' ');
      int vibrationStrengthB = data2.substring(0, spaceIndex2).toInt();
      int vibrationFrequencyB = data2.substring(spaceIndex2 + 1).toInt();
      int brightnessB = vibrationStrengthB;

    if (vibrationStrengthS > 0) {
      vibrationStartTimeS = millis();  // Record vibration start time
      vibrationDurationB = 3 * 60 * 1000; // Set vibration duration based on frequency
        
      // Choose TCA9548 channel based on VibrationStrengthS
      if (vibrationStrengthS > 20) {
        initTCA9548(3);
        } else if (vibrationStrengthS > 0 && vibrationStrengthS <= 20) {
          initTCA9548(1);
          }

            // Selection of Waveforms according to Frequency
            if (vibrationFrequencyS < 5000) {
              // pulsing click -60%
              drvS.setWaveform(53, vibrationStrengthS);
              } else {
                  // pulsing click -100%
                  drvS.setWaveform(52, vibrationStrengthS);
                  }
                  drvS.go();
                  }               
       // LED1 brightness
       if (brightnessS > 0) {
         setBrightnessS(brightnessS);
         }else {
           // If the brightness value is 0, the light is extinguished
           setBrightnessS(0);
           }


    if (vibrationStrengthB > 0) {
      vibrationStartTimeB = millis();  // Record vibration start time
      vibrationDurationB = 3 * 60 * 1000;  // Set vibration duration based on frequency
      
      // Choose TCA9548 channel based on VibrationStrengthS
      if (vibrationStrengthB > 20) {
        initTCA9548(7);
        } else if (vibrationStrengthB > 10 && vibrationStrengthB <= 20) {
          initTCA9548(6);
          } else if (vibrationStrengthB > 0 && vibrationStrengthB <= 10) {
            initTCA9548(2);
            }
            // Selection of Waveforms according to Frequency
            if (vibrationFrequencyB < 2000) {
              // strong click -30%
              drvB.setWaveform(3, vibrationStrengthB);
              } else if (vibrationFrequencyB < 5000) {
                // strong click -60%
                drvB.setWaveform(2, vibrationStrengthB);
                } else {
                  // strong click -100%
                  drvB.setWaveform(1, vibrationStrengthB);
                  }
                  drvB.go();
                  } 
       // LED1 brightness
       if (brightnessB > 0) {
         setBrightnessB(brightnessB);
         }else {
           // If the brightness value is 0, the light is extinguished
           setBrightnessB(0);
           }
  }
} 
  // Stop vibration
  stopVibrationIfNeeded(1, vibrationStartTimeS, vibrationDurationS, drvS);
  stopVibrationIfNeeded(2, vibrationStartTimeB, vibrationDurationB, drvB);
  stopVibrationIfNeeded(3, vibrationStartTimeS, vibrationDurationB, drvS);
  stopVibrationIfNeeded(6, vibrationStartTimeB, vibrationDurationS, drvB);
  stopVibrationIfNeeded(7, vibrationStartTimeB, vibrationDurationB, drvB);
}

// Stop vibration
void stopVibrationIfNeeded(uint8_t channel, unsigned long startTime, int &duration, Adafruit_DRV2605 &drv) {
  if (duration > 0 && (millis() - startTime) >= duration) {
    // Close TCA9548 channel
    initTCA9548(channel);
    // Stop vibration
    drv.setWaveform(0, 0);
    drv.go();
    // Reset vibration parameters
    duration = 0;
    startTime = 0;
  }
}


void setBrightnessS(int brightnessS) {
  strip1.setBrightness(brightnessS);
  for (int i = 0; i < strip1.numPixels(); i++) {
    strip1.setPixelColor(i, strip1.Color(255, 0, 0)); // red
  }
  strip1.show();
}

void setBrightnessB(int brightnessB) {
  strip2.setBrightness(brightnessB);
  for (int i = 0; i < strip2.numPixels(); i++) {
    strip2.setPixelColor(i, strip2.Color(255, 255, 0)); // yellow
  }
  strip2.show();
}
