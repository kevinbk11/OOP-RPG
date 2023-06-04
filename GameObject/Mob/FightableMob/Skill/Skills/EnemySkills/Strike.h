#pragma once
#include "../../Skill.h"
class Strike :public Skill
{
public:
	Strike();
	void execute(FightableMob*, Mob*);
};

