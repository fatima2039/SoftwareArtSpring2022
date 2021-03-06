**180 SECONDS DRAWING CHALLENGE**

Everyone loves a challenge and it can not ever get better when there is room for creativity in a challenge. With this idea in mind, I decided to make my final assignment a drawing challenge. The app user is given three minutes to recreate an image that is displayed. The images are pretty simple and drawn out of basic shapes (circle, square, triangle, rectangles) originally. There are three images stored in the system and each time the app is run, it selects one out of random. In order to recreate the image, the app user is provided with four kinds of brushes: circle, square, triangle, and eraser. As the name suggests, these brushes will draw the named shape on the plain white background with the exception of the eraser brush. The eraser brush draws a circle with white fil on a white background so it gives an illusion of erasing anything on the screen. Additionally, there is a GUI that can be used to control different parameters of the brushes. Users can adjust the color, size, and color opacity of the brushes using the respective sliders on GUI. The app loads with the default brush selected as the eraser one. Users can switch between the brushes using number keys where the application is as follows:

Num key 1: Circle Brush

Num key 2: Square Brush

Num key 3: Triangle Brush

Num key 4: Eraser Brush

Check out the app layout in these pictures:

<img width="45%" alt="Screenshot 2022-05-09 at 10 37 57 AM" src="https://user-images.githubusercontent.com/72029531/167353838-6e728268-99d7-4863-bf50-b0f896e202d1.png"> 
<img width="45%" alt="Screenshot 2022-05-09 at 10 38 08 AM" src="https://user-images.githubusercontent.com/72029531/167353854-6d5b6b82-a6f4-4d74-8074-398284acd974.png">
<img width="45%" alt="Screenshot 2022-05-09 at 10 38 44 AM" src="https://user-images.githubusercontent.com/72029531/167353864-40778079-6ebd-4d3a-ac32-30e057b047be.png">
<img width="42%" alt="Screenshot 2022-05-09 at 10 29 16 AM" src="https://user-images.githubusercontent.com/72029531/167353202-57fb7c2d-e1bb-4b0b-b388-ca0b426603a0.png"> 
<img width="42%" alt="Screenshot 2022-05-09 at 10 32 31 AM" src="https://user-images.githubusercontent.com/72029531/167353217-fa1f6f71-0e6c-49c9-8d0b-4aae28ae5a40.png">



To implement the above-described app, I declared multiple vectors such as _locX, locY, shapeSize, shapeColor, shapeOpacity,_ and _toolNum_. These vectors will store information about the mouseX location, mouseY location, the brush size, shape color, color opacity, and brush number selected each time the mouse is pressed and/or dragged. In order of being drawn, these will be displayed by drawing out different shapes as per the brush selected and the other parameters adjusted by the GUI. At the start, there is a title screen followed by an instruction screen and then the user has 3 minutes to recreate the image displayed in the upper right corner chosen at random. All the images are resized in the _setup()_ to display exactly the same each time the app is loaded. The switching of the screen is controlled by having a global timer. The _timestarted_ stores the seconds when the app is executed and in each iteration of _draw()_, _currenttime_ is also retrieved. The difference between them is calculated and is used as a timer to display texts, and images and draw on-screen at appropriate times. Towards the last 10 seconds, the font size of the timer at the bottom is increased and the color is changed to red. At the start, a background sound is also loaded and continues until the user???s 180 seconds are finished. After 180 seconds, the _mousePressed()_ and _mouseDragged()_ no longer work and the user is displayed its final progress. 

Coding this app has been a very fun experience. Trying out the different functions resulted in me spending so much time trying to complete the challenge. Initially, the timer was set for 2 minutes and after about 20 failed attempts, I decided to increase it to 3 minutes. Still could not create a decent recreation but I am pretty sure some fast user is able to make it in time or at least make it a very interesting recreation. During the implementation, I ran into several issues with displaying images and loading sounds. I was able to figure out the image displaying errors through the online forums. However, the sound issue still remains. I wanted to play two sounds, background music that stops before the last 10 seconds of the drawing and a timer sound that plays for the last 10 seconds. When both loaded, the background music does stop when intended but the timer would not play. Trying to work around the code did not work either. So I decided to create another sound by merging silent audio for the part when background music is playing and playing timer sound in the last 10 seconds. I tried playing them together and that did not work either. Finally, I decided to stick with background music for the whole duration.

The development of this seemingly _simple_ app allowed me to learn so much about coding practices. I was able to learn how innovative ways of problem-solving could result in simpler code and easier implementation. Additionally, debugging errors with the help of existing information on forums allowed me to learn so much about different ways to approach a problem and so many new functionalities and possibilities in openFrameworks. 

Watch me struggle to complete the challenge here: https://youtu.be/IBbKBEAL6f4
