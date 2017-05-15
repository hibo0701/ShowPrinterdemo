#pragma once
#include "ofMain.h"
#include "ofxDatGui.h"

class uiControl
{
public:
	uiControl();
	~uiControl();
	void setup();
	void onButtonEvent(ofxDatGuiButtonEvent e);
	void onSliderEvent(ofxDatGuiSliderEvent e);
	//void on2dPadEvent(ofxDatGui2dPadEvent e);
	void onColorPickerEvent(ofxDatGuiColorPickerEvent e);
	ofxDatGui* gui;
	float speed=0.5;
	bool reset = false;
	bool start = false;

};

