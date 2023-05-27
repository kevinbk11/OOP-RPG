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
	cout << "��J";
}*/
void OutputController::printPlayerGetAttackMessage(Player* player,DamageObject* damageObject) {
	cout << "���a" << player->name << "����F" << damageObject->getDamageValue() << "�I�ˮ`";
}