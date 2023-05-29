#pragma once
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
