import ddf.minim.analysis.*;
import ddf.minim.*;
import processing.serial.*;

Minim minim;
AudioPlayer jingle;
FFT fft;
Serial arduinoPort;
int numLEDs = 30;  // Number of LEDs on the LED strip

void setup() {
  size(800, 200);
  arduinoPort = new Serial(this, "/dev/cu.usbmodem14501", 9600);
  
  minim = new Minim(this);
  jingle = minim.loadFile("Controller.mp3", 2048);
  jingle.play();
  fft = new FFT(2048, jingle.sampleRate());
}

void draw() {
  background(0);
  
  if (!jingle.isPlaying()) {
    println("Audio playback finished.");
    noLoop();
  }
  
  fft.forward(jingle.mix);
  
  // Calculating Audio Amplitude
  float sumAmplitude = 0;
  for (int i = 0; i < fft.specSize(); i++) {
    sumAmplitude += fft.getBand(i);
  }
  
  // Calculating LED Brightness
  int brightnessValue = int(map(sumAmplitude, 0, fft.specSize(), 0, 255));
  
  // Send brightness value to Arduino
  arduinoPort.write(brightnessValue + "\n");
}
