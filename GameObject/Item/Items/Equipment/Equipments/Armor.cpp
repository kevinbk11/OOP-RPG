#include "Armor.h"
#include "../../../../Mob/FightableMob/Player/Player.h"
Armor::Armor(int count) :Item(count) {
	this->type = 1;
}
void Armor::showMessage(WearType type) {
	system("cls");
	switch (type) {
		case WearType::ATTACH:
			cout << "穿上了" << name << "，" << "增加了" << this->defenseValue << "點防禦力\n\n";
			break;
		case WearType::DETACH:
			cout << "脫下了" << name << "，" << "減少了" << this->defenseValue << "點攻擊力\n\n";
			break;
	}
}
void Armor::attachTo(Player* player) {
	player->armor = this;
	player->adjustDefenseValue(this->defenseValue);
	showMessage(WearType::ATTACH);
}
void Armor::detachTo(Player* player) {
	player->adjustDefenseValue(-this->defenseValue);
	showMessage(WearType::DETACH);
}
bool Armor::use(Player* player) {
	if (player->armor != nullptr) {
		if (this->name == player->armor->getName())this->detachTo(player);
		else this->attachTo(player);
	}
	else this->attachTo(player);
	return true;
}