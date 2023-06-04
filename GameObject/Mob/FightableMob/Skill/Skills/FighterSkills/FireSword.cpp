#include "FireSword.h"
#include "../../SkillEffect/SkillEffects/FireEffect.h"
#include "../../SkillEffect/SkillEffects/HarmfulEffect.h"
FireSword::FireSword() {
	this->skillName = "¤õµK¼A¬å";
}
void FireSword::execute(FightableMob* caster, Mob* target) {
	FireEffect* effect1 = new FireEffect(0.2);
	HarmfulEffect* effect2 = new HarmfulEffect(0.5);
	if (!(target->effectState & effect1->effectState)) {
		this->addEffect(effect1);
	}
	this->addEffect(effect2);
	this->executeEffect(target);
}