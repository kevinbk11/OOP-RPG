#pragma once
#include "../../FightableMob.h"
class FightableMob;
class Mob;
class SkillEffect
{
public:
	int continous;
	int times;
	virtual float calculateDamage(FightableMob*, Mob*)=0;
	void execute(float, Mob* target);
	int effectState;
	enum class STATE {
		BURING = 1,
	};
};

