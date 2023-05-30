#pragma once
#include "../FightableMob.h"
#include "../../../Map/Map.h"
class Skill;
class Player:public FightableMob
{

public:
	Player(string name);
	void getAttack(DamageObject* damageObject);
	void setLocate(Map*);
	void respawn();
	Map* getLocate();
private:
	int level = 0;
	int nowExp = 0;
	int neededExp = 0;
	Map* locate = nullptr;
};

