#include "Player.h"
#include "../../../../ControlCenter/Controller.h"
Player::Player(string name) {
	this->name = name;
	this->bag = vector<Item*>();
	this->putItemIntoBag(new HealWater(5));
}
void Player::getAttack(DamageObject* damageObject) {
	FightableMob::getAttack(damageObject);
}
void Player::setLocate(Map* map) {
	this->locate = map;
}
void Player::respawn() {
	cout <<endl<< "眼前一片黑暗，你回到了重生點。"<<endl;
	this->hp = this->fullHp*0.1;
	this->mp = this->fullMp * 0.1;
	this->setLocate(ControlCenter::getInstance<GameController>()->getPlayerRespawnPoint());
}
void Player::getMonsterBooty(Enemy* enemy) {
	Booty *booty = enemy->dropBooty();
	this->addExp(booty->exp);
	this->money += booty->money;
	cout << "獲得了" << booty->money << "元\n";
	cout << "獲得了" << booty->exp << "點經驗"<<endl;
	for (int i = 0; i < booty->items.size(); i++) {
		cout << "獲得了" << booty->items[i]->name << booty->items[i]->getCount()<<"個\n";
		this->putItemIntoBag((booty->items[i]));
	}
	cout << endl;
}
void Player::addExp(int exp) {
	this->nowExp += exp;
	if (this->isLevelUp())this->levelUp();
}
bool Player::isLevelUp() {
	return this->nowExp >= this->neededExp;
}
void Player::levelUp() {
	cout << endl << "LEVEL UP!!!" << endl;
	this->level += 1;
	this->nowExp -= this->neededExp;
	this->neededExp += level * 5;
	this->hp = this->fullHp;
	this->mp = this->fullMp;
}
void Player::printDetails() {
	cout << "玩家名稱:" << this->name<<endl;
	cout << "玩家血量:" << this->hp<<"/"<<this->fullHp << endl;
	cout << "玩家魔量:" << this->mp << "/" << this->fullMp << endl;
	cout << "玩家等級:" << this->level << endl;
	cout << "玩家經驗值:" << this->nowExp<<"/"<<this->neededExp << endl;
	cout << "玩家金幣:" << this->money << "元\n";
	cout << endl;
	this->printBag();
}
void Player::putItemIntoBag(Item* item) {
	for (int i = 0; i < bag.size(); i++) {
		if (bag[i]->name == item->name) {
			bag[i]->addCount(item->getCount());
			delete item;
			return;
		}
		}
	bag.push_back(item);
}
bool Player::printBag() {
	if (bag.size() == 0) {
		cout << "背包是空的。\n\n";
		return false;
	}
	else {
		for (int i = 0; i < bag.size(); i++) {
			cout << i + 1 << ".";
			bag[i]->printDetails();
		}	
		cout << endl;
		return true;
	}
}
bool Player::useItem(int index) {
	return this->bag[index]->use(this);
}
void Player::removeItem(Item *item) {
	for (int i = 0; i < this->bag.size(); i++) {
		if (this->bag[i]->name == item->name) {
			cout << this->bag[i]->name;
			this->bag.erase(bag.begin() + i);
			return;
		}
	}
}
Map* Player::getLocate() {
	return this->locate;
}

