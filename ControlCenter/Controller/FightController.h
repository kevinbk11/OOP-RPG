#pragma once
#include <cstddef>
#include "../../GameObject/Mob/FightableMob/FightableMob.h"
#include "../../Utils/Calculator/DamageCalculator.h"
class FightController
{
public:
	static FightController* getInstance();
	void fight(FightableMob*,FightableMob*);
private:
	static FightController* controller;
	FightController();
};

