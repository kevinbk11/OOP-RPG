#pragma once
#include ".././../Skill.h"
class Charge :public Skill
{
public:
	Charge();
	void execute(FightableMob* caster, Mob* target);
};

