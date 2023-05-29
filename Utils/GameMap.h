#pragma once
#include "../GameObject/Map/Map.h"
#include <vector>
class GameMap
{
public:
	void setRespawnPoint(Map*);
	Map* getRespawnPoint();
private:
	Map* respawnPoint;
};

