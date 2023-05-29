#pragma once
#include "../../GameObject/Map/Map.h"
#include "../../GameObject/Mob/FightableMob/FightableMob.h"
class MapBuilder
{
public:
	MapBuilder* setMonster(FightableMob*);
	MapBuilder* setName(string);
	MapBuilder();
	Map* createMap();
private:
	Map* map=nullptr;
};

