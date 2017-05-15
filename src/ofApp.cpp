#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(20, 20, 20);
	ofSetWindowTitle("Minifab Schematic");
	ofSetFrameRate(60);//让图形边缘平滑

	uvled.led_Init();
	_plate.plate_Init();
	model.model_Init();
	platform.init();

	cam.setDistance(800);
	
	cam.orbit(0, 70, cam.getDistance());	
	cam.setDrag(0.5);
	ofEnableDepthTest();
	//ofVec3f point=ofVec3f(0, 0, 0);
	//cam.lookAt(point);
	//ofSetVerticalSync(true);//开启垂直同步
	
}

//--------------------------------------------------------------
void ofApp::update(){
	
	_plate.setPlate_Up();
	model.setModelUp();
	//model.modelAppend();

	//uvled.setRotation(1, 270 + ofGetElapsedTimef() * 60, 0, 0, 1);
}

//--------------------------------------------------------------
void ofApp::draw(){
	cam.begin();

	uvled.ledDraw();
	_plate.plateDraw();
	model.modelDraw();
	platform.platformDraw();

	cam.end();
	ofSetColor(255, 255, 255);
	ofDrawBitmapString("fps: " + ofToString(ofGetFrameRate(), 2), 10, 15);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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