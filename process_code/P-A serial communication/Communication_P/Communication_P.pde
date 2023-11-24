import processing.serial.*;

Serial arduinoPort;  // serial

void setup() {
  // Replace with the appropriate serial port name for your Arduino
  arduinoPort = new Serial(this, "/dev/cu.usbmodem14501", 9600);
}

void draw() {
  // send to Arduino
  arduinoPort.write("Hello from Processing!\n");
}
