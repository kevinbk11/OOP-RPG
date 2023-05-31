#include "Fighter.h"
#include "../../../../../ControlCenter/ControlCenter.h"
Fighter::Fighter(string name):Player(name) {
	initDamageValue(35);
	initDefenseValue(10);
	initHp(100);
	initMp(50);
	this->setSkill(new NormalAttack());
}
void Fighter::levelUp() {
	this->fullHp += 50;
	this->fullMp += 5;
	this->basicDamageValue += (level/5.0f);
	this->basicDamageValue += (level / 10.0f);
	Player::levelUp();
}