#include "GameController.h"
GameController* GameController::controller = nullptr;
GameController *GameController::getInstance() {
	if (controller == nullptr) {
		controller = new GameController();
	}
	return controller;
}
void GameController::initMap() {
	this->mapObject=GameMapGenerator::generate();
}
void GameController::gameStart(Player* player) {
	if (player == nullptr) {
		cout << "讀取玩家中。";
		return;
	}
	cout << "遊戲開始\n";
	this->initMap();
	player->setLocate(this->mapObject.getRespawnPoint());
	while (true) {
		cout <<"輸入0前往上一張地圖，輸入1前往下一張地圖，輸入2查看此處的怪物並選擇要戰鬥的怪物。\n";
		Map* locate = player->getLocate();
		vector<FightableMob*> mobs = locate->getAllMob();
		cout << "目前所在地:"<<locate->name<<endl;
		int command;
		cin >> command;
		system("cls");
		switch (command) {
			case 0: {
				break;
			}
			case 1: {
				player->setLocate(locate->getNextMap());
				break;
			}
			case 2: {
				if (mobs.size() == 0)cout << "這裡沒有怪物。\n";
				else {
					cout << "請輸入怪物代碼來進入戰鬥。\n";
					for (int i = 0; i < mobs.size(); i++) {
						cout << "怪物" << i + 1 << ":" << mobs[i]->name << endl;
					}
					cin >> command;
					FightableMob *mob = mobs[command - 1];
					FightController *controller = ControlCenter::getInstance<FightController>();
					controller->fight(player, mob);
					cout << endl;
				}
			}
		}
	}
	cout << "遊戲結束，謝謝遊玩。\n";
}
Map* GameController::getPlayerRespawnPoint() {
	return this->mapObject.getRespawnPoint();
}
void GameController::setPlayerRespawnPoint(Map* map) {
	this->mapObject.setRespawnPoint(map);
}