#include "plate.h"

plate::plate()
{
}

plate::~plate()
{
}

void plate::plate_Init()
{
	_plate.loadModel("plate.stl",20);
	_plate.setPosition(0, 0, plateZ);
	_plate.setScale(0.7, 0.7, 0.7);
}

void plate::setPlate_Up()
{
	plateZ =plateZ+goSpeed;
	_plate.setPosition(0, 0, plateZ);
}

void plate::setPlate_Down()
{
	plateZ =plateZ-goSpeed;
	_plate.setPosition(0, 0, plateZ);
}

float plate::getPlateZ()
{
	return plateZ;
}

void plate::plateDraw()
{
	ofSetColor(255, 0, 0, 255);
	_plate.drawFaces();
}
