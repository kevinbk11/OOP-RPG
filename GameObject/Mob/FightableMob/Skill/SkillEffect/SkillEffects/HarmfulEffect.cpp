#include "HarmfulEffect.h"
HarmfulEffect::HarmfulEffect(double magnification) {
	this->magnification = magnification;
	this->times = 1;
	this->effectState = 0;
}

float HarmfulEffect::calculateDamage(FightableMob* caster, Mob* target) {
	float dif = caster->getBasicDamageValue()*magnification - target->getBasicDefenseValue();
	dif = dif > 0 ? dif : 0;
	return dif;
}