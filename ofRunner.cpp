#include "ofRunner.h"



ofRunner::ofRunner()
{
}


ofRunner::~ofRunner()
{
}

void ofRunner::init()
{
	uvled.led_Init();
	_plate.plate_Init();
	model.model_Init();
	platform.init();
}
void ofRunner::findHome()
{
	if (goState == UP)
	{
		_plate.setPlate_Up();
		model.setModelUp();
		cout << "going up" << endl;
	}
	if (goState == DOWN)
	{
		_plate.setPlate_Down();
		model.setModelDown();
		cout << "going down" << endl;
	}

	tempPosition = _plate.getPlateZ();
	if (tempPosition <= homePosition)
	{

		if (needGetLastTime)
		{
			lastTime = ofGetSystemTime();
			needGetLastTime = 0;
			cout << "--------------2s start---------------" << endl;
		}
		goState = STOP;
		if (ofGetSystemTime() - lastTime >= stopTime)
		{
			needGetLastTime = 1;
			homeCount++;
			cout << "--------------2s end-----------------" << endl;
			goState = UP;
			if (homeCount == 2)
			{
				STATE = PRINTCYCLE;
				goState = DOWN;
				cout << "I got home" << endl;
			}

		}

	}
	if (tempPosition > normalHeight)
	{
		goState = DOWN;
	}
}


void ofRunner::printCycle()
{
	if (goState == UP)
	{
		_plate.setPlate_Up();
		model.setModelUp();
		cout << "going up" << endl;
	}
	if (goState == DOWN)
	{
		_plate.setPlate_Down();
		model.setModelDown();
		cout << "going down" << endl;
	}
	if (goState == STOP)
	{
		if (needGetLastTime)
		{
			lastTime = ofGetSystemTime();
			needGetLastTime = 0;
			cout << "--------------3s start---------------" << endl;
		}
		goState = STOP;
		if (ofGetSystemTime() - lastTime >= exposedTime)
		{
			needGetLastTime = 1;
			cout << "--------------3s end---------------" << endl;
			model.modelAppend();
			uvled.setLedOff();
			goState = UP;
		}

		cout << "exposing" << endl;

	}
	tempPosition = _plate.getPlateZ();
	if (goState == DOWN&&tempPosition <= minimalHeight)
	{
		uvled.setLedOn();
		goState = STOP;
	}
	if (tempPosition > normalHeight)
	{
		goState = DOWN;
	}
	if (model.getModelHeight() >= 0.1)
	{
		STATE = FINISH;
	}
}
void ofRunner::printFinish()
{
	_plate.setPlate_Up();
	model.setModelUp();
	tempPosition = _plate.getPlateZ();
	if (tempPosition >= maximalHeight)
	{
		STATE = FREE;
		std::cout << "finish" << endl;
	}
}

void ofRunner::draw()
{
	uvled.ledDraw();
	_plate.plateDraw();
	model.modelDraw();
	platform.platformDraw();
}
