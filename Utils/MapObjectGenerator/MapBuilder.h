#pragma once
#include "../../GameObject/Map/Map.h"
#include "../../GameObject/Mob/FightableMob/Enemy/Enemy.h"
#include "../../GameObject/NPC/NPCs/Villager.h"
class MapBuilder
{
public:
	MapBuilder* setMonster(Enemy*);
	MapBuilder* setName(string);
	MapBuilder* setNPC(NPC*);
	MapBuilder();
	Map* createMap();
private:
	Map* map=nullptr;
};

