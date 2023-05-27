#pragma once
#include "../../Utils/Calculator/DamageCalculator.h"
#include "../../GameObject/Mob/FightableMob/Player/Player.h"
class FightController
{
public:
	static FightController* getInstance();	
	void fight(Player*,FightableMob*);
private:
	bool isPlayerTurn;
	static FightController* controller;
	FightController();	
};

