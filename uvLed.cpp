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
	uvled.loadModel("multiLed.stl");
	uvled.setScale(1,1,1);
	uvled.setPosition(0,0, -200);

	spotLight.loadModel("uvled.stl");
	spotLight.setScale(0.85, 0.55, 65);
	spotLight.setPosition(0, 0, -195);
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
	//if (ledOn)
	//{
		ofSetColor(138, 43, 226);
		uvled.drawFaces();
	//}	
}

void uvLed::ledLightDraw()
{
	if (ledOn)
	{
		//ofRotateX(180);
		ofSetColor(138, 43, 226, 50);
		spotLight.drawFaces();
	}
}