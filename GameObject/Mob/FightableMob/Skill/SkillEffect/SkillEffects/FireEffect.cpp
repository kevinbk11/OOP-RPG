#include "FireEffect.h"
FireEffect::FireEffect(double magnification) {
	this->magnification = magnification;
	this->continous = 3;
	this->times = 3;
	this->effectState = int(STATE::BURING);
	cout << this->effectState;
}

float FireEffect::calculateDamage(FightableMob* caster, Mob* target) {
	float dif = caster->getBasicDamageValue() * magnification;
	dif = dif > 0 ? dif : 0;
	return dif;
}