#pragma once
#include "../GameObject.h"
#include "../../Utils/DialogObject.h"
class DialogObject;
class Player;
class NPC : public GameObject
{
public:
	DialogObject* getOpeningDialog();
	void setOpeningDialog(DialogObject*);
	void talk(Player*,DialogObject*);
private:
	DialogObject* openingDialog = nullptr;
};

