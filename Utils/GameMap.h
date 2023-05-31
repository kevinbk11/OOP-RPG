#pragma once
#include "../GameObject/Map/Map.h"
#include <vector>
class GameMap
{
public:
	GameMap(vector<Map*>);
	void setRespawnPoint(Map*);
	vector<Map*> getAllMap();
	Map* getRespawnPoint();
private:
	vector<Map*>allMap;
	Map* respawnPoint;
};

