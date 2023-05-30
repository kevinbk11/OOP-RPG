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
			cout << endl << "�A����q:" << player->getHp() << endl;
			cout << endl << "�A���]�q:" << player->getMp() << endl;
			cout << endl <<mob->name <<"����q:" << mob->getHp() << endl;
			cout <<endl<< "��J1��ܧ����Ҧ��A��J2��ܹD��A��J3�k�]�C\n";
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
					cout << "�k�]���\�C";
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
	cout <<endl<< "�԰������C\n";
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