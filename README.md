# Final-Project - SensoryCine

## Video Link: https://youtu.be/CZowIp6P4QA

**Project Purpose:**

The development of virtual reality/movie/game has ignored the feelings of disabled groups, such as the DEAF, who do not enjoy the full viewing experience and lose a large part of their immersion because they cannot hear the music.

For example, horror movies are usually much less frightening when the sound is turned off. Therefore how to make it possible for deaf people to join in the enjoyment of virtual reality/movies is also an important issue. 

Therefore, I want to make a wearable device that increases deaf people's immersion in films through touch instead of music. My goal is not to make music audible to the deaf, but to increase the viewing experience for deaf people by replacing the sense of hearing with the sense of touch and visual

![IMG_5306 2](https://git.arts.ac.uk/storage/user/589/files/5664cc17-34b0-4843-a820-f9a1aabe4a81)

## Process:
### 1. Research (7.10-8.10)
  
   I. The substitutability of auditory experiences for the deaf

   II. Existing substitutes (tactile, visual)
   
### 2. Wrote the Introduction part of the essay: Literature Review.pdf

About the feasibility of my project, mainly including the existing research and the significance of the project. (View Literature Review.pdf)

There’s the link about my essay on Google Docs if I upload a pdf that's not easy to read: https://docs.google.com/document/d/1-iiLT-GF5E35Y-toC7YNKWTx89TsdeicaAzzfK-SBGA/edit?usp=sharing

### 3. Interview (8.10-8.20)
   I. I interviewed eight students around me with the questions in the questionnaire.pdf and I summarised each question. (see Summary and Transcript part) The questionnaire is based on the existing questionnaire model.

   Based on the interview questionnaire, I decided to design the vibration and LED strip wearable devices to be worn on on hand.

   II. The equipment needs to be rented from the school: Display, Headset, Table, Chair
In this case, it will be divided into four main viewing states, the first is to wear headphones to watch, the second is to wear wear wearable devices without headphones, the third is to wear no headphones without wearable devices to watch, and finally is to wear at the same time

### 4. Find a Video (8.20-8.27)
   I.  short film：Controller
   
   link：https://www.youtube.com/watch?v=_osh7dQa5lA

   <img width="873" alt="截屏2023-11-01 14 06 54" src="https://git.arts.ac.uk/storage/user/589/files/2d828b9d-99d6-486a-bcce-74b2f0589fce">

   II. Synopsis： Just before turning in for the night, Sarah soon finds her evening much more entertaining than anticipated. Surely cause and effect is the rational judgement? Or perhaps there is a far more whimsical reason? begging the question, who or what is the controller?

   III. 3 minutes in length and with a clear change of plot, and the music in this film is very useful and switches more frequently (e.g. sound level, type of music), which I think is a better length for the final graduation exhibition.

   The music in this film almost has the sound effect (sound from TV) but lacks music that expresses emotions. But I think that this short film without music will affect the understanding of the film, so I think that this short film can still highlight what my project is presenting

### 5. Coding Part (8.27-11.1)

In Processing (a coding software based on Java), I have completed audio analysis and transferred the data to Arduino to synchronize LED strips and a vibration motor with the music. However, the file still needs debugging because some data analysis issues have resulted in reduced precision in the vibration motor's operation after merging.

**Step 1**

Test the communication test between Arduino and Processing first, send the data to arduino using serial monitor. Input "Hello from processing" to Arduino in the processing side, after that, if Arduino recognises the data, it will turn on the LED light. (see **P-A serial communication**)

**Step 2**
The audio amplitude is calculated in Processing and the mapped LED brightness data is then transferred to the Arduino. This approach is more straightforward and simpler, as the Arduino only needs to process the simple brightness values from Processing and control the brightness of the LED strip accordingly. This makes the code on the Arduino side cleaner and makes it easier to reflect the rhythm of the music on the LED strip. (see **oneLEDstrip**)

![IMG_4976](https://git.arts.ac.uk/storage/user/589/files/9b627272-f0bc-47e1-a048-3099910bee1d)

**Step 3**
Vibration strength adjustment: int vibrationStrength = int(map(amplitude, 0, 0.5, 0, 255));

The smaller the last digit the smaller the vibration amplitude, it is not easy to feel it, but the change can be felt. The most suitable is (0, 0.5, 0, 100) (see **oneVibrationMotor**)

![IMG_5002](https://git.arts.ac.uk/storage/user/589/files/0775b217-1b8f-48cf-b0c2-b61d8d07845a)

**Step 4**
Multi-threaded exploration:
Just testing the PROCESSING multithreaded analysis first, using channel A and channel B to analyse the two audio sound_effect.mp3 and background_music.mp3 that I separated earlier, and detecting the sound values by FFT. If the sound of channel A is greater than 0, then use the draw function to draw a red rectangle; if the sound of channel A is greater than 0, then draw a yellow rectangle.（see **Multi-threaded**）

<img width="532" alt="截屏2023-11-24 18 51 11" src="https://git.arts.ac.uk/storage/user/589/files/f9ee2740-9524-4c53-a20d-22eafe32dd98">


**Step 5**
Connect more vibration motors controlled by DRV2605L. I choose to use TCA9548A for centralized control of all DRV2605L devices.

   <img width="247" alt="截屏2023-10-30 14 48 38" src="https://git.arts.ac.uk/storage/user/589/files/a311fee3-1cc9-4966-8345-93da70828a1e">
   
Adding a vibration motor to Multi-threaded and adjusting the parameters of the The vibration strengh is: the calculateRMS function calculates the RMS value of the audio buffer. vibration frequency is analysed using FFT. brightness = vibration strengh. （see **Group2**）
![IMG_5309](https://git.arts.ac.uk/storage/user/589/files/dd261a94-1e68-464e-861b-2e316ea0e801)
![IMG_5245](https://git.arts.ac.uk/storage/user/589/files/ed01f14c-dbde-4378-9df0-54967c92bbef)

**Step 6**
Cutting model with sponge and cardboard shell material, cardboard shell for device support, sponge for better user tactile feeling. Then assemble.
![IMG_5261](https://git.arts.ac.uk/storage/user/589/files/31687992-7619-43a3-85b1-025f6cf77aea)
![IMG_5260](https://git.arts.ac.uk/storage/user/589/files/650fce24-99b4-4afc-b131-10927afe3576)

   
**Step 7** Explore different kind of vibrations

Splitting the audio into sound effects and background music and use multiple channels to analyze, so that can allowed users to feel sound effects in the left hand and the background music in the right hand. (Since I don't have the original video's audio track files, I might opt to edit the background music in software like Premiere and replace it with similar sound effects. In the final exhibition will use the original video and audio files. The two audio files I use multiple channels to analyze by Processing will not be played in the exhibition.)  （see **Group3**）
![IMG_5283](https://git.arts.ac.uk/storage/user/589/files/bd286495-d6bd-46f5-9f1c-5b938deda015)

   
### 6. Write the Methodology, A Project Write Up and Evaluation of the paper.(11.1-11.20)

