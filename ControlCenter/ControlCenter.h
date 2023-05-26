#pragma once
#include "Controller/FightController.h"
class ControlCenter
{
public:
	static FightController* getFightController();
private:
	ControlCenter();
};

