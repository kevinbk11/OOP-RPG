#include "MapBuilder.h"

MapBuilder::MapBuilder() {
	map = new Map();
}
MapBuilder* MapBuilder::setMonster(Enemy* mob) {
	this->map->addMonster(mob);
	return this;
}
MapBuilder* MapBuilder::setName(string name) {
	this->map->name=name;
	return this;
}
MapBuilder* MapBuilder::setNPC(NPC* npc) {
	this->map->addNPC(npc);
	return this;
}
Map* MapBuilder::createMap() {
	Map* map = this->map;
	this->map = new Map();
	return map;
}
