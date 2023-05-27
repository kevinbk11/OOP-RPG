#include "Player.h"
Player::Player(string name) {
	this->name = name;
	this->hp = 500;
	this -> mp = 500;
	this->basicDamageValue = 35;
	this->basicDefenseValue = 20;
	this->setSkill(new NormalAttack());
}
void Player::attack(Mob* mob) {
	this->executeSkill(this,mob);
}
void Player::getAttack(DamageObject* damageObject) {
	FightableMob::getAttack(damageObject);
	cout << "����������";
}
void Player::executeSkill(Player* player,Mob* mob) {
	cout << this->name << "�ϥΤF" << this->skillChoice->skillName << endl;
	this->skillChoice->executeEffect(player, mob);
}
void Player::setSkillChoice(Skill* skill) {
	this->skillChoice = skill;
}

