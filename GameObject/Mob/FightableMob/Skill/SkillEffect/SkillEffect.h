#pragma once
#include "../../FightableMob.h"
class FightableMob;
class Mob;
class SkillEffect
{
public:
	int times;
	virtual float calculateDamage(FightableMob*, Mob*)=0;
	virtual void execute(float, FightableMob* caster,Mob* target);
	virtual ~SkillEffect();
	int effectState;
	enum class STATE {
		BURING = 1,
		CHARGED = 2,
	};
};

