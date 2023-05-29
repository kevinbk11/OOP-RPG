#pragma once
#include "../FightableMob.h"
#include "../../../Map/Map.h"
class Skill;
class Player:public FightableMob
{

public:
	Player(string name);
	void attack(Mob*);
	void getAttack(DamageObject* damageObject);
	void executeSkill(Player*,Mob*);
	void setSkillChoice(Skill*);
	void setLocate(Map*);
	Map* getLocate();
private:
	int level = 0;
	int nowExp = 0;
	int neededExp = 0;
	Skill *skillChoice=nullptr;
	Map* locate = nullptr;
};

