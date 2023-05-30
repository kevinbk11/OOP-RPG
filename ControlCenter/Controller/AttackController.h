#pragma once
#include "../../GameObject/Mob/FightableMob/Player/Player.h"
class AttackController
{
public:
	static AttackController* getInstance();
	void attack(Player*, Mob*);
	void attack(FightableMob*, Player*);
	void choiceSkill(Player*);
	void choiceSkill(FightableMob*);
private:
	static AttackController* controller;
	AttackController();
};
