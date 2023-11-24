import ddf.minim.*;
import ddf.minim.analysis.*;
import ddf.minim.effects.*;
import processing.serial.*;
import processing.video.*;

Minim minim;
AudioPlayer player;
FFT fft;
Serial arduinoPort;
boolean songPlaying = false;

Movie myMovie;
int videoStartTime;
int videoDelay = 30; // 2-second frame rate at 30 fps.


void setup() {
  size(1920, 1080);
  arduinoPort = new Serial(this, "/dev/cu.usbmodem14501", 9600);
  
  minim = new Minim(this);
  player = minim.loadFile("Controller.mp3");
  fft = new FFT(1024, 44100);
  
  myMovie = new Movie(this, "nomisic.mp4");
  myMovie.play();
  videoStartTime = frameCount; // Record the number of frames at which the video starts to play
}

void draw() {
  background(0);
  // Drawing Video
  image(myMovie, 0, 0, width, height);
  
  // If the video plays for 2 seconds (60 frames * 2 seconds)
  if (frameCount - videoStartTime >= videoDelay) { 
    
  if (!songPlaying) {
    player.play();
    songPlaying = true;
  }
  

  fft.forward(player.mix);
  
  // Calculating Audio Amplitude
  float amplitude = calculateRMS(player.mix);
  // Mapping Volume to Vibration Effect Strengh
  int vibrationStrength = int(map(amplitude, 0, 0.5, 0, 255));
  //Brightness
  int blinkBrightness = int(map(amplitude, 0, 0.5, 0, 255));
  //Freqyency
  float vibrationFrequency = findDominantFrequency();

  println("Amplitude: " + amplitude + ", Vibration Strength: " + vibrationStrength + ", Vibration Frequency: " + vibrationFrequency);  
  
  // Combined: Send both vibration and blink information to Arduino
  arduinoPort.write(vibrationStrength + " " + int(vibrationFrequency) + " " + blinkBrightness + "\n");
  
  // stop
  if (!player.isPlaying()) {
    exit();
  }
 }
}

void movieEvent(Movie m) {
  m.read();
}

void stop() {
  player.close();
  minim.stop();
  super.stop();
}

// RMS
float calculateRMS(AudioBuffer buffer) {
  float sum = 0;
  for (int i = 0; i < buffer.size(); i++) {
    float sample = buffer.get(i);
    sum += sample * sample;
  }
  float rms = sqrt(sum / buffer.size());
  return rms;
}

// Calculating vibration frequency
float findDominantFrequency() {
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
