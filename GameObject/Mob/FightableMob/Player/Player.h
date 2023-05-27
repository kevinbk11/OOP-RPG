#pragma once
#include "../FightableMob.h"
#include "Skill/Skills/NormalAttack.h"
class Skill;
class Player:public FightableMob
{

public:
	Player(string name);
	void attack(Mob*);
	void getAttack(DamageObject* damageObject);
	void executeSkill(Player*,Mob*);
	void setSkillChoice(Skill*);
private:
	int level = 0;
	int nowExp = 0;
	int neededExp = 0;
	Skill *skillChoice;
};

