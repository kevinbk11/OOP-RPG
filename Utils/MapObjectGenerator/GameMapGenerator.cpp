#include "GameMapGenerator.h"
GameMap* GameMapGenerator::generate() {
	MapBuilder* builder = new MapBuilder();
	vector<Map*> maps = vector<Map*>();
	maps.push_back(builder->setName("初心鎮")
		->setNPC(new Villager())
		->createMap());
	maps.push_back(builder->setName("草原")
		->setMonster(new Pig())
		->createMap());
	maps.push_back(builder->setName("森林")
		->setMonster(new Wolf())
		->createMap());
	MapLinker* linker = new MapLinker();
	linker->link(maps);
	GameMap *gameMap = new GameMap(maps);
	gameMap->setRespawnPoint(maps[0]);
	delete linker;
	delete builder;
	return gameMap;
}
