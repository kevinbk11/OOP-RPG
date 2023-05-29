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
		cout << "��J0�e���W�@�i�a�ϡA��J1�e���U�@�i�a��\n";
		Map* locate = player->getLocate();
		vector<FightableMob*> mobs = locate->getAllMob();
		cout << "�ثe�Ҧb�a:"<<locate->name<<endl;
		if (mobs.size() == 0)cout << "�o�̨S���Ǫ��C\n";
		for (int i = 0; i < mobs.size(); i++) {
			cout << "�Ǫ�" << i + 1 << ":" << mobs[i]->name<<endl;
		}
		int command;
		cin >> command;
		player->setLocate(locate->getNextMap());
		system("cls");
	}
	cout << "�C�������A���¹C���C";
}