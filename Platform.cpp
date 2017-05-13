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
}
void Platform::platformDraw()
{
	ofSetColor(0, 0, 0);
	platform.drawFaces();
}