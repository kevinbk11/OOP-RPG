#include "Fighter.h"
#include "../../../../../ControlCenter/ControlCenter.h"
#include "../../../../Item/Items/Equipment/Equipments/Weapons/WoodSword.h"
#include "../../../../Item/Items/Equipment/Equipments/Armor/LeatherArmor.h"
#include "../../Skill/Skills/FighterSkills/NormalAttack.h"
#include "../../Skill/Skills/FighterSkills/FireSword.h"
#include "../../Skill/Skills/FighterSkills/Charge.h"
Fighter::Fighter(string name):Player(name) {
	initDamageValue(30);
	initDefenseValue(10);
	initHp(100);
	initMp(50);
	this->setSkill(new NormalAttack());
	this->setSkill(new FireSword());
	this->setSkill(new Charge());
	this->putItemIntoBag(new HealWater(5));

}
void Fighter::levelUp() {
	this->fullHp += 20;
	this->fullMp += 10;
	this->basicDamageValue += (level/5.0f);
	this->basicDamageValue += (level / 10.0f);
	Player::levelUp();
}