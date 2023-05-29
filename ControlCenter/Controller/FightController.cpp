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
	AttackController* attackController = ControlCenter::getInstance<AttackController>();
	while (player->isLive() && mob->isLive()) {
		if (isPlayerTurn) {
			cout << "��J1��ܧ����Ҧ�\n��J2��ܹD��\n��J3�k�]\n";
			int command;
			cin >> command;
			switch (command) {
				case 1:
					//attackController->choiceSkill(player);
					//attackController->attack(player, mob);
					break;
				case 2:
					break;
				case 3:
					break;
			}
		}
	}
	cout << "�԰�����";	
}