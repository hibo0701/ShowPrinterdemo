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
private:
	float plateZ=200;
	float goSpeed = 1;
	ofxAssimpModelLoader _plate;
};

