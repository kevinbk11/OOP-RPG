#pragma once
#include "../SkillEffect.h"
class FireEffect :public SkillEffect
{
public:
	float calculateDamage(FightableMob*, Mob*);
	FireEffect(double);
private:
	double magnification;
};

