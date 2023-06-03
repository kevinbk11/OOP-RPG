#pragma once
#include "../Enemy/Enemy.h"
#include "../../../Map/Map.h"
#include "../../../Task/Task.h"
#include "../../../Item/Items/Equipment/Equipments/Weapon.h"
class Skill;
class Map;
class Task;
class Weapon;
class Wearable;
class Player:public FightableMob
{

public:
	Player(string name);
	void getAttack(DamageObject* damageObject);
	void setLocate(Map*);
	void getBooty(Booty*);
	void respawn();
	void printDetails();
	bool printBag(int type);
	bool useItem(int,int type);
	void putItemIntoBag(Item*);
	void removeItem(Item*,int count=-1);
	void acceptTask(Task*);
	void solveTask(Task*,int);
	vector<Task*> getTasks();
	Map* getLocate();
	void OperateEquipment(Wearable*);
	Wearable* weapon = nullptr;
	Wearable* armor = nullptr;
	vector<vector<Item*>> getBag();
protected:
	int money;
	int level = 1;
	void addExp(int);
	bool isLevelUp();
	virtual void levelUp();
	vector<Task*> tasks;
private:
	vector<vector<Item*>> bag;
	int nowExp = 0;
	int neededExp = 10;
	Map* locate = nullptr;
};

