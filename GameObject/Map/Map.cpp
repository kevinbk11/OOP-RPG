#include "Map.h"
Map::Map() {
	this->mobList = vector<FightableMob*>();
}
void Map::setNextMap(Map* map) {
	this->nextMap = map;
}
void Map::setPreviousMap(Map* map) {
	this->prevMap = map;
}
Map* Map::getNextMap() {
	return this->nextMap;
}
Map* Map::getPreviousMap() {
	return this->prevMap;
}
vector<FightableMob*> Map::getAllMob() {
	return this->mobList;
}
void Map::addMonster(FightableMob* monster) {
	this->mobList.push_back(monster);
}
