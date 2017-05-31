#pragma once

#include "ofxAssimpModelLoader.h"

class uvLed
{
public:
	uvLed();
	~uvLed();
	void led_Init();
	void setLedOn();
	void setLedOff();
	bool getLedOn();
	void ledDraw();
	void ledLightDraw();
private:
	bool ledOn=false;
	ofxAssimpModelLoader uvled;
	ofxAssimpModelLoader spotLight;
};

