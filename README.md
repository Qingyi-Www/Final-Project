# Final-Project
**Project Purpose:**
The development of virtual reality/movie/game has ignored the feelings of disabled groups, such as the DEAF, who do not enjoy the full viewing experience and lose a large part of their immersion because they cannot hear the music.

For example, horror movies are usually much less frightening when the sound is turned off. Therefore how to make it possible for deaf people to join in the enjoyment of virtual reality/movies is also an important issue. 

Therefore, I want to make a wearable device that increases deaf people's immersion in virtual reality/movies/games through touch instead of music. My goal is not to make music audible to the deaf, but to increase the viewing experience for the blind by replacing the sense of hearing with the sense of touch

**Inspiration:** Music: Not Impossible

This project is to help deaf people experience live music.

https://www.notimpossible.com/projects/music-not-impossible#:~:text=Music%3A%20Not%20Impossible%20is%20a%20Vibrotextile%E2%84%A2%20wearable%20technology,all%20users%20a%20unique%20and%20nuanced%20music%20experience.

## Project Timeline and Milestones
## Summer work plan
### Literature reading (3 weeks)

Providing feasible support for your project based on existing articles/techniques.

Academic Paper: Write the background part of the Introduction (7.9-7.15)

**Completed:** 
1. The substitutability of auditory experiences for the blind
2. Existing substitutes (tactile, visual)
3. Several modes of tactile stimulation (vibration, pressure, heat)
4. Differences in emotions conveyed by different modes of tactile modalities.
   
   **negative emotions:** hard squeeze(also aroused emotional), brief and forcefull touch

   **positive emotions:** finger touch, slow squeeze, prolonged actions

   **How to increase the user's perception of touch:**

   Amplitude perceivable by participants. Sequential squeezes by participants. Cold was easier to notice than warmth. 
5. The effect of music on the atmosphere of a movie, the rhythmic melody of different types of music (scary music, exciting music)
   Rhythm: the basic elements of the composition, equivalent to drums.

   Melody(the most expressive of the mood) & Pitch(vibrations)：

   Sad: slow vibrations, stress (heavy tactile stimuli)

   Fear, anxious and angry: rapid vibrations, stress (heavy tactile stimuli)

   Clam: slow vibrations, light tone (light tactile stimulus) 
   
   Happy and euphoric: rapid vibrations, light tone (light tactile stimulus) 

**Unfinished:**
1. Papers related to wearable device design (for design)

### Questionnaire (half week, 7.10-7.15)
1. Does Haptics Have an Impact on Augmented Film/Virtual Reality Immersion (Yes, No)
2. If there were wearable devices that enabled vibration delivery, would people prefer one body part, or multiple? (1,2,3)
3. Does the sensation of touch vary from one body part to another? (Yes, No)
4. The parts of the body that are considered to be the most sensitive for sensing touch are (head, fingers, hand, arm, leg)
5. Academic Paper: Methodology.

### Extract audio (1/1.5 week, 7.15-7.23)
Academic Paper: Related Work, Methodology

**1. Find a short play suitable for the exhibition**

   3-4 minutes in length and with a clear change of plot (different kinds of atmospheric music shaping).

   Question: Copyright issues? Are there situations where I can use a resource for free?

**2. Plantfrom: aubio**
   
   Link: https://github.com/aubio/aubio or **rcaudio** https://github.com/mhy12345/rcaudio

### Different sensor tests (7.27-8.24)
Tests with different sensors, choose the 2-3 most suitable solutions. 

Academic Paper: Related Work, Methodology, A Project Write Up

**Vibration:**
1. Arduino Vibration Motor (SKU:RB-02S087): pure vibration, can control the time and interval of vibration (https://zhuanlan.zhihu.com/p/165207514)
2. LilyPad Vibe Board: Can be sewn into projects with conductive thread and controlled by a LilyPad Arduino (https://www.instructables.com/Arduino-) Lilypad-Slipper-Automatic-Foot-Massager/)
3. vr grip

**Squeeze:**
1. Servo motor drives the material belt spindle to rotate
Reference: [https:](https://blog.arduino.cc/2023/05/11/emoband-strokes-and-squeezes-your-wrist/)https://blog.arduino.cc/2023/05/11/emoband-strokes-and-squeezes-your-wrist/
2. Something like the Electronic Sphygmomanometer
Small air pump:
[https](https://thepihut.com/products/air-pump-and-vacuum-dc-motor-4-5v-and-1-8-lpm?variant=39823807480003&currency=GBP&utm_medium=product_sync&utm_source=google&utm_content=sag_organic&utm_campaign=sag_organic&gclid=CjwKCAjw-7OlBhB8EiwAnoOEk-Zb3UMpdbe-WMbEg1-cD3sDYEHj3bKbZNP-WBXn2U8wWIH9t2x33RoCDqQQAvD_BwE)https://thepihut.com/products/air-pump-and-vacuum-dc-motor-4-5v-and-1-8-lpm?variant=39823807480003&currency=GBP&utm_medium=product_sync&utm_source=google&utm_content=sag_organic&utm_campaign=sag_organic&gclid=CjwKCAjw-7OlBhB8EiwAnoOEk-Zb3UMpdbe-WMbEg1-cD3sDYEHj3bKbZNP-WBXn2U8wWIH9t2x33RoCDqQQAvD_BwE.

### Design (8.25-9.4)
Sketch of 1 or 3 body part wearables based on questionnaire results (with three types of sensors, assembled into one wearable or separately based on questionnaire results)
Academic Paper: Related Work, Methodology, A Project Write Up

## Autumn work plan
### Music data converted to tactile
Based on the conclusions of the pre-paper readings, the music in the film was transformed into a haptic experience through different tactile modalities and frequencies. (Will also be partially completed during **Different sensor tests** phases)

### Assemble
Assembling them after successful tests.
