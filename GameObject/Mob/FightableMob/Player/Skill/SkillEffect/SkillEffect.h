#pragma once
#include "../../../FightableMob.h"
class SkillEffect
{
public:
	virtual void execute(FightableMob*, Mob*)=0;
};

