#include "Skill.h"
#include "SkillEffect/SkillEffect.h"
#include "../../Player/Player.h"
void Skill::setSkillEffect(SkillEffect* effect) {
	this->effect = effect;
}
void Skill::executeEffect(Player* player,Mob* mob) {
	this->effect->execute(player,mob);
}