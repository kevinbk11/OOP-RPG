#include "CreateHeroController.h"
CreateHeroController::CreateHeroController() {}
CreateHeroController* CreateHeroController::controller = nullptr;
CreateHeroController* CreateHeroController::getInstance() {
	if (controller == nullptr) {
		controller = new CreateHeroController();
	}
	return controller;
}
enum HeroCode {
	FIGHTER=1,
	MAGICIAN=2
};
Player* CreateHeroController::createPlayer(string name,int command) {
	switch (command) {
	case HeroCode::FIGHTER:
		Player* player = new Fighter(name);
		return player;
	}
}