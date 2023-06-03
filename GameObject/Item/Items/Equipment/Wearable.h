#pragma once
#include <string>
class Player;
class Wearable
{
public:
	virtual void attachTo(Player*)=0;
	virtual void detachTo(Player*) = 0;
	virtual std::string getName()=0;
protected:
	enum class WearType { ATTACH, DETACH };
	virtual void showMessage(WearType) = 0;
};

