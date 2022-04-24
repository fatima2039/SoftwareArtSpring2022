#pragma once

#include "ofMain.h"
//#include "ofxFFmpegRecorder.h"
//#include "ofxFastFboReader.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        void addnewparticle(float x, float y);
    
        vector<ofColor> color;
        vector<float> mass;
        vector<float> posX;
        vector<float> posY;
        vector<float> lifespan;
        vector<float> velocityX;
        vector<float> velocityY;
        
        ofColor options[5];
    
//        ofxFFmpegRecorder vidRecorder;
//        ofFbo recordFbo;
//        ofPixels recordPixels;
//        ofxFastFboReader reader;
		
};
