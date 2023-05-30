#include "Map.h"
Map::Map() {
	this->mobList = vector<Enemy*>();
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
vector<Enemy*> Map::getAllMob() {
	return this->mobList;
}
vector<NPC*> Map::getAllNPC() {
	return this->NPCList;
}
void Map::addMonster(Enemy* monster) {
	this->mobList.push_back(monster);
}
void Map::addNPC(NPC* npc) {
	this->NPCList.push_back(npc);
}
