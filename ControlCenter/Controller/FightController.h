#pragma once
#include "../../ControlCenter/Controller.h"
#include "../../ControlCenter/ControlCenter.h"
class FightController
{
public:
	static FightController* getInstance();	
	void fight(Player*,Enemy*);
private:
	bool isPlayerTurn;
	static FightController* controller;
	FightController();	
};
