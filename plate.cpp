#include "plate.h"

plate::plate()
{
}

plate::~plate()
{
}

void plate::plate_Init()
{
	_plate.loadModel("plate1.stl",20);
	_plate.setPosition(ofGetWidth()/2, ofGetHeight()/2, 0);
}

void plate::setPlate_Up()
{
	float plate_Z = getPlateHeight();
	_plate.setPosition(ofGetWidth()/2, ofGetHeight()/2, (++plate_Z)/10);
	plateHeight = plate_Z;
}

void plate::setPlate_Down()
{
	float plate_Z = getPlateHeight();
	_plate.setPosition(ofGetWidth()/2, ofGetHeight()/2, (--plate_Z)/10);
	plateHeight = plate_Z;
}

float plate::getPlateHeight()
{
	return plateHeight;
}

void plate::plateDraw()
{
	ofSetColor(255, 0, 0, 255);
	_plate.drawFaces();
}
