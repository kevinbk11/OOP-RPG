#include "FightController.h"
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
	this->isPlayerTurn = true;
	while (player->isLive() && mob->isLive()) {
		if (isPlayerTurn) {
			cout << endl << "你的血量:" << player->getHp() << endl;
			cout << endl << "你的魔量:" << player->getMp() << endl;
			cout << endl <<mob->name <<"的血量:" << mob->getHp() << endl;
			cout <<endl<< "輸入1選擇攻擊模式，輸入2選擇道具，輸入3逃跑。\n";
			int command;
			cin >> command;
			system("cls");
			switch (command) {
				case 1:
					attackController->choiceSkill(player);
					attackController->attack(player, mob);
					break;
				case 2:
					break;
				case 3:
					cout << "逃跑成功。";
					return;
			}
		}
		else {
			attackController->choiceSkill(mob);
			attackController->attack(mob, player);
		}
		isPlayerTurn = !isPlayerTurn;
	}
	system("cls");
	cout <<endl<< "戰鬥結束。\n";
	FightableMob* winner;
	FightableMob* loser;
	if (player->isLive()) {
		winner = player;
		loser = mob;
	}
	else {
		winner = mob;
		loser = player;
	}
	loser->respawn();
}