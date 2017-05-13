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
	model.setPosition(0, 0, 0);
}

void Model::modelAppend()
{
	modelHeight += 0.1;
	model.setScale(1, 1, modelHeight);
}

void Model::setModelUp()
{
	model.setPosition(0,0, (++modelZ)/10);
}

void Model::setModelDown()
{
	model.setPosition(0,0, (--modelZ)/10);
}

void Model::modelDraw()
{
	ofSetColor(0, 0, 255, 255);
	model.drawFaces();
}