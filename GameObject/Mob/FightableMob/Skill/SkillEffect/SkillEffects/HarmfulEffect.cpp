#include "HarmfulEffect.h"
HarmfulEffect::HarmfulEffect(double magnification) {
	this->magnification = magnification;
}

void HarmfulEffect::execute(FightableMob* caster, Mob* target) { 
	int dif = caster->getBasicDamageValue()*magnification - target->getBasicDefenseValue();
	dif = dif > 0 ? dif : 0;
	DamageObject* damage = new DamageObject(dif);
	target->getAttack(damage);
	delete damage;
}