#pragma once
#include "ofxAssimpModelLoader.h"

class Platform
{
public:
	Platform();
	~Platform();
	void init();
	void platformDraw();
private:
	ofxAssimpModelLoader platform;
};

