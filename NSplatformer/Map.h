#pragma once
#include <SFML/Graphics.hpp>

class Map
{
private:
	struct Tile {
		float tLeft,
			tRight,
			bLeft,
			bRight;
		int id;
	};
public:
	Map();
public:
	void importTileset(const std::string& tilesetPath);
	void importLevel(const std::string& levelPath);
	void load();
	void render();
private:
	sf::VertexArray m_map;
	sf::Texture m_tileset;
	std::vector<Tile> m_tiles;
	std::vector<int> m_tileIDs;
};

