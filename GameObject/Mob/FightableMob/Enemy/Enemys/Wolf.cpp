#include "Wolf.h"
#include "../../Skill/Skills/EnemySkills/Bite.h"
Wolf::Wolf() {
	this->name = "³¥¯T";
	initDamageValue(25);
	initDefenseValue(5);
	initHp(1000);
	initMp(0);
	this->booty->exp = 20;
	this->booty->money = 10;
	this->setSkill(new Bite());
}
void Wolf::setBootyItems() {
	this->booty->items.clear();
	this->booty->items.push_back(new WolfFur(1));
}
void Wolf::setSkillChoice() {
	this->skillChoice = (skills[0]);
}
