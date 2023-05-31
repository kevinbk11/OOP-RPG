#include "HealWater.h"
#include "../../Mob/FightableMob/Player/Player.h"
HealWater::HealWater(int count):Item(count) {
	this->name = "�v���Ĥ�";
	this->describe = "�ܤU��i�H�^�_100�IHP�C\n";
}
bool HealWater::use(Player* player) {
	player->addHp(100);
	this->drop(1);
	if (this->count == 0) {
		player->removeItem(this);
	}
	return true;
}