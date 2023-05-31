#pragma once
#include "../../GameObject/NPC/NPC.h"
#include "../../GameObject/Mob/FightableMob/Player/Player.h"
class InteractiveController
{
public:
	static InteractiveController* getInstance();
	void interactive(Player*,NPC*);
private:
	static InteractiveController* controller;
	InteractiveController();
};

