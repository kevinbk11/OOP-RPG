#pragma once
#include "Controller/FightController.h"
#include "Controller/OutputController.h"
#include "Controller/AttackController.h"
class ControlCenter
{
public:
	static FightController* getFightController();
	static OutputController* getOutputController();
	static AttackController* getAttackController();
private:
	ControlCenter();
};

