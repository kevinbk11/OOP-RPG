#pragma once
#include "../../GameObject/Mob/FightableMob/Player/Player.h"
#include "../../Utils/DamageObject.h"
#include <vector>
class OutputController
{
public:
	static OutputController* getInstance();
	//void printSkillHint(std::vector<Skill>);
	void printPlayerGetAttackMessage(Player*,DamageObject*);
	/*void printMonsterGetAttackMessage();
	void printPlayerAttackMessage();
	void printMonsterAttackMeesage();*/
private:
	static OutputController* controller;
	OutputController();
};

