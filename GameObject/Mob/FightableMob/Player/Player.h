#pragma once
#include "../FightableMob.h"
class Player:public FightableMob
{

public:
	Player(string name);
	void attack(Mob*);
	void getAttack(DamageObject* damageObject);
private:
	int level = 0;
	int nowExp = 0;
	int neededExp = 0;
};

