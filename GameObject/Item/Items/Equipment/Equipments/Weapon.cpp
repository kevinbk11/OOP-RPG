#include "Weapon.h"
#include "../../../../Mob/FightableMob/Player/Player.h"
Weapon::Weapon(int count) :Item(count) {
	this->type = 1; 
}
void Weapon::showMessage(WearType type) {
	system("cls");
	switch (type) {
		case WearType::ATTACH:
			cout << "���_�F" << name << "�A" << "�W�[�F" << this->damageValue << "�I�����O\n\n";
			break;
		case WearType::DETACH:
			cout << "��U�F" << name << "�A" << "��֤F" << this->damageValue << "�I�����O\n\n";
			break;
	}
}
void Weapon::attachTo(Player* player) {
	player->weapon = this;
	player->adjustDamageValue(this->damageValue);
	showMessage(WearType::ATTACH);
}
void Weapon::detachTo(Player* player) {
	player->adjustDamageValue(-this->damageValue);
	showMessage(WearType::DETACH);
}
bool Weapon::use(Player* player) {
	if (player->weapon != nullptr) {
		if(this->name==player->weapon->getName())this->detachTo(player);
		else this->attachTo(player);
	}
	else this->attachTo(player);
	return true;
}