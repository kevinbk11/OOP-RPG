#pragma once
#include "../../Skill.h"
class Bite :public Skill
{
public:
	Bite();
	void execute(FightableMob*, Mob*);
};

