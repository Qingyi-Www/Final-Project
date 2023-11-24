import ddf.minim.*;
import ddf.minim.analysis.*;
import ddf.minim.effects.*;
import processing.serial.*;
import processing.video.*;

Minim minim;
AudioPlayer soundSPlayer;  // sound_effect.mp3
AudioPlayer soundBPlayer;  // background_music.mp3
Serial arduinoPort;
boolean songPlaying = false;

Movie myMovie;
int videoStartTime;
int videoDelay = 30; // 2-second frame rate at 30 fps.


void setup() {
  size(1920, 1080);
  minim = new Minim(this);
  soundSPlayer = minim.loadFile("sound_effect.mp3", 2048);
  soundBPlayer = minim.loadFile("background_music.mp3", 2048);
  soundSPlayer.play();
  soundBPlayer.play();
  arduinoPort = new Serial(this, "/dev/cu.usbmodem14501", 9600); 
  
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
      soundSPlayer.play();
      soundBPlayer.play();
      songPlaying = true;
    }
  

  // Processing soundSPlayer's RMS and FFT 
  float amplitudeS = calculateRMS(soundSPlayer.mix);
  int vibrationStrengthS = int(map(amplitudeS, 0, 0.2, 0, 255));
  float vibrationFrequencyS = findDominantFrequency(soundSPlayer, new FFT(2048, soundSPlayer.sampleRate()));

  // Processing soundBPlayer's RMS and FFT 
  float amplitudeB = calculateRMS(soundBPlayer.mix);
  int vibrationStrengthB = int(map(amplitudeB, 0, 0.2, 0, 255));
  float vibrationFrequencyB = findDominantFrequency(soundBPlayer, new FFT(2048, soundBPlayer.sampleRate()));
    
  println("Vibration StrengthB: " + vibrationStrengthB + ", Vibration FrequencyB: " + vibrationFrequencyB + ", Vibration StrengthS: " + vibrationStrengthS + ", Vibration FrequencyS: " + vibrationFrequencyS);

  // send information to Arduino
  arduinoPort.write(vibrationStrengthS + " " + int(vibrationFrequencyS) + "," + vibrationStrengthB + " " + int(vibrationFrequencyB) + "\n");

  // stop
  if (!soundSPlayer.isPlaying() && !soundBPlayer.isPlaying()) {
    exit();
  }
}
}

void movieEvent(Movie m) {
  m.read();
}

void stop() {
  soundSPlayer.close();
  soundBPlayer.close();
  minim.stop();
  super.stop();
}

// Calculate the root mean square (RMS) value of the audio buffer
float calculateRMS(AudioBuffer buffer) {
  float sum = 0;
  for (int i = 0; i < buffer.size(); i++) {
    float sample = buffer.get(i);
    sum += sample * sample;
  }
  float rms = sqrt(sum / buffer.size());
  return rms;
}

// Get the dominant frequency of a specified audio using FFT
float findDominantFrequency(AudioPlayer player, FFT fft) {
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
  return maxIndex * fft.getBandWidth();
}
