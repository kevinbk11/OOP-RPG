#pragma once
#include "../../../Item.h"
#include "../Wearable.h"
class Player;
class Item;
class Wearable;
class Armor:public Item,public Wearable
{
public:
	Armor(int count);
	void attachTo(Player*);
	void detachTo(Player*);
	int defenseValue;
	bool use(Player*);
	string getName() {
		return this->name;
	}
protected:
	void showMessage(WearType type);
};

