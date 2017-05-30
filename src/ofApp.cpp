#include "ofApp.h"
#include "Windows.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	init();
}

//--------------------------------------------------------------
void ofApp::update(){
	if (gui.start)
	{
		STATE = FINDHOME;
		gui.start = false;
		textState = FINDNIG_HOME;
	}
	if (gui.reset)
	{
		reset();
	}
	model.setSpeed(gui.speed);
	_plate.setSpeed(gui.speed);
	switch (STATE)
	{
	case FINDHOME:
		{
			findHome();
			break;
		}
	case PRINTCYCLE:
		{
			printCycle();
			break;
		}
			
	case FINISH:
		{
			finish();
			break;
		}	
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofEnableDepthTest();
	cam.begin();
	if (gui.needRotateToggle->getChecked())
	{
		rotateAngle += 0.2;
		ofRotateZ(rotateAngle);
	}
	else
	{
		rotateAngle = 0;
	}
	ofEnableLighting();
	light_Above.enable();
	
	uvled.ledDraw();
	_plate.plateDraw();
	model.modelDraw();
	platform.platformDraw();

	light_Above.disable();
	ofDisableLighting();
	cam.end();
	ofDisableDepthTest();
	ofSetColor(255, 255, 255);
	drawText();
}
//--------------------------------------------------------------
void ofApp::init()
{
	ofSetBackgroundColor(20, 20, 20);
	ofSetWindowTitle("Minifab Schematic");
	ofSetFrameRate(60);//让图形边缘平滑
	gui.setup();
	uvled.led_Init();
	_plate.plate_Init();
	model.model_Init();
	platform.init();

	STATE = STOP;
	homePosition = 50;
	tempPosition = 0;
	stopTime = 1000;
	exposedTime = 3000;
	lastTime = 0;
	needGetLastTime = 1;
	normalHeight = 100;
	minimalHeight = 0;
	maximalHeight = 300;
	homeCount = 0;
	goState = DOWN;

	cam.setDistance(800);
	cam.orbit(0, 70, cam.getDistance());
	cam.setDrag(0.5);
	ofSetVerticalSync(true);//开启垂直同步

	light_Above.setDiffuseColor(ofColor(0.f, 0.f, 255.f));
	light_Above.setSpecularColor(ofColor(255.f, 255.f, 255.f));
	light_Above.setDirectional();
	light_Above.setOrientation(ofVec3f(0, 90, 0));
}
//--------------------------------------------------------------
void ofApp::reset()
{
	gui.~uiControl();
	ofApp::setup();
	gui.reset = false;
	gui.speed = 0.5;
}
//--------------------------------------------------------------
void ofApp::drawText()
{
	ofDrawBitmapString("fps: " + ofToString(ofGetFrameRate(), 2), 10, 15);
	switch (textState)
	{
		case FINDNIG_HOME:
		{
			ofDrawBitmapString("STATE: FINDNIG HOME ", 10, 30);
			break;
		}
		case GOING_UP:
		{
			ofDrawBitmapString("STATE: GOING UP " , 10, 30);
			break;
		}
		case GOING_DOWN:
		{
			ofDrawBitmapString("STATE: GOING DOWN TO THE NEXT LAYER", 10, 30);
			break;
		}
		case GOT_HOME:
		{
			ofDrawBitmapString("STATE: GOT HOME POSITION", 10, 30);
			break;
		}
		case EXPOSING:
		{
			ofDrawBitmapString("STATE: EXPOSING NOW", 10, 30);
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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

void ofApp::findHome()
{
	if (goState == UP)
	{
		_plate.setPlate_Up();
		model.setModelUp();
	}
	if (goState == DOWN)
	{
		_plate.setPlate_Down();
		model.setModelDown();
	}

	tempPosition = _plate.getPlateZ();
	if (tempPosition <= homePosition)
	{

		if (needGetLastTime)
		{
			lastTime = ofGetSystemTime();
			needGetLastTime = 0;
		}
		goState = STOP;
		if (homeCount == 1) textState = GOT_HOME;
		if (ofGetSystemTime() - lastTime >= stopTime)
		{
			needGetLastTime = 1;
			homeCount++;
			goState = UP;
			if (homeCount == 2)
			{
				STATE = PRINTCYCLE;
				goState = DOWN;
			}

		}

	}
	if (tempPosition > normalHeight)
	{
		goState = DOWN;
	}
}
void ofApp::printCycle()
{
	if (goState == UP)
	{
		_plate.setPlate_Up();
		model.setModelUp();
		textState = GOING_UP;
	}
	if (goState == DOWN)
	{
		_plate.setPlate_Down();
		model.setModelDown();
		textState = GOING_DOWN;
	}
	if (goState == STOP)
	{
		if (needGetLastTime)
		{
			lastTime = ofGetSystemTime();
			needGetLastTime = 0;
		}
		goState = STOP;
		if (ofGetSystemTime() - lastTime >= exposedTime)
		{
			needGetLastTime = true;
			model.modelAppend();
			uvled.setLedOff();
			goState = UP;
		}

		textState = EXPOSING;

	}
	tempPosition = _plate.getPlateZ();
	if (goState == DOWN&&tempPosition <= minimalHeight)
	{
		minimalHeight += 2.5;
		uvled.setLedOn();
		goState = STOP;
	}
	if (tempPosition > normalHeight)
	{
		normalHeight += 2.5;
		goState = DOWN;
	}
	if (model.getModelHeight() >= 1)
	{
		STATE = FINISH;
	}
}
void ofApp::finish()
{
	_plate.setPlate_Up();
	model.setModelUp();
	tempPosition = _plate.getPlateZ();
	if (tempPosition >= maximalHeight)
	{
		STATE = FREE;
		MessageBox(NULL, TEXT("FINISH"), TEXT("FINISH"), MB_OK);
	}
}