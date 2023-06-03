#pragma once
#include "../../Skill.h"
class FireSword :public Skill
{
public:
	FireSword();
	void execute(FightableMob* caster, Mob* target);
};

