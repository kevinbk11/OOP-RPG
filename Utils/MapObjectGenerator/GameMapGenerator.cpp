#include "GameMapGenerator.h"
GameMap GameMapGenerator::generate() {
	MapBuilder* builder = new MapBuilder();
	vector<Map*> maps = vector<Map*>();
	maps.push_back(builder->setName("初心鎮")
		->setNPC(new Villager())
		->createMap());
	maps.push_back(builder->setName("草原1")
		->setMonster(new Wolf())
		->createMap());
	MapLinker* linker = new MapLinker();
	linker->link(maps);
	GameMap gameMap = GameMap();
	gameMap.setRespawnPoint(maps[0]);
	delete linker;
	delete builder;
	return gameMap;
}
