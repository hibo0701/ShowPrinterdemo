#include "Model.h"


Model::Model()
{
}
Model::~Model()
{
}

void Model::model_Init()
{
	model.loadModel("model.stl");
	model.setPosition(0, 0, modelZ);
	model.setScale(0.3, 0.3, -modelHeight);
}

void Model::modelAppend()
{
	modelHeight += 0.01;
	model.setScale(0.3, 0.3, -modelHeight);
}

void Model::setModelUp()
{
	modelZ += goSpeed;
	model.setPosition(0,0, modelZ);
}

void Model::setModelDown()
{
	modelZ -= goSpeed;
	model.setPosition(0,0, modelZ);
}

float Model::getModelHeight()
{
	return modelHeight;
}

void Model::modelDraw()
{
	ofSetColor(0, 0, 255, 255);
	model.drawFaces();
}