#pragma once
#include "ofxAssimpModelLoader.h"

class Model
{
public:
	Model();
	~Model();
	void model_Init();
	void modelAppend();
	void setModelUp();
	void setModelDown();
	void modelDraw();
	float getModelHeight();
	void setSpeed(float a);
private:
	ofxAssimpModelLoader model;
	float modelHeight=0;
	float modelZ=200;
	float goSpeed = 0.5;
};

