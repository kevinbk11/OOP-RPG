#include "Pig.h"
#include "../../Skill/Skills/EnemySkills/Strike.h"
Pig::Pig() {
	this->name = "ГЅНо";
	initDamageValue(15);
	initDefenseValue(15);
	initHp(100);
	initMp(0);
	this->booty->exp = 5;
	this->booty->money = 5;
	this->setSkill(new Strike());
}
void Pig::setBootyItems() {
	this->booty->items.clear();
	this->booty->items.push_back(new Pork(1));
}
void Pig::setSkillChoice() {
	this->skillChoice = (skills[0]);
}
