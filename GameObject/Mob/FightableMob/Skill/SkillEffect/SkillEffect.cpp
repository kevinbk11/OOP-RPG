#include "SkillEffect.h"
void SkillEffect::execute(float dif, Mob* target) {
	DamageObject* damage = new DamageObject(dif,this->effectState);
	target->getAttack(damage);
	this->times--;
	delete damage;
}