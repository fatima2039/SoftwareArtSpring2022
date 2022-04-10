#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //background
    ofBackground(0);
    ofEnableSmoothing();
    
    //gui
    gui.setup();
    gui.add(shapes.setup("No# shapes", 10, 1, 20));
    gui.add(lines.setup("No# lines per shape", 500, 0, 1000));
    gui.add(themes.setup("Color Palette", int(ofRandom(1,5)), 1, 5));
    gui.add(label1.setup("Palette 1", "City Sunset"));
    gui.add(label2.setup("Palette 2", "Grey Contrast"));
    gui.add(label3.setup("Palette 3", "Moonlight"));
    gui.add(label4.setup("Palette 4", "Dirty Pinks"));
    gui.add(label5.setup("Palette 5", "Cappuccino"));
    
    
    //colors - color-hex palette inspiration
    ofColor color[5][5] = {/*city sunset colors*/{ofColor(238,175,97),ofColor(251,144,98), ofColor(238,93,108),ofColor(206,73,147), ofColor(106,13,131)}, /*grey contrast colors*/ {ofColor(0, 176, 197),ofColor(9, 232, 222), ofColor(221, 223, 227),ofColor(128, 128, 128), ofColor(94, 94, 94)}, /*moonlight colors*/{ofColor(106,50,159),ofColor(32,18,77), ofColor(103,78,167),ofColor(180,167,214), ofColor(234,209,220)}, /*dirty pinks*/ {ofColor(208,178,166),ofColor(221,146,151), ofColor(226,187,189),ofColor(91,81,77), ofColor(251,245,238)}, /*cappuccino*/{ofColor(81,59,20),ofColor(133,68,66), ofColor(255,244,230),ofColor(60,47,47), ofColor(190,155,123)}};
    
    
    
    //add colors to an array
    for (int j=0; j<5; j++) {
        for (int i=0; i<5; i++) {
            colors[j][i] = color[j][i];
        }
    }
    
    //for every shape
    for (int j=0; j<20; j++) {
        
        float xcenter = ofRandom(ofGetWidth());
        float ycenter = ofRandom(ofGetHeight());
        noise_xloc = ofRandom(20);
        noise_yloc = ofRandom(20);
        noise_angle = ofRandom(20);
        noise_radius = ofRandom(20);
        angle = -PI/2;
        
        //for every line in a single shape
        for (int i=0; i<1000; i++) {
            //change radius using perlin noise
            noise_radius += 0.005;
            radius = (ofNoise(noise_radius)*500) + 1;
            
            //use noise to calculate angular movement
            noise_angle += 0.005;
            angle += (ofNoise(noise_angle)*6) - 3;
            if (angle>360) {
                angle -= 360;
            }
            if (angle<0) {
                angle +=360;
            }
            
            //location of lines
            noise_yloc += 0.01;
            noise_xloc += 0.01;
            float centerX = xcenter + (ofNoise(noise_xloc) * 100) - 50;
            float centerY = ycenter + (ofNoise(noise_yloc) * 100) - 50;
            float radius1 = ofDegToRad(angle);
            float x1 = centerX + (radius * cos(radius1));
            float y1 = centerY + (radius * sin(radius1));
            xloc1[j][i] = x1;
            yloc1[j][i] = y1;
            float radius2 = radius1 + PI;
            float x2 = centerX + (radius * cos(radius2));
            float y2 = centerY + (radius * sin(radius2));
            xloc2[j][i] = x2;
            yloc2[j][i] = y2;
            
            
            //opacity of a single line
            opacity[j][i] = ofRandom(0,30);
        }
    }
    
    //color index of every shape
    for (int i=0; i<shapes; i++) {
        shapecolor[i] = int(ofRandom(5));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    gui.draw();
    
    ofSetLineWidth(1);
    for (int j=0; j<shapes; j++) {
        ofColor col = colors[themes-1][shapecolor[j]];
        for (int i= 0; i<lines; i++) {
            ofSetColor(col,opacity[j][i]);
            ofDrawLine(xloc1[j][i], yloc1[j][i], xloc2[j][i], yloc2[j][i]);
        }
    }
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
