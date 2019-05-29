#include "stdafx.h"
#include "LevelParser.h"

void LevelParser::parseMap(const std::string& name) {
	m_mapFile.open(name);
	std::string temp;
	std::getline(m_mapFile, temp);
	m_tilesetname = temp;
	std::getline(m_mapFile, temp);
	m_dimensions.x = std::stoi(temp, nullptr);
	std::getline(m_mapFile, temp);
	m_dimensions.y = std::stoi(temp, nullptr);
	std::getline(m_mapFile, temp);
	m_BGname = temp;
	std::getline(m_mapFile, temp);
	m_isYfixed = temp == "true";
	while (std::getline(m_mapFile, temp)) {
		for (int i = 0; i < temp.length(); i++) {
			std::string tileid;
			while (isdigit(temp[i])) {
				tileid += temp[i];
				i++;
			}
			if (tileid != "") {
				m_map.emplace_back(std::stoi(tileid));
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
	m_objFile.open(name);
	std::string temp;

	auto getClearedLine = [&]() {
		temp.erase(std::remove(temp.begin(), temp.end(), ' '), temp.end());
	};

	auto doesContain = [&](const std::string& str) {
		return temp.find(str) != std::string::npos;
	};

	auto setValue = [&](int& val) { 
		getClearedLine();
		val = 0;
		std::string val_str;

		for (int i = 0; i < temp.size(); i++) {
			if (isdigit(temp[i])) {
				val_str += temp[i];
			}
		}
		if (val_str.size() == 0) {
			val = 0;
			return;
		}

		val = std::stoi(val_str);
	};

		int id;
		std::string obj_name;
		std::string parameter;
		int x, y;
		int gWidth, gHeight;
	while (std::getline(m_objFile, temp)) {
		if (doesContain("}"))
			continue;
		std::string type;
		if (doesContain("{")) {
			std::getline(m_objFile, temp);
			if (doesContain("gid")) {
				type = "obj";
				setValue(id);
			}
			else if (doesContain("height")) {
				type = "goal";
				setValue(gHeight);
			}
			else
				continue;
			while (std::getline(m_objFile, temp)) {
				if (doesContain("}"))
					break;
				getClearedLine();
				if (type == "obj") {
					if (doesContain("name"))
						obj_name = temp.substr(8, temp.size() - 10);
					if (doesContain("properties")) {
						while (std::getline(m_objFile, temp)) {
							getClearedLine();
							if (doesContain("}"))
								break;
							else if (doesContain("value"))
								parameter = temp.substr(9, temp.size() - 10);
						}
					}
					else if (doesContain("x"))
						setValue(x);
					else if (doesContain("y"))
						setValue(y);
				}
				else if (type == "goal") {
					if (doesContain("width"))
						setValue(gWidth);
					else if (doesContain("x"))
						setValue(x);
					else if (doesContain("y"))
						setValue(y);
				}
			}
			if (type == "obj")
				m_objects.emplace_back(id, obj_name, parameter, sf::Vector2f(x, y));
			else if (type == "goal")
				m_goal = {(float)x, (float)y, (float)gWidth, (float)gHeight};
		}
	}
}

const std::string& LevelParser::getTilesetName() const {
	return m_tilesetname;
}

const std::string& LevelParser::getBGName() const {
	return m_BGname;
}

const bool LevelParser::isYFixed() const {
	return m_isYfixed;
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
