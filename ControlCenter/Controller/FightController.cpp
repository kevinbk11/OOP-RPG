#include "FightController.h"
#include "../../Utils/TaskChecker.h"
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

void FightController::fight(Player* player, Enemy* mob){
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
					if (!player->printBag(0)) {
						system("cls");
						continue;
					}
					cout << "請輸入你要使用的道具，輸入0返回。\n";
					do {
						cin >> command;
						if (command == 0) {
							system("cls");
							break;
						}
					} while (!player->useItem(command - 1,0));
					if (command == 0)continue;
					attackController->executeDamageCalculate(player, mob);
					break;
				case 3:
					cout << "逃跑成功。\n";
					break;
				default:
					cout << "錯誤!\n";
					continue;
			}
		}
		else {
			attackController->choiceSkill(mob);
			attackController->attack(mob, player);
		}
		isPlayerTurn = !isPlayerTurn;
	}
	system("cls");
	player->effectState = 0;
	for (SkillEffect* effect : player->selfEffect) {
		delete effect;
	}
	player->selfEffect.clear();
	if (player->isLive() && mob->isLive())return;//代表逃跑
	cout <<endl<< "戰鬥結束。\n";
	if (player->isLive()) {	
		TaskProcessor::update(player->getTasks(), mob->name);
		player->getBooty(mob->dropBooty());
	}
	else {
		player->respawn();
	}
	mob->respawn();
}