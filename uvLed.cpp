#include "uvLed.h"

uvLed::uvLed()
{
}

uvLed::~uvLed()
{
}

void uvLed::led_Init()
{
	uvled.loadModel("uvled.stl");
	uvled.setPosition(ofGetWidth() / 2, ofGetHeight() / 2, 0);
}

void uvLed::setLedOn()
{
	ledOn = true;
}

void uvLed::setLedOff()
{
	ledOn = false;
}

bool uvLed::getLedOn()
{
	return ledOn;
}

void uvLed::ledDraw()
{
	if (ledOn)
	{
		ofSetColor(0, 255, 0, 255);
		uvled.drawFaces();
	}
}
