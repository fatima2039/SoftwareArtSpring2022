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
    
        //polylines
        ofPolyline box1;
        ofPolyline box2;
        ofPolyline box3;
        ofPolyline box4;
        ofPolyline box5;
        ofPolyline box6;
        ofPolyline box7;
        ofPolyline box8;
        ofPolyline box9;
        ofPolyline box10;
    
        //array to store points
        float xpoints[9];
        float ypoints[9];
    
        //gui variables
        ofxPanel gui;
        
        ofxFloatSlider thickness;
        ofxFloatSlider opacity;
        ofxIntSlider NumPolylines;
        ofxToggle toggle;
    
        //array for polylines
        ofPolyline lines[10];
        
        
        //points for grid
        int xindex1;
        int xindex2;
        int yindex1;
        int yindex2;
        
        int xindex3;
        int xindex4;
        int yindex3;
        int yindex4;
        
        int xindex5;
        int xindex6;
        int yindex5;
        int yindex6;
        
        int xindex7;
        int xindex8;
        int yindex7;
        int yindex8;
        
        int xindex9;
        int xindex10;
        int yindex9;
        int yindex10;
        
        int xindex11;
        int xindex12;
        int yindex11;
        int yindex12;
        
        int xindex13;
        int xindex14;
        int yindex13;
        int yindex14;
        
        int xindex15;
        int xindex16;
        int yindex15;
        int yindex16;
        
        int xindex17;
        int xindex18;
        int yindex17;
        int yindex18;
        
        int xindex19;
        int xindex20;
        int yindex19;
        int yindex20;
    
};
