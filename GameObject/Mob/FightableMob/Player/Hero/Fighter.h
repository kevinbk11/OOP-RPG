#pragma once
#include "../Player.h"
#include "../../Skill/Skills/FighterSkills/NormalAttack.h"
class Fighter:public Player
{
public:
	void levelUp();
	Fighter(string);
};

