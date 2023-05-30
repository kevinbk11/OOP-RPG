#include "NormalAttack.h"
#include "../../SkillEffect/SkillEffects/HarmfulEffect.h"
NormalAttack::NormalAttack() {
	this->skillName = "普通攻擊";
	this->setSkillEffect(new HarmfulEffect(1.0));
}