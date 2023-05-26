#include "FightController.h"

FightController* FightController::controller = nullptr;
FightController::FightController() {}
FightController* FightController::getInstance()
{
	if (controller == NULL) {
		controller = new FightController();
	}
	return controller;
}
void FightController::fight(FightableMob* m1, FightableMob* m2){
	m1->attack(m2);
}