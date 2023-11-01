# Final-Project
**Project Purpose:**
The development of virtual reality/movie/game has ignored the feelings of disabled groups, such as the DEAF, who do not enjoy the full viewing experience and lose a large part of their immersion because they cannot hear the music.

For example, horror movies are usually much less frightening when the sound is turned off. Therefore how to make it possible for deaf people to join in the enjoyment of virtual reality/movies is also an important issue. 

Therefore, I want to make a wearable device that increases deaf people's immersion in virtual reality/movies/games through touch instead of music. My goal is not to make music audible to the deaf, but to increase the viewing experience for the blind by replacing the sense of hearing with the sense of touch

**Inspiration:** Music: Not Impossible


## Project Timeline and Milestones
### Literature reading (3 weeks)

Providing feasible support for your project based on existing articles/techniques.

Academic Paper: View Literature Review.pdf 

## Completed:
### 1. Research：
  
   I. The substitutability of auditory experiences for the deaf

   II. Existing substitutes (tactile, visual)
   
### 2. Wrote the Introduction part of the essay: Literature Review.pdf

About the feasibility of my project, mainly including the existing research and the significance of the project. (sView Literature Review.pdf)

There’s the link about my essay on Google Docs if I upload a pdf that's not easy to read: https://docs.google.com/document/d/1-iiLT-GF5E35Y-toC7YNKWTx89TsdeicaAzzfK-SBGA/edit?usp=sharing

### 3. Interview
   I. I interviewed eight students around me with the questions in the questionnaire and I summarised each question. (see Summary and Transcript part)

   Based on the interview questionnaire, I decided to design the vibration and squeeze sensors as two separate wearable devices to be worn on different parts of the user's body while watching the film (the exact position will be decided after I convert the audio into vibration).

   II. The equipment needs to be rented from the school: Display, Headset, Table, Chair
In this case, it will be divided into four main viewing states, the first is to wear headphones to watch, the second is to wear wear wearable devices without headphones, the third is to wear no headphones without wearable devices to watch, and finally is to wear at the same time

### 4. Video
   I.  short film：Controller
   
   link：https://www.youtube.com/watch?v=_osh7dQa5lA

   <img width="873" alt="截屏2023-11-01 14 06 54" src="https://git.arts.ac.uk/storage/user/589/files/2d828b9d-99d6-486a-bcce-74b2f0589fce">

   II. Synopsis： Just before turning in for the night, Sarah soon finds her evening much more entertaining than anticipated. Surely cause and effect is the rational judgement? Or perhaps there is a far more whimsical reason? begging the question, who or what is the controller?

   III. 3 minutes in length and with a clear change of plot, and the music in this film is very useful and switches more frequently (e.g. sound level, type of music), which I think is a better length for the final graduation exhibition.

   The music in this film almost has the sound effect (sound from TV) but lacks music that expresses emotions. But I think that this short film without music will affect the understanding of the film, so I think that this short film can still highlight what my project is presenting

### 5. Coding Part

In Processing (a coding software based on Java), I have completed audio analysis and transferred the data to Arduino to synchronize LED strips and a vibration motor with the music. However, the merged file still needs debugging because some data analysis issues have resulted in reduced precision in the vibration motor's operation after merging.

![WechatIMG42](https://git.arts.ac.uk/storage/user/589/files/02db0616-8da2-4af5-87c0-91e601a26b82)

Processing coding:

<img width="508" alt="截屏2023-10-30 14 18 16" src="https://git.arts.ac.uk/storage/user/589/files/24956dc4-eca4-42f3-8d92-6e650722e763">
<img width="636" alt="截屏2023-10-30 14 18 34" src="https://git.arts.ac.uk/storage/user/589/files/6916d0c0-e15a-4f89-bd1c-a5202edc6fed">
<img width="512" alt="截屏2023-10-30 14 18 42" src="https://git.arts.ac.uk/storage/user/589/files/21f90a1f-31fd-4444-9bd9-691c7fc5632d">

Arduino coding:

<img width="636" alt="截屏2023-10-30 14 15 00" src="https://git.arts.ac.uk/storage/user/589/files/575edd08-c4d5-4175-aa13-4501dc017f8a">
<img width="634" alt="截屏2023-10-30 14 15 09" src="https://git.arts.ac.uk/storage/user/589/files/bf5ddef9-8e60-40c9-aea9-fb2ac0f03f1f">

## Next to do:
### 1. Connect more controllers.
  
   Connect more vibration motors controlled by DRV2605L; here, I choose to use TCA9548A for centralized control of all DRV2605L devices.

   <img width="247" alt="截屏2023-10-30 14 48 38" src="https://git.arts.ac.uk/storage/user/589/files/a311fee3-1cc9-4966-8345-93da70828a1e">
   
### 2. Explore a wider variety of vibration patterns

Such as splitting the audio into sound effects and background music and allowing users to feel sound effects and background music separately in the left and right hands. (Since I don't have the original video's audio track files, I might opt to edit the background music in software like Premiere and replace it with similar sound effects. However, there's no need to worry about discrepancies with the original video, as the final presentation will use the original video and audio files. The two audio files I edit later are for background analysis.)

### 3. Experiment with more dynamic changes in LED strip colors.
   
### 4. Write the Methodology, A Project Write Up and Evaluation of the paper.

   I have completed the literature review and interview sections so far, as my project is still ongoing, I haven't finished the other section yet.

### 5. Assemble the wearable form
   Like a glove. I am using a total of six vibration motors controlled by controllers, and I am securing them to three fingers on each hand. Based on the interviews, fingers are more sensitive to tactile sensations, and they are also symbolically connected to the heart in Chinese culture. In my project, participants will be wearing headphones, so I cannot mount the motors on the ears. Therefore, I have chosen to design this wearable device for the hand.

   ![WechatIMG21566](https://git.arts.ac.uk/storage/user/589/files/da3932d2-e0aa-4f11-8f8e-eae29deaba32)

## Question:

 I was not able to find the DRV2605L component in Autodesk Thinkercad, so I needed to figure out how to solve this problem in order to put a clearer circuit diagram in my thesis.

 <img width="1225" alt="截屏2023-10-30 14 42 35" src="https://git.arts.ac.uk/storage/user/589/files/17abd5b7-f327-45d4-8b0c-a0a049688e16">

 <img width="329" alt="截屏2023-10-30 14 44 10" src="https://git.arts.ac.uk/storage/user/589/files/89f93441-a158-4c36-b18a-9b3afc3b9ce1">
