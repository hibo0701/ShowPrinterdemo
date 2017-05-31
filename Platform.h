#pragma once
#include "ofxAssimpModelLoader.h"

class Platform
{
public:
	Platform();
	~Platform();
	void init();
	void platformDraw();
	void resinDraw();
private:
	ofxAssimpModelLoader platform;
	ofxAssimpModelLoader resin;
};

