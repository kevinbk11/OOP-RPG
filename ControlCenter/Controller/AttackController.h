#pragma once
#include "../../GameObject/Mob/FightableMob/Player/Player.h"
class AttackController
{
public:
	static AttackController* getInstance();
	void attack(Player*, Mob*);
	void choiceSkill(Player*);
private:
	static AttackController* controller;
	AttackController();
};
