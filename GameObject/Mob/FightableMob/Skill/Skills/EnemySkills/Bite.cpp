#include "Bite.h"
#include "../../SkillEffect/SkillEffects/HarmfulEffect.h"
Bite::Bite() {
	this->skillName = "撕咬";
	this->setSkillEffect(new HarmfulEffect(0.8));
}