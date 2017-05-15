#pragma once
#include "ofxAssimpModelLoader.h"

class plate
{
public:
	plate();
	~plate();
	void plate_Init();
	void setPlate_Up();
	void setPlate_Down();
	float getPlateZ();
	void plateDraw();
	void setSpeed(float a);
private:
	float plateZ=200;
	float goSpeed = 0.5;
	ofxAssimpModelLoader _plate;
};

