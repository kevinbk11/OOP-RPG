#pragma once
#include "../SkillEffect.h"
#include "../../GameObject/Mob/FightableMob/Player/Player.h"
class Mob;
class HarmfulEffect:public SkillEffect
{
public:
	float calculateDamage(FightableMob*,Mob*);
	HarmfulEffect(double);
private:
	double magnification;
};

