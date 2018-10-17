#include "stdafx.h"
#include "Map.h"


Map::Map() {
	m_map.setPrimitiveType(sf::Quads);
}

void Map::importTileset(const std::string& tilesetPath) {
	m_tileset.loadFromFile("./Tilesets/" + tilesetPath + ".png");

	int tileNumX = m_tileset.getSize().x / Data::tileSize;
	int tileNumY = m_tileset.getSize().y / Data::tileSize;

	for (int y = 0; y < tileNumY; y++) {
		for (int x = 0; x < tileNumX; x++) {
			Tile tile;
			tile.texPos.x = x * Data::tileSize;
			tile.texPos.y = y * Data::tileSize;
			m_tiles.push_back(tile);
		}
	}
}

void Map::importLevel(const std::string& levelPath) {
	m_levelFl.open("./Maps/" + levelPath + ".txt");
	std::string temp;
	std::getline(m_levelFl, temp);
	m_mapDims.x = std::stoi(temp, nullptr);
	std::getline(m_levelFl, temp);
	m_mapDims.y = std::stoi(temp, nullptr);
	while (std::getline(m_levelFl, temp)) {
		for (int i = 0; i < temp.length(); i++) {
			int tileid = 0;
			if (isdigit(temp[i])) {
				if (i + 1 != temp.length()) {
					if (isdigit(temp[i + 1])) {
						int digit1 = temp[i] - '0';
						int digit2 = temp[i + 1] - '0';
						tileid = digit1 * 10 + digit2;
					}
					else
						tileid = temp[i] - '0';
					i++;
				}
				if (tileid < 1 || tileid > m_tiles.size() - 1)  // checks whether the id is valid
					tileid = 0;
				m_lvl.emplace_back(tileid);
			}
		}
		if (m_lvl.size() < m_mapDims.x * m_mapDims.y) {
			for (int i = m_lvl.size(); i < m_mapDims.x * m_mapDims.y; i++) { //fills in tiles if less tiles are given
				m_lvl.emplace_back(0);
			}
		}
	}
}

void Map::load() {
	m_map.resize(m_mapDims.x * m_mapDims.y * 4);
	int i = 0;
	for (int y = 0; y < m_mapDims.y; y++ ) {
		for (int x = 0; x < m_mapDims.x; x++) {
			m_map[i].position     = sf::Vector2f( x * Data::tileSize, y * Data::tileSize );
			m_map[i + 1].position = sf::Vector2f( x * Data::tileSize + Data::tileSize, y * Data::tileSize );
			m_map[i + 2].position = sf::Vector2f( x * Data::tileSize + Data::tileSize, y * Data::tileSize + Data::tileSize );
			m_map[i + 3].position = sf::Vector2f( x * Data::tileSize, y * Data::tileSize + Data::tileSize );

			sf::Vector2f texCoord = m_tiles[m_lvl[x + y * m_mapDims.x]].texPos; //index of the tile is it's id

			m_map[i].texCoords     = sf::Vector2f( texCoord.x, texCoord.y);
			m_map[i + 1].texCoords = sf::Vector2f( texCoord.x + Data::tileSize, texCoord.y);
			m_map[i + 2].texCoords = sf::Vector2f( texCoord.x + Data::tileSize, texCoord.y + Data::tileSize );
			m_map[i + 3].texCoords = sf::Vector2f( texCoord.x, texCoord.y + Data::tileSize );

			i += 4;
		}
	}
}

void Map::render(sf::RenderWindow& window) {
	window.draw(m_map, &m_tileset);
}

void Map::handleCollisions(Entity* entity) {
	if (entity->getPos().y + entity->getSize().y > Data::tileSize * m_mapDims.y
		|| entity->getPos().x + entity->getSize().x > Data::tileSize * m_mapDims.x
		|| entity->getPos().y < 0
		|| entity->getPos().x < 0) {
		return;
	}

	int column = floor(entity->getPos().x / Data::tileSize);
	int row = floor(entity->getPos().y / Data::tileSize);
	int tile = m_lvl[column + row * m_mapDims.x];
	if (tile != 0)
	Collider::Collide(entity, tile, row, column);

	column = floor((entity->getPos().x + entity->getSize().x) / Data::tileSize);
	tile = m_lvl[column + row * m_mapDims.x];
	if (tile != 0) 
	Collider::Collide(entity, tile, row, column);

	column = floor(entity->getPos().x / Data::tileSize);
	row = floor((entity->getPos().y + entity->getSize().y) / Data::tileSize);
	tile = m_lvl[column + row * m_mapDims.x];
	if (tile != 0)
	Collider::Collide(entity, tile, row, column);

	column = floor((entity->getPos().x + entity->getSize().x) / Data::tileSize);
	tile = m_lvl[column + row * m_mapDims.x];
	Collider::Collide(entity, tile, row, column);
}

Map::~Map() {
	m_levelFl.close();
}