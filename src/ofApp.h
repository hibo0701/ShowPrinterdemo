#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "../uvLed.h"
#include "../plate.h"
#include "../Model.h"
#include "../Platform.h"
#include "ofLight.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
private:
		uvLed uvled;
		plate _plate;
		Model model;
		Platform platform;
		ofEasyCam cam;
		ofLight light_Above;
		int STATE;
		enum STATE { FINDHOME, PRINTCYCLE, FINISH,FREE };
		float homePosition=50;
		float tempPosition=0;
		float stopTime=1000;
		float exposedTime=3000;
		float lastTime=0;
		bool needGetLastTime=1;
		float normalHeight=100;
		float minimalHeight=0;
		float maximalHeight=300;
		int homeCount=0,goState=0;
		enum goState{DOWN,UP,GOT,STOP};

};
