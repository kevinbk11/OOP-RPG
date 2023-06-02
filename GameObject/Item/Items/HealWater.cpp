#include "HealWater.h"
#include "../../Mob/FightableMob/Player/Player.h"
HealWater::HealWater(int count):Item(count) {
	this->name = "治療藥水";
	this->describe = "喝下後可以回復100點HP。\n";
}
bool HealWater::use(Player* player) {
	player->addHp(100);
	player->removeItem(this,1);
	return true;
}