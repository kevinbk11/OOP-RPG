#include "Bite.h"
#include "../../SkillEffect/SkillEffects/HarmfulEffect.h"
Bite::Bite() {
	this->skillName = "���r";
	this->setSkillEffect(new HarmfulEffect(0.8));
}