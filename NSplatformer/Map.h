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
public:
	void setDimensions(const sf::Vector2i& dim);
	void importTileset(const std::string& tilesetName);
	void importLevel(std::vector<int>& level);
	void load();
	void render(sf::RenderWindow& window);

	void handleCollisions(Entity* entity) const;
private:
	sf::VertexArray m_map;
	std::vector<Tile> m_tiles;
	std::vector<int>* m_lvl;
	sf::Vector2i m_dimensions;
	std::string m_tilesetName;
};

