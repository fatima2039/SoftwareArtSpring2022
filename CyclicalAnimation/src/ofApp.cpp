#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofNoFill();
    ofSetFrameRate(15);
    ofSetBackgroundColor(0);
    
    //initialize global variables
    sphere_width = 0;
    sphere_height = ofGetHeight();
    change_width = 10;
    change_height = 5;
    initial_height = ofGetHeight();
}

//--------------------------------------------------------------
void ofApp::update(){
    //rotate anticlockwise
    if (sphere_height>0) {
        sphere_width += change_width;
        sphere_height -= change_height;
    }
    //rotate clockwise
    if (sphere_height<=0){
        sphere_width -= change_width;
        sphere_height -= change_height;
    }
    //reset parameters to give a loop effect
    if (sphere_height<= (-initial_height)) {
        sphere_width = 0;
        sphere_height = ofGetHeight();
        change_width = 10;
        change_height = 5;
        initial_height = ofGetHeight();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    //translate to center of screen
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    //rotate the sphere
    ofRotateDeg(sphere_width + ofNoise(sphere_width*10));
    
    //draw five spheres one inside another
    ofSetColor(106,50,159);
    ofDrawSphere(0, 0, 0, 100-sphere_width);
    ofSetColor(32,18,77);
    ofDrawSphere(0, 0, 0, 200-sphere_width);
    ofSetColor(103,78,167);
    ofDrawSphere(0, 0, 0, 300-sphere_width);
    ofSetColor(180,167,214);
    ofDrawSphere(0, 0, 0, 400-sphere_width);
    ofSetColor(234,209,220);
    ofDrawSphere(0, 0, 0, 500-sphere_width);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

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
