#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //background
    ofBackground(255);
    
    //timer to control the transitions
    timestarted = ofGetElapsedTimef();
    
    //defaults for color, images and their resizing
    ofColor defaultColor(255,0,0);
    ofRectMode(CENTER);
    Brushtype=4;
    img1.load("image1.png");
    img2.load("image2.png");
    img3.load("image3.png");
    img1.resize(409.6, 307.2);
    img2.resize(409.6, 307.2);
    img3.resize(409.6, 307.2);
    
    //gui
    gui.setup();
    gui.add(brushcolor.setup("Brush Color",
                             defaultColor,
                             ofColor(0, 0),
                             ofColor(255, 255)));
    gui.add(coloropacity.setup("Color Opacity", 100, 0, 255));
    gui.add(label7.setup("Press corresponding key", ""));
    gui.add(label1.setup("Circle Brush", "1"));
    gui.add(label2.setup("Square Brush", "2"));
    gui.add(label3.setup("Triangle Brush", "3"));
    gui.add(label4.setup("Eraser Brush", "4"));
    gui.add(brushsize.setup("Brush Size", 10, 0, 200));
    
    //font loading
    myfont.load("ZakirahsBold.ttf", 60);
    myfont2.load("ZakirahsCasual.ttf", 25);
    myfont3.load("ZakirahsCasual.ttf", 12);
    
    //sound loading
    mysound1.load("background.mp3");
    //mysound2.load("timerfull.mp3");
    
    //start background sound
    mysound1.play();
    //mysound2.play();
    
    //to allow for random display of image to recreate
    choice = int(ofRandom(1,3));
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //get current time
    currenttime = ofGetElapsedTimef();
    
    //display main intro
    if (currenttime-timestarted<4) {
        ofSetColor(0);
        myfont.drawString("180 Seconds", ofGetWidth()/3, ofGetHeight()/2.25);
        myfont.drawString("\nDrawing Challenge", ofGetWidth()/4, ofGetHeight()/2.25);
    }
    
    //display instructions
    if (currenttime-timestarted>4 && currenttime-timestarted<9) {
        ofSetColor(0);
        myfont2.drawString("Recreate your version of image on right corner", ofGetWidth()/3.9, ofGetHeight()/2);
        myfont2.drawString("\nUse different keys to select brushes", ofGetWidth()/3.5, ofGetHeight()/2);
        
    }
    
    //allow for drawing the shapes and recreating the image
    if (currenttime-timestarted>9 && currenttime-timestarted<129) {
        //display existing saved shapes
        showprevious();
        
        //save the shape only if mouse pressed
        if (ofGetMousePressed()==true) {
            drawshapes();
        }
        
        //stop background sound
//        if (currenttime-timestarted>118) {
//            mysound1.stop();
//        }
        
        //display timer
        char fpsStr[255]; // an array of chars
        sprintf(fpsStr, "Remaining seconds: %f", 189-currenttime-timestarted);
        if (currenttime-timestarted>9 && currenttime-timestarted<179) {
            ofSetColor(0);
            myfont3.drawString(fpsStr, ofGetWidth()/2.5,ofGetHeight()*0.97);
        }
        if (currenttime-timestarted>179 && currenttime-timestarted<189) {
            ofSetColor(255,0,0);
            myfont2.drawString(fpsStr, ofGetWidth()/2.9,ofGetHeight()*0.97);
        }
        
        
        //draw gui
        ofSetColor(0);
        ofDrawRectangle(0, 0, gui.getWidth()+9, gui.getHeight()+9);
        gui.draw();
        ofSetColor(255);
        
        //display the image to be recreated on right top corner
        if (choice==1) {
            img1.draw(ofGetWidth()-420, 10);
        }
        if (choice==2) {
            img2.draw(ofGetWidth()-420, 10);
        }
        if (choice==3) {
            img3.draw(ofGetWidth()-420, 10);
        }
        
    }
    
    //stop allowing for changes/ edits and display times up screen
    if (currenttime-timestarted>=189) {
        if (currenttime-timestarted>189) {
            mysound1.stop();
        }
        ofSetColor(255, 255, 255);
        ofDrawRectangle(0, 0, gui.getWidth()+9, gui.getHeight()+9);
        showprevious();
        ofSetColor(0, 255);
        myfont.drawString("Times Up", ofGetWidth()/2.5, ofGetHeight()/2);
    }
    
    
}

//--------------------------------------------------------------
void ofApp::drawshapes(){
    
    //save the shape dimension and paramters adjusted using gui
    float size = brushsize;
    locX.push_back(ofGetMouseX());
    locY.push_back(ofGetMouseY());
    shapeSize.push_back(brushsize);
    
    //save the shape type to allow to easier display later
    if (Brushtype == 1 || Brushtype == 2 || Brushtype == 3 ) {
        shapeColor.push_back(brushcolor);
        shapeOpacity.push_back(coloropacity);
    }
    if (Brushtype == 1) {
        toolNum.push_back(1);
    }
    else if (Brushtype == 2){
        toolNum.push_back(2);
    }
    else if (Brushtype == 3){
        toolNum.push_back(3);
    }
    
    //eraser tool specifications -
    //white circle to imitate eraser function on white background
    else if (Brushtype == 4){
        toolNum.push_back(4);
        shapeOpacity.push_back(255);
        shapeColor.push_back(ofColor(255,255,255));
    }
}

//--------------------------------------------------------------
void ofApp::showprevious(){

    //for all the shapes already stored, draw based on type and dimensions saved
    for (int i=0; i<shapeSize.size(); i++) {
        ofSetColor(shapeColor[i],shapeOpacity[i]);
        if (toolNum[i]==1) {
            ofDrawCircle(locX[i], locY[i], shapeSize[i]);
        }
        else if (toolNum[i]==2) {
            ofDrawRectangle(locX[i], locY[i], shapeSize[i], shapeSize[i]);
        }
        else if (toolNum[i]==3) {
            ofDrawTriangle(locX[i], locY[i], locX[i]-shapeSize[i], locY[i], locX[i], locY[i]-shapeSize[i]);
        }
        else if (toolNum[i]==4){
            ofDrawCircle(locX[i], locY[i], shapeSize[i]);
        }
    }
}
                       
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    //1 for circle
    if (key==49) {
        Brushtype=1;
        
    }
    
    //2 for square
    else if (key==50) {
        Brushtype=2;
    }
    
    //3 for triangle
    else if (key==51) {
        Brushtype=3;
    }
    
    //4 for eraser
    else if (key==52) {
        Brushtype=4;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    //only allow for drawing in specificed time
    if (currenttime-timestarted>9 && currenttime-timestarted<189){
        drawshapes();
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    //only allow for drawing in specificed time
    if (currenttime-timestarted>9 && currenttime-timestarted<189){
        drawshapes();
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
