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
		cout << "輸入0前往上一張地圖，輸入1前往下一張地圖\n";
		Map* locate = player->getLocate();
		vector<FightableMob*> mobs = locate->getAllMob();
		cout << "目前所在地:"<<locate->name<<endl;
		if (mobs.size() == 0)cout << "這裡沒有怪物。\n";
		for (int i = 0; i < mobs.size(); i++) {
			cout << "怪物" << i + 1 << ":" << mobs[i]->name<<endl;
		}
		int command;
		cin >> command;
		player->setLocate(locate->getNextMap());
		system("cls");
	}
	cout << "遊戲結束，謝謝遊玩。";
}