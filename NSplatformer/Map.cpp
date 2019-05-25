#include "stdafx.h"
#include "Map.h"


Map::Map() {
	m_map.setPrimitiveType(sf::Quads);
}

void Map::setDimensions(const sf::Vector2i& dim) {
	m_dimensions = dim;
}

void Map::importTileset(const std::string& tilesetName) {
	m_tilesetName = tilesetName;
	int tileNumX = Resources::textures.get(m_tilesetName).getSize().x / Data::tile::size;
	int tileNumY = Resources::textures.get(m_tilesetName).getSize().y / Data::tile::size;

	for (int y = 0; y < tileNumY; y++) {
		for (int x = 0; x < tileNumX; x++) {
			Tile tile;
			tile.texPos.x = x * Data::tile::size;
			tile.texPos.y = y * Data::tile::size;
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
			m_map[i].position     = sf::Vector2f( x * Data::tile::size, y * Data::tile::size );
			m_map[i + 1].position = sf::Vector2f( x * Data::tile::size + Data::tile::size, y * Data::tile::size );
			m_map[i + 2].position = sf::Vector2f( x * Data::tile::size + Data::tile::size, y * Data::tile::size + Data::tile::size );
			m_map[i + 3].position = sf::Vector2f( x * Data::tile::size, y * Data::tile::size + Data::tile::size );

			if (m_lvl->at(x + y * m_dimensions.x) == 0) {
				m_map[i].color = sf::Color::Transparent;
				m_map[i + 1].color = sf::Color::Transparent;
				m_map[i + 2].color = sf::Color::Transparent;
				m_map[i + 3].color = sf::Color::Transparent;
				i += 4;
				continue;
			}


			sf::Vector2f texCoord = m_tiles[m_lvl->at(x + y * m_dimensions.x) - 1].texPos; //index of the tile is it's id

			m_map[i].texCoords     = sf::Vector2f( texCoord.x, texCoord.y);
			m_map[i + 1].texCoords = sf::Vector2f( texCoord.x + Data::tile::size, texCoord.y);
			m_map[i + 2].texCoords = sf::Vector2f( texCoord.x + Data::tile::size, texCoord.y + Data::tile::size );
			m_map[i + 3].texCoords = sf::Vector2f( texCoord.x, texCoord.y + Data::tile::size );

			i += 4;
		}
	}
}

void Map::render(sf::RenderWindow& window) {
	window.draw(m_map, &Resources::textures.get(m_tilesetName));
}

void Map::handleCollisions(Dynamic* obj) const {
	if (obj->getPos().y + obj->getSize().y > Data::tile::size * m_dimensions.y
		|| obj->getPos().x + obj->getSize().x > Data::tile::size * m_dimensions.x
		|| obj->getPos().y < 0
		|| obj->getPos().x < 0) {
		return;
	}

	//Tesing the TOP
	int row = floor(obj->getPos().y / Data::tile::size);
	int column = floor(obj->getPos().x / Data::tile::size);
	int tile = m_lvl->at(column + row * m_dimensions.x);
	if (tile != 0)
		Collider::Collide(obj, tile, row, column);

	column = floor((obj->getPos().x + obj->getSize().x / 2) / Data::tile::size);
	tile = m_lvl->at(column + row * m_dimensions.x);
	if (tile != 0)
		Collider::Collide(obj, tile, row, column);

	column = floor((obj->getPos().x + obj->getSize().x) / Data::tile::size);
	tile = m_lvl->at(column + row * m_dimensions.x);
	if (tile != 0) 
		Collider::Collide(obj, tile, row, column);

	// Testing the BOTTOM
	row = floor((obj->getPos().y + obj->getSize().y) / Data::tile::size);
	column = floor(obj->getPos().x / Data::tile::size);
	tile = m_lvl->at(column + row * m_dimensions.x);
	if (tile != 0)
		Collider::Collide(obj, tile, row, column);

	column = floor((obj->getPos().x + obj->getSize().x / 2) / Data::tile::size);
	tile = m_lvl->at(column + row * m_dimensions.x);
	if (tile != 0)
		Collider::Collide(obj, tile, row, column);

	column = floor((obj->getPos().x + obj->getSize().x) / Data::tile::size);
	tile = m_lvl->at(column + row * m_dimensions.x);
	if (tile != 0)
		Collider::Collide(obj, tile, row, column);

	//Testing the LEFT
	column = column = floor(obj->getPos().x / Data::tile::size);
	row = floor(obj->getPos().y / Data::tile::size);
	tile = m_lvl->at(column + row * m_dimensions.x);
	if (tile != 0)
		Collider::Collide(obj, tile, row, column);

	row = floor((obj->getPos().y + obj->getSize().y / 2) / Data::tile::size);
	tile = m_lvl->at(column + row * m_dimensions.x);
	if (tile != 0)
		Collider::Collide(obj, tile, row, column);

	row = floor((obj->getPos().y + obj->getSize().y) / Data::tile::size);
	tile = m_lvl->at(column + row * m_dimensions.x);
	if (tile != 0)
		Collider::Collide(obj, tile, row, column);

	//Testing the RIGHT
	column = floor((obj->getPos().x + obj->getSize().x) / Data::tile::size);
	row = floor(obj->getPos().y / Data::tile::size);
	tile = m_lvl->at(column + row * m_dimensions.x);
	if (tile != 0)
		Collider::Collide(obj, tile, row, column);

	row = floor((obj->getPos().y + obj->getSize().y / 2) / Data::tile::size);
	tile = m_lvl->at(column + row * m_dimensions.x);
	if (tile != 0)
		Collider::Collide(obj, tile, row, column);

	row = floor((obj->getPos().y + obj->getSize().y) / Data::tile::size);
	tile = m_lvl->at(column + row * m_dimensions.x);
	if (tile != 0)
		Collider::Collide(obj, tile, row, column);
}