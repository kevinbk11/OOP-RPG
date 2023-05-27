#include "ControlCenter.h"
ControlCenter::ControlCenter() {}


FightController* ControlCenter::getFightController()
{
	return FightController::getInstance();
}
OutputController* ControlCenter::getOutputController() {
	return OutputController::getInstance();
}
AttackController* ControlCenter::getAttackController() {
	return AttackController::getInstance();
}