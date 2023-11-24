import ddf.minim.analysis.*;
import ddf.minim.*;
import processing.serial.*;

Minim minim;
AudioPlayer soundSPlayer;
AudioPlayer soundBPlayer;
Serial arduinoPort;

void setup() {
  size(800, 200);
  minim = new Minim(this);
  soundSPlayer = minim.loadFile("sound_effect.mp3", 2048);
  soundBPlayer = minim.loadFile("background_music.mp3", 2048);
  soundSPlayer.play();
  soundBPlayer.play();
  arduinoPort = new Serial(this, "/dev/cu.usbmodem14501", 9600); 
}

void draw() {
  background(255); 

  FFT fftS = new FFT(2048, soundSPlayer.sampleRate());
  fftS.forward(soundSPlayer.mix);
  float sumAmplitudeS = 0;
  for (int i = 0; i < fftS.specSize(); i++) {
    sumAmplitudeS += fftS.getBand(i);
  }

  FFT fftB = new FFT(2048, soundBPlayer.sampleRate());
  fftB.forward(soundBPlayer.mix);
  float sumAmplitudeB = 0;
  for (int i = 0; i < fftB.specSize(); i++) {
    sumAmplitudeB += fftB.getBand(i);
  }

  int brightnessValueS = int(map(sumAmplitudeS, 0, fftS.specSize(), 0, 255));
  int brightnessValueB = int(map(sumAmplitudeB, 0, fftB.specSize(), 0, 255));
  
  println( "brightnessValueS: " + brightnessValueS + ", brightnessValueB: " + brightnessValueB);  
 
  arduinoPort.write(brightnessValueS + "," + brightnessValueB + "\n");

  if (sumAmplitudeS > 0) {
    fill(255, 225, 0); // yellow
    rect(50, 50, 50, 50); // yellow -----> Thread S's data sound is greater than 0
  } else {
    fill(255);
    rect(50, 50, 50, 50);
  }
  
  if (sumAmplitudeB > 0) {
    fill(255, 0, 0); // red
    rect(150, 50, 50, 50); // red -----> Thread B's data sound is greater than 0
  } else {
    fill(255);
    rect(150, 50, 50, 50);
  }
}
