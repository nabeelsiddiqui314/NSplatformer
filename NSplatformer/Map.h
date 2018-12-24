#pragma once
#include "Resources.h"
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
	void importTileset(const std::string& tilesetName);
	void importLevel(const std::string& levelPath);
	void load();
	void render(sf::RenderWindow& window);

	void handleCollisions(Entity* entity) const;
private:
	sf::VertexArray m_map;
	std::vector<Tile> m_tiles;
	std::vector<int> m_lvl;
	std::ifstream m_levelFl;
	sf::Vector2i m_mapDims;
	std::string m_tilesetName;
};

