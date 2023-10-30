import ddf.minim.*;
import ddf.minim.analysis.*;
import ddf.minim.effects.*;
import processing.serial.*;

Minim minim;
AudioPlayer player;
AudioInput input;
FFT fft;
Serial arduinoPort;
boolean songPlaying = false;
int numLEDs = 30;  // LED灯带上的LED数量，根据实际情况调整

void setup() {
  size(800, 200);
  minim = new Minim(this);
  
  // 初始化音频输入
  input = minim.getLineIn();
  
  // 初始化FFT对象，可根据需要调整大小
  fft = new FFT(input.bufferSize(), input.sampleRate());
  
  // 初始化串口通信
  arduinoPort = new Serial(this, "/dev/cu.usbmodem14501", 9600);
  
  // 加载音频文件
  player = minim.loadFile("Controller.mp3");
}

void draw() {
  background(0);
  
  if (!songPlaying) {
    player.play();
    songPlaying = true;
  }
  
  // 更新FFT
  fft.forward(input.mix);
  
  // 计算音频振幅
  float amplitude = calculateRMS(input.mix);
  
  // 映射音量到震动效果强度
  int vibrationStrength = int(map(amplitude, 0, 0.2, 0, 255));
  
  // 打印数据
  println("Amplitude: " + amplitude + ", Vibration Strength: " + vibrationStrength);
  
  // 发送震动效果参数给 Arduino
  arduinoPort.write(vibrationStrength + "\n");
  
  // 检查音频是否已停止播放，如果是，退出应用程序
  if (!player.isPlaying()) {
    exit();
  }
}

void stop() {
  player.close();
  minim.stop();
  super.stop();
}

// 计算均方根 (RMS)
float calculateRMS(AudioBuffer buffer) {
  float sum = 0;
  for (int i = 0; i < buffer.size(); i++) {
    float sample = buffer.get(i);
    sum += sample * sample;
  }
  float rms = sqrt(sum / buffer.size());
  return rms;
}
