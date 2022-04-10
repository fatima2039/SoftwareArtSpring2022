**Sketch 1 - Lines**

For this sketch, I divided my frame in a 8x8 grid and store the boundary points in two arrays - _xpoints_ and _ypoints._ The sketch includes 10 polylines - _box(1-10)_ which are updated to include points randomly either within the grid layout or the whole frame. These polylines are stored in an array - _lines_. The frameRate is minimized to keep the user involved enough to track the changes made based on the sliders and fully immerse themselves in artwork. Background color is black to allow for colors to pop up and clearly see the building up of the different opacities as the sketch progresses. 

Initially, the sketch displays only one polyline so the user can play around with the different gui controls and understand the algorithm better. As frame count increases and more polylines are displayed, the sketch becomes brighter and turns into a mesmerizing visual piece. Have a look at some visuals:

<img width="400" height= "400" alt="1" src="https://user-images.githubusercontent.com/72029531/161952617-84d4ad8c-1551-45fc-86bd-cb47d879a7f2.png"><img width="400" height= "400" alt="2" src="https://user-images.githubusercontent.com/72029531/161952715-752bcb33-0b0a-4d33-8573-6b695b853522.png"><img width="400" height= "400" alt="4" src="https://user-images.githubusercontent.com/72029531/161952878-c0ed1ac9-e970-4386-999d-93892c852d90.png"><img width="400" height= "400" alt="3" src="https://user-images.githubusercontent.com/72029531/161952887-60675bc7-ea24-4ffc-89fa-9c66b2c6ddff.png">

One issue that I encountered with this sketch was when the polyline is assigned the boundary points in a grid initially, sometimes, it would be linear. This would result in forming a straight line - either big or small. This would sometimes affect the overall visual aesthetic. This is something I would love to improve in the code later on. 

Check out the video of the app here: https://youtu.be/16nQDmJh5So
