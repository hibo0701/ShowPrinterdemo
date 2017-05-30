#include "uiControl.h"

uiControl::uiControl()
{
}
void uiControl::setup()
{
	gui = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT);
	gui->addHeader("CONTROL PANEL");
	gui->addSlider("MOVE SPEED", 0, 5, 0.5);
	gui->addButton("START");
	gui->addColorPicker("BACKGROUND");
	//gui->add2dPad("MACHINE POSITION");
	needRotateToggle = gui->addToggle("ROTATE", false);
	gui->addButton("RESET");
	gui->addFooter();
	gui->onButtonEvent(this, &uiControl::onButtonEvent);
	gui->onSliderEvent(this, &uiControl::onSliderEvent);
	//gui->on2dPadEvent(this, &uiControl::on2dPadEvent);
	gui->onColorPickerEvent(this, &uiControl::onColorPickerEvent);
	gui->setOpacity(.5);
}

uiControl::~uiControl()
{
	delete gui;
}

void uiControl::onButtonEvent(ofxDatGuiButtonEvent e)
{
	if (e.target->getLabel() == "RESET")
	{
		reset = true;
	}
	if (e.target->getLabel() == "START")
	{
		start = true;
	}
}
void uiControl::onSliderEvent(ofxDatGuiSliderEvent e)
{
	if (e.target->getLabel() == "MOVE SPEED")
	{
		speed=e.target->getValue();
	}
}
void uiControl::onToggleEvent(ofxDatGuiToggleEvent e)
{
	
}
//void uiControl::on2dPadEvent(ofxDatGui2dPadEvent e)
//{
//
//}
void uiControl::onColorPickerEvent(ofxDatGuiColorPickerEvent e)
{
	if (e.target->getLabel() == "BACKGROUND") {
		ofSetBackgroundColor(e.target->getColor());
	}
}

