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
	uvled.setScale(0.1,0.1,1);
	uvled.setPosition(0,0, -200);

	spotLight.loadModel("spotLight.stl");
	spotLight.setScale(0.8, 0.5, 0.5);
	spotLight.setPosition(0, 0, 0);
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
		ofRotateX(180);
		ofSetColor(138, 43, 226,100);
		spotLight.drawFaces();
	}
}