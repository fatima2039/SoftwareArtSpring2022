#pragma once

#include "ofMain.h"
#include "ofxGui.h"

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
        
        //functions that allow drawing a new shapes
        //and display all the previous ones in order of drawn
        void showprevious();
        void drawshapes();
    
        //font
        ofTrueTypeFont myfont;
        ofTrueTypeFont myfont2;
        ofTrueTypeFont myfont3;
    
        //GUI
        ofxPanel gui;
        ofxColorSlider brushcolor;
        ofxFloatSlider coloropacity;
        ofxLabel label7;
        ofxLabel label1;
        ofxLabel label2;
        ofxLabel label3;
        ofxLabel label4;
        ofxFloatSlider brushsize;
    
        //time
        float timestarted;
        float currenttime;
    
        //variables
        vector<float> locX;
        vector<float> locY;
        vector<float> shapeSize;
        vector<ofColor> shapeColor;
        vector<float> shapeOpacity;
        vector<int> toolNum;
        int Brushtype;
        int choice;
		
        //images
        ofImage img1;
        ofImage img2;
        ofImage img3;
    
        //sound
        ofSoundPlayer mysound1;
        //ofSoundPlayer mysound2;
};
