#include "Bite.h"
#include "../../SkillEffect/SkillEffects/HarmfulEffect.h"
Bite::Bite() {
	this->skillName = "撕咬";
}
void Bite::execute(FightableMob* caster, Mob* target) {
	this->addEffect(new HarmfulEffect(1.5));
	this->executeEffect(target);
}