#include "NormalAttack.h"
#include "../../SkillEffect/SkillEffects/HarmfulEffect.h"
NormalAttack::NormalAttack() {
	this->skillName = "普通攻擊";
}
void NormalAttack::execute(FightableMob* caster,Mob* target) {
	this->addEffect(new HarmfulEffect(1.0));
	this->executeEffect(target);
}