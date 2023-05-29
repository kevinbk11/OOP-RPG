#include "Player.h"
Player::Player(string name) {
	this->name = name;
}
void Player::attack(Mob* mob) {
	this->executeSkill(this,mob);
}
void Player::getAttack(DamageObject* damageObject) {
	FightableMob::getAttack(damageObject);
	cout << "глглглглк№";
}
void Player::executeSkill(Player* player,Mob* mob) {
	cout << this->name << "и╧е╬дF" << this->skillChoice->skillName << endl;
	this->skillChoice->executeEffect(player, mob);
}
void Player::setSkillChoice(Skill* skill) {
	this->skillChoice = skill;
}
void Player::setLocate(Map* map) {
	this->locate = map;
}
Map* Player::getLocate() {
	return this->locate;
}

