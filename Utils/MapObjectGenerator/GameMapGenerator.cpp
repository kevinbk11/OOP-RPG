#include "GameMapGenerator.h"
GameMap GameMapGenerator::generate() {
	MapBuilder* builder = new MapBuilder();
	vector<Map*> maps = vector<Map*>();
	maps.push_back(builder->setName("�����")
		->createMap());
	maps.push_back(builder->setName("���1")
		->setMonster(new TestMonster1())
		->setMonster(new TestMonster1())
		->createMap());
	MapLinker* linker = new MapLinker();
	linker->link(maps);
	GameMap gameMap = GameMap();
	gameMap.setRespawnPoint(maps[0]);
	delete linker;
	delete builder;
	return gameMap;
}
