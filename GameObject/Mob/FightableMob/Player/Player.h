#pragma once
#include<iostream>
#include "../FightableMob.h"

using namespace std;
class Player:public FightableMob
{

public:
	Player(string name);
	void attack(FightableMob*);
	void getAttack(DamageObject* damageObject);
private:
	int level = 0;
	int nowExp = 0;
	int neededExp = 0;
};

