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
private:
	bool ledOn=true;
	ofxAssimpModelLoader uvled;
};

