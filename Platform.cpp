#include "Platform.h"



Platform::Platform()
{
}

Platform::~Platform()
{
}

void Platform::init()
{
	platform.loadModel("platform.stl");
	platform.setPosition(0, 0, 0);
	resin.loadModel("uvLed.stl");
	resin.setScale(0.8, 0.5, 8);
	resin.setPosition(0, 0, 0);
}
void Platform::platformDraw()
{
	ofSetColor(0, 0, 0);
	platform.drawFaces();
}

void Platform::resinDraw()
{
	ofSetColor(0,255,0,100);
	resin.drawFaces();
}