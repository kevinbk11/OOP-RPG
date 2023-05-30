#include "Skill.h"
#include "SkillEffect/SkillEffect.h"
#include "../FightableMob.h"
void Skill::setSkillEffect(SkillEffect* effect) {
	this->effect = effect;
}
void Skill::executeEffect(FightableMob* mob1, Mob* mob2) {
	this->effect->execute(mob1, mob2);
}
