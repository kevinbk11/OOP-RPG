#include "GameMap.h"
GameMap::GameMap(vector<Map*> maps) {
	this->allMap = maps;
}
void GameMap::setRespawnPoint(Map* map) {
	this->respawnPoint = map;
}
Map* GameMap::getRespawnPoint() {
	return this->respawnPoint;
}
vector<Map*> GameMap::getAllMap() {
	return this->allMap;
}