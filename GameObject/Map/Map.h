#pragma once
#include<string>
#include<vector>
#include "../Mob/FightableMob/FightableMob.h"
class Map:public GameObject
{
public:
	void setNextMap(Map*);
	void setPreviousMap(Map*);
	void addMonster(FightableMob*);
	Map* getNextMap();
	Map* getPreviousMap();
	vector<FightableMob*> getAllMob();
	Map();
private:
	Map *nextMap;
	Map* prevMap;
	vector<FightableMob*> mobList;
};

