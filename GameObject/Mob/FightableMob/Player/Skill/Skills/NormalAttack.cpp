#include "NormalAttack.h"
#include "../SkillEffect/SkillEffects/HarmfulEffect.h"
NormalAttack::NormalAttack() {
	this->skillName = "���q����";
	this->setSkillEffect(new HarmfulEffect());
}