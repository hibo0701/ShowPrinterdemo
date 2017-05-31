#include "uvLed.h"

uvLed::uvLed()
{
}

uvLed::~uvLed()
{
}

void uvLed::led_Init()
{
	ledOn = false;
	uvled.loadModel("uvled.stl");
	uvled.setPosition(0,0, -100);
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
		ofSetColor(138, 43, 226);
		uvled.drawFaces();
	}
}