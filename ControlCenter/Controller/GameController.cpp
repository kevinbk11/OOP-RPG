#include "GameController.h"
#include "../../Utils/getExistIndex.h"
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
	cout << "遊戲開始\n";
	this->initMap();
	player->setLocate(this->mapObject->getRespawnPoint());
	while (true) {
		cout <<"輸入0前往上一張地圖\n\n輸入1前往下一張地圖\n\n";
		cout << "輸入2查看此處的怪物並選擇要戰鬥的怪物\n\n輸入3查看此處的NPC並選擇要對話的NPC\n\n";
		cout << "輸入4查看角色狀態\n\n";
		cout << "輸入5打開背包。\n\n";
		Map* locate = player->getLocate();
		cout << "目前所在地:"<<locate->name<<endl;
		int command;
		cin >> command;
		system("cls");
		switch (command) {
			case 0: {
				if (locate->getPreviousMap() == nullptr)cout << "沒有上一張地圖。\n\n";
				else player->setLocate(locate->getPreviousMap());
				break;
			}
			case 1: {
				if (locate->getNextMap() == nullptr)cout << "沒有下一張地圖。\n\n";
				else player->setLocate(locate->getNextMap());
				break;
			}
			case 2: {
				vector<Enemy*> mobs = locate->getAllMob();
				if (mobs.size() == 0)cout << "這裡沒有怪物。\n";
				else {
					cout << "請輸入怪物代碼來進入戰鬥，或者輸入0來離開。\n";
					for (int i = 0; i < mobs.size(); i++) {
						cout << "怪物" << i + 1 << ":" << mobs[i]->name << endl;
					}
					FightController *controller = ControlCenter::getInstance<FightController>();
					command = getExistIndex(mobs);
					if (command == -1)continue;
					controller->fight(player, mobs[command]);
					cout << endl;
				}
				break;
			}
			case 3: {
				vector<NPC*> NPCs = locate->getAllNPC();
				if (NPCs.size() == 0)cout << "這裡沒有NPC。\n";
				else {
					cout << "請輸入NPC代碼來進入對話。，或者輸入0返回\n";
					for (int i = 0; i < NPCs.size(); i++) {
						cout << "NPC." << i + 1 << ":" << NPCs[i]->name << endl;
					}
					InteractiveController* controller = ControlCenter::getInstance<InteractiveController>();
					command = getExistIndex(NPCs);
					if (command == -1)continue;
					controller->interactive(player, NPCs[command]);
					cout << endl;
				}
				break;
			}
			case 4: {
				player->printDetails();
				break;
			}
			case 5:{
				cout << "請輸入你要打開的背包，或者輸入0來返回\n\n";
				cout << "1.道具背包\n\n";
				cout << "2.裝備背包\n\n";
				vector<vector<Item*>> bag = player->getBag();
				int type = getExistIndex(bag);
				if (type == -1)continue;
				if (player->printBag(type)) {
					cout << "\n請輸入你要使用的道具編號，或者輸入0來取消\n\n";
					command = getExistIndex(bag[type]);
					if (command == -1)continue;
					player->useItem(command, type);
				}
				break;
			}
		}
	}
	cout << "遊戲結束，謝謝遊玩。\n";
}
Map* GameController::getPlayerRespawnPoint() {
	return this->mapObject->getRespawnPoint();
}
void GameController::setPlayerRespawnPoint(Map* map) {
	this->mapObject->setRespawnPoint(map);
}