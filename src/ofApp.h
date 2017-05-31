#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "../uvLed.h"
#include "../plate.h"
#include "../Model.h"
#include "../Platform.h"
#include "ofLight.h"
#include "../uiControl.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		void init();
		void reset();
		void drawText();
		void findHome();
		void printCycle();
		void finish();
		void camRotate();
	
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
		uiControl gui;
		uvLed uvled;
		plate _plate;
		Model model;
		Platform platform;
		ofEasyCam cam;

		ofLight spotLight_Up,  pointLight, ledspotLight, spotLight_Down;
		int STATE=FINDHOME;
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
		int homeCount=0,goState=DOWN;
		enum goStates{DOWN,UP,GOT,STOP};
		int textState = 5;
		enum textStates{ FINDNIG_HOME,GOING_UP,GOING_DOWN, GOT_HOME, EXPOSING,null};
		float rotateAngle = 0;
};
