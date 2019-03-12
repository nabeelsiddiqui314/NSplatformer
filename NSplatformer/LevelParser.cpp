#include "stdafx.h"
#include "LevelParser.h"


void LevelParser::parseMap(const std::string& name) {
	m_mapFile.open("./Levels/" + name + "/map.txt");
	std::string temp;
	std::getline(m_mapFile, temp);
	m_tilesetname = temp;
	std::getline(m_mapFile, temp);
	m_dimensions.x = std::stoi(temp, nullptr);
	std::getline(m_mapFile, temp);
	m_dimensions.y = std::stoi(temp, nullptr);
	while (std::getline(m_mapFile, temp)) {
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
				tileid--; // because tiled represents first tile as 1 rather than 0
				if (tileid < 1 || tileid > m_map.size() - 1)  // checks whether the id is valid
					tileid = 0;
				m_map.emplace_back(tileid);
			}
		}
		if (m_map.size() < m_dimensions.x * m_dimensions.y) {
			for (int i = m_map.size(); i < m_dimensions.x * m_dimensions.y; i++) { //fills in tiles if less tiles are given
				m_map.emplace_back(0);
			}
		}
	}
}

void LevelParser::parseObjects(const std::string& name) {
	m_objFile.open("Levels/" + name + "/obj.txt");
	std::string temp;

	auto setValue = [&](int line, int& val) { 
		for (int i = 0; i < line; i++) { // gets line
			std::getline(m_objFile, temp);
		}

		val = 0;
		int digitPlace = 1; //indicates the position of a digit 
		for (int i = temp.size() - 2; i > 0; i--) { // reads the value no matter how big
			if (isdigit(temp[i])) {
				val += (temp[i] - '0') * digitPlace;
				digitPlace *= 10;
			}
			else
				break;
		}
	};

		int id;
		int parameter;
		int x, y;
		int width, height;
	while (std::getline(m_objFile, temp)) {
		if (temp.substr(1, 3) == "gid") { // it is at evry starting point of an object data section
			setValue(0, id);
			setValue(8, parameter);
			setValue(6, x);
			setValue(1, y);

			ObjectInfo inf;
			inf.id = id;
			inf.parameter = parameter;
			inf.pos = {static_cast<float>(x), static_cast<float>(y)};
		}
		else if (temp.substr() == "height") {
			setValue(0, height);
			for (int i = 0; i < 2; i++) {
				std::getline(m_objFile, temp);
			}
			if (temp.substr(8, 4) == "Goal") {
				setValue(4, width);
				setValue(1, x);
				setValue(1, y);
				m_goal = {x, y, width, height};
			}
		}
	}
}

const std::string& LevelParser::getTilesetName() const {
	return m_tilesetname;
}

const sf::Vector2i& LevelParser::getDimensions() const {
	return m_dimensions;
}

const sf::FloatRect& LevelParser::getGoalRegion() const {
	return m_goal;
}

std::vector<int>& LevelParser::getMap() {
	return m_map;
}

const std::vector<LevelParser::ObjectInfo>& LevelParser::getObjects() const {
	return m_objects;
}

LevelParser::~LevelParser() {
	m_mapFile.close();
	m_objFile.close();
}
