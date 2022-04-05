#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //background and frame speed
    ofSetFrameRate(2);
    ofBackground(0, 0, 0);
    
    //gui controls
    gui.setup();
    gui.add(thickness.setup("Thickness", 1,0.1,4));
    gui.add(opacity.setup("Opacity", 150,40,255));
    gui.add(NumPolylines.setup("No. PolyLines", 1,1,10));
    gui.add(toggle.setup("Grid", true));
   
    //add points in array for grid
    for (int i=0; i<=8; i++) {
        xpoints[i] = i*ofGetWidth()/8;
        ypoints[i] = i*ofGetHeight()/8;
    }
    
    //initalize array for polylines
    lines[0] = box1;
    lines[1] = box2;
    lines[2] = box3;
    lines[3] = box4;
    lines[4] = box5;
    lines[5] = box6;
    lines[6] = box7;
    lines[7] = box8;
    lines[8] = box9;
    lines[9] = box10;
    
    
    //initialize the boundaries for each polyline for grid version
    xindex1 = (int) ofRandom(9);
    yindex1 = (int) ofRandom(9);
    xindex2 = (int) ofRandom(9);
    yindex2 = (int) ofRandom(9);
    
    xindex3 = (int) ofRandom(9);
    yindex3 = (int) ofRandom(9);
    xindex4 = (int) ofRandom(9);
    yindex4 = (int) ofRandom(9);
    
    xindex5 = (int) ofRandom(9);
    yindex5 = (int) ofRandom(9);
    xindex6 = (int) ofRandom(9);
    yindex6 = (int) ofRandom(9);
    
    xindex7 = (int) ofRandom(9);
    yindex7 = (int) ofRandom(9);
    xindex8 = (int) ofRandom(9);
    yindex8 = (int) ofRandom(9);
    
    xindex9 = (int) ofRandom(9);
    yindex9 = (int) ofRandom(9);
    xindex10 = (int) ofRandom(9);
    yindex10 = (int) ofRandom(9);
    
    xindex11 = (int) ofRandom(9);
    yindex11 = (int) ofRandom(9);
    xindex12 = (int) ofRandom(9);
    yindex12 = (int) ofRandom(9);
    
    xindex13 = (int) ofRandom(9);
    yindex13 = (int) ofRandom(9);
    xindex14 = (int) ofRandom(9);
    yindex14 = (int) ofRandom(9);
    
    xindex15 = (int) ofRandom(9);
    yindex15 = (int) ofRandom(9);
    xindex16 = (int) ofRandom(9);
    yindex16 = (int) ofRandom(9);
    
    xindex17 = (int) ofRandom(9);
    yindex17 = (int) ofRandom(9);
    xindex18 = (int) ofRandom(9);
    yindex18 = (int) ofRandom(9);
    
    xindex19 = (int) ofRandom(9);
    yindex19 = (int) ofRandom(9);
    xindex20 = (int) ofRandom(9);
    yindex20 = (int) ofRandom(9);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //stick to a part of grid for polyline
    if(toggle){
        lines[0].addVertex(ofRandom(xpoints[xindex1], xpoints[xindex2]), ofRandom(ypoints[yindex1], ypoints[yindex2]));
        
        lines[1].addVertex(ofRandom(xpoints[xindex3], xpoints[xindex4]), ofRandom(ypoints[yindex3], ypoints[yindex4]));
        
        lines[2].addVertex(ofRandom(xpoints[xindex5], xpoints[xindex6]), ofRandom(ypoints[yindex5], ypoints[yindex6]));
        
        lines[3].addVertex(ofRandom(xpoints[xindex7], xpoints[xindex8]), ofRandom(ypoints[yindex7], ypoints[yindex8]));
        
        lines[4].addVertex(ofRandom(xpoints[xindex9], xpoints[xindex10]), ofRandom(ypoints[yindex9], ypoints[yindex10]));
        
        lines[5].addVertex(ofRandom(xpoints[xindex11], xpoints[xindex12]), ofRandom(ypoints[yindex11], ypoints[yindex12]));

        lines[6].addVertex(ofRandom(xpoints[xindex13], xpoints[xindex14]), ofRandom(ypoints[yindex13], ypoints[yindex14]));

        lines[7].addVertex(ofRandom(xpoints[xindex15], xpoints[xindex16]), ofRandom(ypoints[yindex15], ypoints[yindex16]));

        lines[8].addVertex(ofRandom(xpoints[xindex17], xpoints[xindex18]), ofRandom(ypoints[yindex17], ypoints[yindex18]));

        lines[9].addVertex(ofRandom(xpoints[xindex19], xpoints[xindex20]), ofRandom(ypoints[yindex19], ypoints[yindex20]));
    }
    
    //randomize boundaries
    else{
        lines[0].addVertex(ofRandom(xpoints[(int) ofRandom(9)], xpoints[(int) ofRandom(9)]), ofRandom(ypoints[(int) ofRandom(9)], ypoints[(int) ofRandom(9)]));
        
        lines[1].addVertex(ofRandom(xpoints[(int) ofRandom(9)], xpoints[(int) ofRandom(9)]), ofRandom(ypoints[(int) ofRandom(9)], ypoints[(int) ofRandom(9)]));
        
        lines[2].addVertex(ofRandom(xpoints[(int) ofRandom(9)], xpoints[(int) ofRandom(9)]), ofRandom(ypoints[(int) ofRandom(9)], ypoints[(int) ofRandom(9)]));
        
        lines[3].addVertex(ofRandom(xpoints[(int) ofRandom(9)], xpoints[(int) ofRandom(9)]), ofRandom(ypoints[(int) ofRandom(9)], ypoints[(int) ofRandom(9)]));
        
        lines[4].addVertex(ofRandom(xpoints[(int) ofRandom(9)], xpoints[(int) ofRandom(9)]), ofRandom(ypoints[(int) ofRandom(9)], ypoints[(int) ofRandom(9)]));
        
        lines[5].addVertex(ofRandom(xpoints[(int) ofRandom(9)], xpoints[(int) ofRandom(9)]), ofRandom(ypoints[(int) ofRandom(9)], ypoints[(int) ofRandom(9)]));

        lines[6].addVertex(ofRandom(xpoints[(int) ofRandom(9)], xpoints[(int) ofRandom(9)]), ofRandom(ypoints[(int) ofRandom(9)], ypoints[(int) ofRandom(9)]));

        lines[7].addVertex(ofRandom(xpoints[(int) ofRandom(9)], xpoints[(int) ofRandom(9)]), ofRandom(ypoints[(int) ofRandom(9)], ypoints[(int) ofRandom(9)]));

        lines[8].addVertex(ofRandom(xpoints[(int) ofRandom(9)], xpoints[(int) ofRandom(9)]), ofRandom(ypoints[(int) ofRandom(9)], ypoints[(int) ofRandom(9)]));

        lines[9].addVertex(ofRandom(xpoints[(int) ofRandom(9)], xpoints[(int) ofRandom(9)]), ofRandom(ypoints[(int) ofRandom(9)], ypoints[(int) ofRandom(9)]));
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    gui.draw();
    
    for (int i=0; i<NumPolylines; i++) {
        ofSetLineWidth(thickness);
        ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255), opacity);
        lines[i].draw();
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
