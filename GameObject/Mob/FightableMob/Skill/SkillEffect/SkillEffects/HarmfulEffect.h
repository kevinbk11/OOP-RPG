#pragma once
#include "../SkillEffect.h"
class HarmfulEffect:public SkillEffect
{
public:
	float calculateDamage(FightableMob*,Mob*);
	HarmfulEffect(double);
private:
	double magnification;
};

