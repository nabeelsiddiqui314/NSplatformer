#pragma once
#include <vector>
#include <fstream>
#include "Data.h"

class LevelParser
{
public:
	struct ObjectInfo {
		ObjectInfo(int id_, const std::string& name_, const std::string& param_, const sf::Vector2f& pos_) :
			id(id_), 
			name(name_),
		    parameter(param_),
		    pos(pos_) {}
		int id;
		std::string name;
		std::string parameter;
		sf::Vector2f pos;
	};
public:
	~LevelParser();
	void parseMap(const std::string& name);
	void parseObjects(const std::string& name);

	const std::string& getTilesetName() const;
	const std::string& getBGName() const;
	const bool isYFixed() const;
	const sf::Vector2i& getDimensions() const;
	const sf::FloatRect& getGoalRegion() const;
	std::vector<int>& getMap();
	const std::vector<ObjectInfo>& getObjects() const;
private:
	std::ifstream m_mapFile;
	std::ifstream m_objFile;

	std::vector<int> m_map;
	std::vector<ObjectInfo> m_objects;

	std::string m_tilesetname;
	std::string m_BGname;
	bool m_isYfixed;
	sf::Vector2i m_dimensions;
	sf::FloatRect m_goal;
};

