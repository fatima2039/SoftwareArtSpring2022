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
        
    
        float noise_angle;
        float noise_radius;
        float noise_xloc;
        float noise_yloc;
        float angle;
        float radius;
        int colorchoice;
        bool isDrawGui;
    
        ofxPanel gui;
        ofxLabel label6;
        ofxLabel label7;
        ofxIntSlider shapes;
        ofxIntSlider lines;
        ofxIntSlider themes;
        ofxLabel label1;
        ofxLabel label2;
        ofxLabel label3;
        ofxLabel label4;
        ofxLabel label5;
        ofxButton save;
    
    
        float xloc1[20][1000];
        float yloc1[20][1000];
        float xloc2[20][1000];
        float yloc2[20][1000];
    
        int shapecolor[20];
    
        
        float opacity[20][1000];
    
        ofColor colors[5][5];
            
    
    
};
