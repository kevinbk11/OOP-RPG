#pragma once
#include "../SkillEffect.h"
#include "../../GameObject/Mob/FightableMob/Player/Player.h"
class Mob;
class HarmfulEffect:public SkillEffect
{
public:
	void execute(FightableMob*,Mob*);
	HarmfulEffect(double);
private:
	double magnification;
};

