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
private:
	ofxAssimpModelLoader model;
	float modelHeight=0;
	float modelZ=0;
};

