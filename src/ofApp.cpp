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
	
	ofEnableLighting();
	ofSetColor(255);
	//pointLight.draw();
	
	//spotLight_Up.draw();
	//directionLight.draw();
	camRotate();
	//pointLight.enable(); 
	spotLight_Up.enable();
	spotLight_Down.enable();

	_plate.plateDraw();
	model.modelDraw();
	platform.platformDraw();
	spotLight_Up.enable();
	spotLight_Up.disable(); 
	ofDisableLighting();
	//ofEnableLighting();
	//directionLight.enable();
	uvled.ledDraw();
	//directionLight.disable();
	//ofDisableLighting();
	platform.resinDraw();
	cam.end();
	
	ofDisableDepthTest();
	ofSetColor(0, 0, 0);
	drawText();
}
//--------------------------------------------------------------
void ofApp::init()
{
	ofSetBackgroundColor(255, 255, 255);
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
	cam.orbit(0, 50, cam.getDistance());
	cam.setDrag(0.5);
	ofSetVerticalSync(true);//开启垂直同步

	/*pointLight.setPointLight();
	pointLight.setPointLight();
	pointLight.setDiffuseColor(ofFloatColor(1.0, 1.0, 1.0));
	pointLight.setPosition(100, 0, 500);*/

	spotLight_Up.setSpotlight();
	spotLight_Up.setPosition(0, 0, 500);
	spotLight_Up.lookAt(ofPoint(0, 0, 0));
	spotLight_Up.setSpecularColor(ofFloatColor(0, 0, 1.0));
	spotLight_Up.setSpotConcentration(5.0);

	spotLight_Down.setSpotlight();
	spotLight_Down.setPosition(0, 0, -500);
	spotLight_Down.lookAt(ofPoint(0, 0, 0));
	spotLight_Down.setSpecularColor(ofFloatColor(0, 0, 1.0));
	spotLight_Down.setSpotConcentration(5.0);
	/*ledspotLight.setSpotlight();
	ledspotLight.setPosition(0, 500, 10);
	ledspotLight.lookAt(ofPoint(0, 0, -100));
	ledspotLight.setSpecularColor(ofFloatColor(1.0, 0, 0));
	ledspotLight.setSpotConcentration(5.0);*/

	/*directionLight.setPosition(0, 0, 200);
	directionLight.setDirectional();
	directionLight.setOrientation(ofPoint(0, 180, 0));
	directionLight.setSpecularColor(ofFloatColor(138.0 / 255,43.0 / 255,226.0/255));*/
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
			ofDrawBitmapString("STATE: FINDNIG HOME ", 10, 40);
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
			ofDrawBitmapString("STATE: LED ON \n       EXPOSING NOW", 10, 30);
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
void ofApp::camRotate()
{
	if (gui.needRotateToggle->getChecked())
	{
		rotateAngle += 0.2;
		ofRotateZ(rotateAngle);
	}
	else
	{
		rotateAngle = 0;
	}
}