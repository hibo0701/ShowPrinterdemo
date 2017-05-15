#pragma once
#include "ofMain.h"
#include "uvLed.h"
#include "plate.h"
#include "Model.h"
#include "Platform.h"
#include "ofLight.h"


class ofRunner
{
public:
	ofRunner();
	~ofRunner();
	void init();
	void findHome();
	void printCycle();
	void printFinish();
	void draw();
private:
	uvLed uvled;
	plate _plate;
	Model model;
	Platform platform;
	ofEasyCam cam;
	ofLight light_Above;
	int STATE;
	enum STATE { FINDHOME, PRINTCYCLE, FINISH, FREE };
	float homePosition = 50;
	float tempPosition = 0;
	float stopTime = 1000;
	float exposedTime = 3000;
	float lastTime = 0;
	bool needGetLastTime = 1;
	float normalHeight = 100;
	float minimalHeight = 0;
	float maximalHeight = 230;
	int homeCount = 0, goState = 0;
	enum goState { DOWN, UP, GOT, STOP };
};

