#pragma once

#include "../../Skill.h"
class NormalAttack :public Skill
{
public:
	NormalAttack();
	void execute(FightableMob* caster, Mob* target);
};

