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
		cout << "Ū�����a���C";
		return;
	}
	cout << "�C���}�l\n";
	this->initMap();
	player->setLocate(this->mapObject.getRespawnPoint());
	while (true) {
		cout <<"��J0�e���W�@�i�a�ϡA��J1�e���U�@�i�a�ϡA��J2�d�ݦ��B���Ǫ��ÿ�ܭn�԰����Ǫ��C\n";
		Map* locate = player->getLocate();
		vector<FightableMob*> mobs = locate->getAllMob();
		cout << "�ثe�Ҧb�a:"<<locate->name<<endl;
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
				if (mobs.size() == 0)cout << "�o�̨S���Ǫ��C\n";
				else {
					cout << "�п�J�Ǫ��N�X�Ӷi�J�԰��C\n";
					for (int i = 0; i < mobs.size(); i++) {
						cout << "�Ǫ�" << i + 1 << ":" << mobs[i]->name << endl;
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
	cout << "�C�������A���¹C���C\n";
}
Map* GameController::getPlayerRespawnPoint() {
	return this->mapObject.getRespawnPoint();
}
void GameController::setPlayerRespawnPoint(Map* map) {
	this->mapObject.setRespawnPoint(map);
}