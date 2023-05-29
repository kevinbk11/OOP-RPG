#pragma once
#include "../../GameObject/Mob/FightableMob/Player/Hero/Fighter.h"
class CreateHeroController
{
public:
	static CreateHeroController* getInstance();
	Player* createPlayer(string,int);
private:
	static CreateHeroController* controller;
	CreateHeroController();
};
