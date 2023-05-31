#include "NPC.h"
#include "../Mob/FightableMob/Player/Player.h"
void NPC::talk(Player* player,DialogObject* dialog) {
	dialog->execute(player,this);
}
void NPC::setOpeningDialog(DialogObject* dialog) {
	this->openingDialog = dialog;
}
DialogObject* NPC::getOpeningDialog() {
	return this->openingDialog;
}
