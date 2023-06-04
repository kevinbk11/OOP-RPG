#include "Strike.h"
#include "../../SkillEffect/SkillEffects/HarmfulEffect.h"
Strike::Strike() {
	this->skillName = "����";
}
void Strike::execute(FightableMob* caster, Mob* target) {
	this->addEffect(new HarmfulEffect(1.0));
	this->executeEffect(target);
}