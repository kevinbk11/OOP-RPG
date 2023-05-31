#include "InteractiveController.h"
InteractiveController* InteractiveController::controller = nullptr;
InteractiveController::InteractiveController() {};
InteractiveController* InteractiveController::getInstance()
{
	if (controller == nullptr) {
		controller = new InteractiveController();
	}
	return controller;
}
void InteractiveController::interactive(Player* player,NPC *npc) {
	DialogObject *dialog = npc->getOpeningDialog();
	dialog->execute(player,npc);
}
