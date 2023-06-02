#pragma once
#include "../../GameObject/Mob/FightableMob/Player/Player.h"
class Map;
class Player;
class NPC;
class DialogObject
{
public:
	DialogObject(string);
	DialogObject();
	virtual void execute(Player*,NPC*);
	DialogObject* addSubDialog(DialogObject*);
	DialogObject* addOptional(string,string);
	void setOptionalDialog();
	void setDisconnectPoint(DialogObject*, DialogObject*,int);
	vector<string> respond;
protected:
	DialogObject* disconnectPoint=nullptr;
	DialogObject* forReplaceDialog = nullptr;
	string sentence;
	vector<DialogObject*> nextState;
	int pathIndex;
	bool haveTask=false;
	DialogObject* parent;
};

