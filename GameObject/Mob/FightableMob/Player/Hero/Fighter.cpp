#include "Fighter.h"
#include "../../../../../ControlCenter/ControlCenter.h"
#include "../../../../Item/Items/Equipment/Equipments/Weapons/WoodSword.h"
#include "../../../../Item/Items/Equipment/Equipments/Armor/LeatherArmor.h"
#include "../../Skill/Skills/FighterSkills/NormalAttack.h"
#include "../../Skill/Skills/FighterSkills/FireSword.h"
Fighter::Fighter(string name):Player(name) {
	initDamageValue(30);
	initDefenseValue(1000);
	initHp(10000);
	initMp(50);
	this->setSkill(new NormalAttack());
	this->setSkill(new FireSword());
	this->putItemIntoBag(new HealWater(5));
	this->putItemIntoBag(new WoodSword(1));
	this->putItemIntoBag(new LeatherArmor(1));
}
void Fighter::levelUp() {
	this->fullHp += 50;
	this->fullMp += 5;
	this->basicDamageValue += (level/5.0f);
	this->basicDamageValue += (level / 10.0f);
	Player::levelUp();
}