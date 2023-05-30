#include "Bite.h"
#include "../../SkillEffect/SkillEffects/HarmfulEffect.h"
Bite::Bite() {
	this->skillName = "¼¹«r";
	this->setSkillEffect(new HarmfulEffect(0.8));
}