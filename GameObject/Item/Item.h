#pragma once
#include "../GameObject.h"
class Player;
class Item:public GameObject
{
public:
	void printDetails();
	int getCount();
	void addCount(int);
	virtual bool use(Player*);
	void drop(int);
protected:
	int count;
	string describe;
};
