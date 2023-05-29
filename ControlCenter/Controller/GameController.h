#pragma once
#include "../../GameObject/Mob/FightableMob/Player/Player.h"
#include "../../Utils/MapObjectGenerator/GameMapGenerator.h"
class GameController
{
public:
	static GameController* getInstance();
	void gameStart(Player*);
	void initMap();
private:
	static GameController* controller;
	GameMap mapObject;
};

