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
	_plate.setPosition(0, 0, 0);
	_plate.setScale(0.7, 0.7, 0.7);
}

void plate::setPlate_Up()
{
	_plate.setPosition(0, 0, (++plateZ)/10);
}

void plate::setPlate_Down()
{
	_plate.setPosition(0, 0, (--plateZ)/10);
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
