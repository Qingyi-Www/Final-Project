const int ledPin = 13;  // LED connected to pin 13 on Arduino
const int blinkDuration = 1000;  // Duration of each blink (milliseconds)
const int totalBlinks = 5;  // Total number of blinks

unsigned long previousMillis = 0;  // Time of the previous blink
int blinkCount = 0;  // Number of blinks so far

void setup() {
  Serial.begin(9600);  // Initialize serial communication with a baud rate of 9600
  pinMode(ledPin, OUTPUT);  // Set pin 13 as an output
}

void loop() {
  unsigned long currentMillis = millis();  // Get the current time

  if (Serial.available() > 0) {
    // Read the received data and check if it is "Hello from Processing!\n"
    String receivedData = Serial.readStringUntil('\n');
    if (receivedData == "Hello from Processing!") {
      // If the specified message is received, blink the LED
      if (blinkCount < totalBlinks) {
        // Check if a blink is needed
        if (currentMillis - previousMillis >= blinkDuration) {
          previousMillis = currentMillis;
          blinkLED();
          blinkCount++;
        }
      }
    }
  }
}

void blinkLED() {
  digitalWrite(ledPin, HIGH);  // Turn on the LED
  delay(blinkDuration / 2);  // Wait for half of the duration
  digitalWrite(ledPin, LOW);  // Turn off the LED
  delay(blinkDuration / 2);  // Wait for half of the duration
}
