#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Data.h"
#include "Collider.h"

class Map
{
private:
	struct Tile {
		sf::Vector2f texPos;
	};
public:
	Map();
	~Map();
public:
	void importTileset(const std::string& tilesetPath);
	void importLevel(const std::string& levelPath);
	void load();
	void render(sf::RenderWindow& window);

	void handleCollisions(Entity* entity);
private:
	sf::VertexArray m_map;
	sf::Texture m_tileset;
	std::vector<Tile> m_tiles;
	std::vector<int> m_lvl;
	std::ifstream m_levelFl;
	sf::Vector2i m_mapDims;
};
