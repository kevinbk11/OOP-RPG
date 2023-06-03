#pragma once
#include "../../GameObject/Mob/FightableMob/Player/Player.h"
class AttackController
{
public:
	static AttackController* getInstance();
	void attack(FightableMob*, Mob*);
	void choiceSkill(Player*);
	void choiceSkill(FightableMob*);
	void executeDamageCalculate(FightableMob*, Mob*);
private:
	static AttackController* controller;
	AttackController();
};
