import ddf.minim.*;
import ddf.minim.analysis.*;
import ddf.minim.effects.*;
import processing.serial.*;

Minim minim;
AudioPlayer player;
FFT fft;
Serial arduinoPort;
boolean songPlaying = false;

void setup() {
  size(800, 200);
  minim = new Minim(this);

  fft = new FFT(1024, 44100);
  arduinoPort = new Serial(this, "/dev/cu.usbmodem14501", 9600);
  
  // Load the audio file
  player = minim.loadFile("Controller.mp3");
}

void draw() {
  background(0);
  
  if (!songPlaying) {
    player.play();
    songPlaying = true;
  }
  
  // Update FFT
  fft.forward(player.mix);
  
  // Calculate audio amplitude
  float amplitude = calculateRMS(player.mix);
  
  // Map volume to vibration strength
  int vibrationStrength = int(map(amplitude, 0, 0.5, 0, 255));
  
  // Find the dominant frequency
  float dominantFrequency = findDominantFrequency();
  
  // Print data
  println("Vibration Strength: " + vibrationStrength + ", Dominant Frequency: " + dominantFrequency);
  
  // Send vibration strength and frequency to Arduino
  arduinoPort.write(vibrationStrength + " " + int(dominantFrequency) + "\n");
  
  // stop playing ---> exit
  if (!player.isPlaying()) {
    exit();
  }
}

void stop() {
  player.close();
  minim.stop();
  super.stop();
}

// Calculate Root Mean Square (RMS)
float calculateRMS(AudioBuffer buffer) {
  float sum = 0;
  for (int i = 0; i < buffer.size(); i++) {
    float sample = buffer.get(i);
    sum += sample * sample;
  }
  float rms = sqrt(sum / buffer.size());
  return rms;
}

// Find the dominant frequency using FFT
float findDominantFrequency() {
  fft.forward(player.mix);
  float[] spectrum = fft.getSpectrumReal();
  int maxIndex = 0;
  float maxAmplitude = 0;
  for (int i = 0; i < spectrum.length; i++) {
    if (spectrum[i] > maxAmplitude) {
      maxAmplitude = spectrum[i];
      maxIndex = i;
    }
  }
  float frequency = maxIndex * player.sampleRate() / fft.getBandWidth();
  return frequency;
}
