#pragma once
#include<string>
#include<vector>
#include "../Mob/FightableMob/Enemy/Enemy.h"
#include "../NPC/NPC.h"
class NPC;
class Map:public GameObject
{
public:
	void setNextMap(Map*);
	void setPreviousMap(Map*);
	void addMonster(Enemy*);
	void addNPC(NPC*);
	Map* getNextMap();
	Map* getPreviousMap();
	vector<NPC*> getAllNPC();
	vector<Enemy*> getAllMob();
	Map();
private:
	Map *nextMap;
	Map* prevMap;
	vector<Enemy*> mobList;
	vector<NPC*> NPCList;
};

