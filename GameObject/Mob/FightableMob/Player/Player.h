#pragma once
#include "../Enemy/Enemy.h"
#include "../../../Map/Map.h"
#include "../../../Task/Task.h"
class Skill;
class Map;
class Task;
class Player:public FightableMob
{

public:
	Player(string name);
	void getAttack(DamageObject* damageObject);
	void setLocate(Map*);
	void getBooty(Booty*);
	void respawn();
	void printDetails();
	bool printBag();
	bool useItem(int);
	void putItemIntoBag(Item*);
	void removeItem(Item*,int count=-1);
	void acceptTask(Task*);
	void solveTask(Task*);
	vector<Task*> getTasks();
	Map* getLocate();
protected:
	int money;
	int level = 1;
	void addExp(int);
	bool isLevelUp();
	virtual void levelUp();
	vector<Task*> tasks;
private:

	vector <Item*> bag;
	int nowExp = 0;
	int neededExp = 10;
	Map* locate = nullptr;
};

