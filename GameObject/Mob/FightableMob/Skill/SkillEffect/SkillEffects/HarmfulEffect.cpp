#include "HarmfulEffect.h"


void HarmfulEffect::execute(FightableMob* caster, Mob* target) { 
	int dif = caster->getBasicDamageValue() - target->getBasicDefenseValue();
	dif = dif > 0 ? dif : 0;
	DamageObject* damage = new DamageObject(dif);
	target->getAttack(damage);
}