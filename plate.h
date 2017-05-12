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
	float getPlateHeight();
	void plateDraw();
private:
	float plateHeight;
	ofxAssimpModelLoader _plate;
};

