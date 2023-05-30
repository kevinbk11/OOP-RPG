#pragma once
#include "../../GameObject/Mob/FightableMob/Player/Player.h"
#include "../../Utils/MapObjectGenerator/GameMapGenerator.h"
#include "../Controller.h"
#include "../ControlCenter.h"
class GameController
{
public:
	static GameController* getInstance();
	void gameStart(Player*);
	void initMap();
	Map* getPlayerRespawnPoint();
	void setPlayerRespawnPoint(Map*);
private:
	static GameController* controller;
	GameMap mapObject;
};

