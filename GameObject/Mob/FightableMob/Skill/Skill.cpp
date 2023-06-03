#include "Skill.h"
#include "SkillEffect/SkillEffect.h"
#include "../FightableMob.h"
void Skill::addEffect(SkillEffect* effect) {
	this->effects.push_back(effect);
}
void Skill::executeEffect(FightableMob* mob1, Mob* mob2) {
	for (SkillEffect* effect : this->effects) {
		mob2->selfEffect.push_back(effect);
		mob2->effectState |= effect->effectState;
	}
	this->effects.clear();
}
void Skill::execute(FightableMob* mob1, Mob* mob2){}