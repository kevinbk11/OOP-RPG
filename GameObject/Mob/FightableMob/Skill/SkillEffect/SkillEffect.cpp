#include "SkillEffect.h"
SkillEffect::~SkillEffect() {}
void SkillEffect::execute(float dif, FightableMob* caster, Mob* target) {
	if (dif > 0.0) {
		DamageObject* damage = new DamageObject(dif, this->effectState);
		target->getAttack(damage);
		delete damage;
	}
	this->times--;
}