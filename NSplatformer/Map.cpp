#include "stdafx.h"
#include "Map.h"


Map::Map() {
	m_map.setPrimitiveType(sf::Quads);
}

void Map::getDimensions(const sf::Vector2i& dim) {
	m_dimensions = dim;
}

void Map::importTileset(const std::string& tilesetName) {
	m_tilesetName = tilesetName;
	int tileNumX = Resources::textures.get(m_tilesetName).getSize().x / Data::tileSize;
	int tileNumY = Resources::textures.get(m_tilesetName).getSize().y / Data::tileSize;

	for (int y = 0; y < tileNumY; y++) {
		for (int x = 0; x < tileNumX; x++) {
			Tile tile;
			tile.texPos.x = x * Data::tileSize;
			tile.texPos.y = y * Data::tileSize;
			m_tiles.push_back(tile);
		}
	}
}

void Map::importLevel(std::vector<int>& level) {
	m_lvl = &level;
}

void Map::load() {
	m_map.resize(m_dimensions.x * m_dimensions.y * 4);
	int i = 0;
	for (int y = 0; y < m_dimensions.y; y++ ) {
		for (int x = 0; x < m_dimensions.x; x++) {
			m_map[i].position     = sf::Vector2f( x * Data::tileSize, y * Data::tileSize );
			m_map[i + 1].position = sf::Vector2f( x * Data::tileSize + Data::tileSize, y * Data::tileSize );
			m_map[i + 2].position = sf::Vector2f( x * Data::tileSize + Data::tileSize, y * Data::tileSize + Data::tileSize );
			m_map[i + 3].position = sf::Vector2f( x * Data::tileSize, y * Data::tileSize + Data::tileSize );

			sf::Vector2f texCoord = m_tiles[m_lvl->at(x + y * m_dimensions.x)].texPos; //index of the tile is it's id

			m_map[i].texCoords     = sf::Vector2f( texCoord.x, texCoord.y);
			m_map[i + 1].texCoords = sf::Vector2f( texCoord.x + Data::tileSize, texCoord.y);
			m_map[i + 2].texCoords = sf::Vector2f( texCoord.x + Data::tileSize, texCoord.y + Data::tileSize );
			m_map[i + 3].texCoords = sf::Vector2f( texCoord.x, texCoord.y + Data::tileSize );

			i += 4;
		}
	}
}

void Map::render(sf::RenderWindow& window) {
	window.draw(m_map, &Resources::textures.get(m_tilesetName));
}

void Map::handleCollisions(Entity* entity) const {
	if (entity->getPos().y + entity->getSize().y > Data::tileSize * m_dimensions.y
		|| entity->getPos().x + entity->getSize().x > Data::tileSize * m_dimensions.x
		|| entity->getPos().y < 0
		|| entity->getPos().x < 0) {
		return;
	}

	int column = floor(entity->getPos().x / Data::tileSize);
	int row = floor(entity->getPos().y / Data::tileSize);
	int tile = m_lvl->at(column + row * m_dimensions.x);
	if (tile != 0)
	Collider::Collide(entity, tile, row, column);

	column = floor((entity->getPos().x + entity->getSize().x) / Data::tileSize);
	tile = m_lvl->at(column + row * m_dimensions.x);
	if (tile != 0) 
	Collider::Collide(entity, tile, row, column);

	column = floor(entity->getPos().x / Data::tileSize);
	row = floor((entity->getPos().y + entity->getSize().y) / Data::tileSize);
	tile = m_lvl->at(column + row * m_dimensions.x);
	if (tile != 0)
	Collider::Collide(entity, tile, row, column);

	column = floor((entity->getPos().x + entity->getSize().x) / Data::tileSize);
	tile = m_lvl->at(column + row * m_dimensions.x);
	Collider::Collide(entity, tile, row, column);
}