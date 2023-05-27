#include "OutputController.h"
OutputController*  OutputController::controller = nullptr;
OutputController::OutputController() {}
OutputController* OutputController::getInstance()
{
	if (controller == nullptr) {
		controller = new OutputController();
	}
	return controller;
}
/*void OutputController::printSkillHint() {
	cout << "輸入";
}*/
void OutputController::printPlayerGetAttackMessage(Player* player,DamageObject* damageObject) {
	cout << "玩家" << player->name << "受到了" << damageObject->getDamageValue() << "點傷害";
}