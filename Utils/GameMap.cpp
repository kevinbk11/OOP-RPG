#include "GameMap.h"
void GameMap::setRespawnPoint(Map* map) {
	this->respawnPoint = map;
}
Map* GameMap::getRespawnPoint() {
	return this->respawnPoint;
}