#include "FightController.h"
#include "../../ControlCenter/ControlCenter.h"

FightController* FightController::controller = nullptr;
FightController::FightController() {
	this->isPlayerTurn = true;
}
FightController* FightController::getInstance()
{
	if (controller == NULL) {
		controller = new FightController();
	}
	return controller;
}
void FightController::fight(Player* player, FightableMob* mob){
	OutputController* outputController = ControlCenter::getOutputController(); 
	AttackController* attackController = ControlCenter::getAttackController();
	while (player->isLive() && mob->isLive()) {
		if (isPlayerTurn) {
			cout << "輸入1選擇攻擊模式\n輸入2選擇道具\n輸入3逃跑\n";
			int command;
			cin >> command;
			switch (command) {
				case 1:
					attackController->choiceSkill(player);
					attackController->attack(player, mob);
					break;
				case 2:
					break;
				case 3:
					break;
			}
		}
	}
}