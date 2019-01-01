#pragma once
#include <vector>
#include <fstream>
#include "Data.h"

class LevelParser
{
public:
	struct ObjectInfo {
		int id;
		int parameter;
		sf::Vector2f pos;
	};
public:
	void parseMap(const std::string& name);
	void parseObjects(const std::string& name);

	const std::string& getTilesetName() const;
	const sf::Vector2i& getDimensions() const;
	std::vector<int>& getMap();
	const std::vector<ObjectInfo>& getObjects() const;
private:
	std::ifstream m_mapFile;
	std::ifstream m_objFile;

	std::vector<int> m_map;
	std::vector<ObjectInfo> m_objects;

	std::string m_tilesetname;
	sf::Vector2i m_dimensions;
};

