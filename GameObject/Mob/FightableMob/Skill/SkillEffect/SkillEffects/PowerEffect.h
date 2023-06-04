#pragma once
#include "../SkillEffect.h"
class PowerEffect:public SkillEffect
{
public:
	float calculateDamage(FightableMob*, Mob*);
	void execute(float, FightableMob* caster, Mob* target);
	PowerEffect(double);
	~PowerEffect();
private:
	double magnification;
	double originDamageValue;
	FightableMob* myself=new FightableMob();//避免刪除空指標
};

