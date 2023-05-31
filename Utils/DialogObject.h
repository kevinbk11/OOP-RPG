#pragma once
#include "../GameObject/Mob/FightableMob/Player/Player.h"
class Map;
class Player;
class NPC;
class DialogObject
{
public:
	DialogObject(string);
	void execute(Player*,NPC*);
	void addSubDialog(DialogObject*);
	void addOptionalResponse(string);
private:
	string sentence;
	vector<string> respond;
	vector<DialogObject*> nextState;
};

