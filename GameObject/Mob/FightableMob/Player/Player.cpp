#include "Player.h"
#include "../../../../ControlCenter/Controller.h"
Player::Player(string name) {
	this->name = name;
}
void Player::getAttack(DamageObject* damageObject) {
	FightableMob::getAttack(damageObject);
	cout << "ㄚㄚㄚㄚ阿a";
}
void Player::setLocate(Map* map) {
	this->locate = map;
}
void Player::respawn() {
	cout <<endl<< "眼前一片黑暗，你回到了重生點。"<<endl;
	this->hp = this->fullHp*0.1;
	this->mp = this->fullMp * 0.1;
	cout << this->hp << endl;
	cout << this->mp << endl;
	this->setLocate(ControlCenter::getInstance<GameController>()->getPlayerRespawnPoint());
}
Map* Player::getLocate() {
	return this->locate;
}

