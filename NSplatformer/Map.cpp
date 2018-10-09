#include "stdafx.h"
#include "Map.h"


Map::Map() {
	
}

void Map::importTileset(const std::string& tilesetPath) {
	if (!m_tileset.loadFromFile("./Tilesets/" + tilesetPath + ".png")) {
		m_tileset.loadFromFile("./Tilesets/NotDefined.png");
	}

	int tileNumX = m_tileset.getSize().x / Data::tileSize;
	int tileNumY = m_tileset.getSize().y / Data::tileSize;

	for (int y = 0; y < tileNumY; y++) {
		for (int x = 0; x < tileNumX; x++) {
			Tile tile;
			tile.pos.x = x * Data::tileSize;
			tile.pos.y = y * Data::tileSize;
			tile.id = x + y * tileNumY;
			m_tiles.push_back(tile);
		}
	}
}

void Map::importLevel(const std::string& levelPath) {
	m_levelFl.open("./Maps/" + levelPath + ".txt");
	std::string temp;
	while (std::getline(m_levelFl, temp)) {
		if (temp == "Width") {
			m_levelFl >> temp;
			m_mapDims.x = std::stoi(temp, nullptr);
		}
		else if (temp == "Height") {
			m_levelFl >> temp;
			m_mapDims.y = std::stoi(temp, nullptr);
		}
		else if (temp == "Level") {
			for (int i = 0; i < m_mapDims.x * m_mapDims.y; i++) {
				m_levelFl >> temp;
				m_lvl[i] = std::stoi(temp, nullptr);
			}
		}
	}
}

void Map::load() {
	
}

void Map::render() {
	
}

Map::~Map() {
	m_levelFl.close();
}