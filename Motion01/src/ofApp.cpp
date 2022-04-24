#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    ofSetFrameRate(100);

    ofNoFill();
    
    //recording
//    vidRecorder.setup(true, false, glm::vec2(ofGetWidth(), ofGetHeight()));
//    vidRecorder.setOverWrite(true);
//    vidRecorder.setFFmpegPathToAddonsPath();
//    vidRecorder.setFps(60);
//    vidRecorder.setVideoCodec("prores");
//    vidRecorder.setBitRate(2000000);
    
//    recordFbo.allocate( ofGetWidth(), ofGetHeight(), GL_RGB );
    
    //theme colors selection
    ofColor themecolors[5] = {ofColor(106,50,159),ofColor(32,18,77), ofColor(103,78,167),ofColor(180,167,214), ofColor(234,209,220)};
    options[0] = themecolors[0];
    options[1] = themecolors[1];
    options[2] = themecolors[2];
    options[3] = themecolors[3];
    options[4] = themecolors[4];
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //decrease the lifespan by 1 in each frame to allow for slow fading of particles
    for(int i=0; i<lifespan.size(); i++){
        //if already 0, keep 0 so doesnt appear -> controls opacity
        if (lifespan[i]==0) {
            lifespan[i] = 0;
        }
        lifespan[i] = lifespan[i] - 1;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
//    recordFbo.begin();
//    ofClear(0,0,0,255);
//
//    //put your draw code here
//
//    recordFbo.end();
//
//
//    if (vidRecorder.isRecording()) {
//        //  ofxFastFboReader is used to speed this up :)
//        reader.readToPixels(recordFbo, recordPixels);
//
//        if (recordPixels.getWidth() > 0 && recordPixels.getHeight() > 0) {
//            vidRecorder.addFrame(recordPixels);
//        }
//    }
//
//    //need if you want to visualize your output on the screen
//    recordFbo.draw(0,0,recordFbo.getWidth(),recordFbo.getHeight());
    
    
    //each frame insert new particle
    if (ofGetFrameNum()%3==0) {
        addnewparticle(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
    }
    
    //calculate distance between two particles and make them close to each other
    for (int a=0; a<mass.size(); a++) {
        float accelerationX = 0;
        float accelerationY = 0;
        
        for (int b=0; b<mass.size(); b++) {
            if (a!=b) {
                float disX = posX[b]-posX[a];
                float disY = posY[b]-posY[a];
                
                float dis = sqrt((disX*disX) + (disY*disY));
                
                if (dis < 1) {
                    dis = 1;
                }
                
                float force = (dis-250) * (mass[b]/dis);
                accelerationX = accelerationX + (force*disX);
                accelerationY = accelerationY + (force*disY);
            }
        }
        
        velocityX[a] = (velocityX[a]*0.9) + (accelerationX*mass[a]);
        velocityY[a] = (velocityY[a]*0.9) + (accelerationY*mass[a]);
    }
    
    //draw the moving particles
    for (int c = 0; c<mass.size(); c++) {
        posX[c] = posX[c] + velocityX[c];
        posY[c] = posY[c] + velocityY[c];
        ofSetColor(color[c], lifespan[c]);
        ofDrawIcoSphere(posX[c], posY[c], mass[c]*1000);
    }
    

}

//--------------------------------------------------------------
void ofApp::addnewparticle(float x, float y){

    //size and location
    mass.push_back(ofRandom(0.003,0.03));
    posX.push_back(x);
    posY.push_back(y);
    velocityX.push_back(0);
    velocityY.push_back(0);
    
    //random color out of theme colors
    int num = int(ofRandom(5));
    color.push_back(options[num]);
    lifespan.push_back(200);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
//    if (key == 114) {
//        if (vidRecorder.isRecording()) {
//            // stop
//            cout << "STOP RECORDING.." <<endl;
//            vidRecorder.stop();
//        }
//        else {
//            cout << "START RECORDING.." <<endl;
//            ofFilePath f;
//            string myPath = f.getUserHomeDir() + "/Desktop/grab_"+ofGetTimestampString()+".mov";
//            cout << myPath << endl;
//            vidRecorder.setOutputPath(myPath);
//            vidRecorder.startCustomRecord();
//        }
//    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    addnewparticle(mouseX, mouseY);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    addnewparticle(mouseX, mouseY);
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
