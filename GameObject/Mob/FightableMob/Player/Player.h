#pragma once
#include "../Enemy/Enemy.h"
#include "../../../Map/Map.h"
class Skill;
class Player:public FightableMob
{

public:
	Player(string name);
	void getAttack(DamageObject* damageObject);
	void setLocate(Map*);
	void getMonsterBooty(Enemy*);
	void respawn();
	void printDetails();
	bool printBag();
	bool useItem(int);
	void putItemIntoBag(Item*);
	void removeItem(Item*);
	Map* getLocate();
protected:
	int money;
	void addExp(int);
	bool isLevelUp();
	virtual void levelUp();
private:

	vector <Item*> bag;
	int level = 1;
	int nowExp = 0;
	int neededExp = 10;
	Map* locate = nullptr;
};

