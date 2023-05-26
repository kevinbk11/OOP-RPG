#include "ControlCenter.h"
ControlCenter::ControlCenter() {}
FightController* ControlCenter::getFightController()
{
	return FightController::getInstance();
}