#include "Player.h"
#include "../../../../ControlCenter/Controller.h"
#include "../../../../Utils/TaskChecker.h"
Player::Player(string name) {
	this->name = name;
	this->bag.push_back(vector <Item*>());//道具背包
	this->bag.push_back(vector<Item*>());//裝備背包
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
void Player::getBooty(Booty* booty) {
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
	while (this->isLevelUp())this->levelUp();
}
bool Player::isLevelUp() {
	return this->nowExp >= this->neededExp;
}
void Player::levelUp() {
	cout << endl << "LEVEL UP!!!" << endl;
	this->level += 1;
	this->nowExp -= this->neededExp;
	this->neededExp += (level - 1) * 5;
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
	cout << "手持武器:";
	if (this->weapon != nullptr)cout << this->weapon->getName();
	else cout << "無";
	cout << endl;
	cout << "當前攻擊力:" << this->basicDamageValue << endl;
	cout << "當前防禦力:" << this->basicDefenseValue << endl;
	cout << endl;
}
void Player::putItemIntoBag(Item* item) {
	int type = item->type;
	for (int i = 0; i < bag[type].size(); i++) {
		if (bag[type][i]->name == item->name) {
			bag[type][i]->addCount(item->getCount());
			for (auto& it : this->tasks) {
				if (TaskProcessor::check(it, *bag[type][i])) {
					cout << "\n任務「" << it->name << "」完成。\n\n";
					it->isSolved = true;
				}
			}
			delete item;
			return;
		}
	}
	bag[type].push_back(item);
}
bool Player::printBag(int type) {
	if (bag[type].size() == 0) {
		cout << "此背包是空的。\n\n";
		return false;
	}
	else {
		for (int i = 0; i < bag[type].size(); i++) {
			cout << i + 1 << ".";
			bag[type][i]->printDetails();
		}	
		cout << endl;
		return true;
	}
}
bool Player::useItem(int index, int type) {
	return this->bag[type].at(index)->use(this);
}
void Player::removeItem(Item *item ,int count) {
	int type = item->type;
	for (int i = 0; i < this->bag[type].size(); i++) {
		if (this->bag[type][i]->name == item->name) {
			if(count==-1)this->bag[type].erase(bag[type].begin() + i);
			else {
				this->bag[type][i]->drop(count);
				if (this->bag[type][i]->getCount() == 0)this->bag[type].erase(bag[type].begin() + i);
			}
			return;
		}
	}
}
void Player::acceptTask(Task *task) {
	this->tasks.push_back(task);
}
Map* Player::getLocate() {
	return this->locate;
}
vector<Task*> Player::getTasks() {
	return this->tasks;
}
void Player::solveTask(Task* task,int type) {
	for (Item* item : this->bag[type]) {
		for (auto& pair : task->requireItems) {
			if (item->name == pair.first) {
				this->removeItem(item, pair.second);
				break;
			}
		}
	}
}
void Player::OperateEquipment(Wearable* wearable) {
	wearable->attachTo(this);
}
vector<vector<Item*>> Player::getBag()
{
	return bag;
}