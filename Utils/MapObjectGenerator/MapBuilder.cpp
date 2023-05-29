#include "MapBuilder.h"

MapBuilder::MapBuilder() {
	map = new Map();
}
MapBuilder* MapBuilder::setMonster(FightableMob* mob) {
	this->map->addMonster(mob);
	return this;
}
MapBuilder* MapBuilder::setName(string name) {
	this->map->name=name;
	return this;
}
Map* MapBuilder::createMap() {
	Map* map = this->map;
	this->map = new Map();
	return map;
}
