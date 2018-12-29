#include "stdafx.h"
#include "LevelParser.h"

void LevelParser::parseMap(const std::string& filepath) {
	m_mapFile.open("./Maps/" + filepath + ".txt");
	std::string temp;
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

void LevelParser::parseObjects(const std::string& filepath) {

}

std::vector<int>& LevelParser::getMap() {
	return m_map;
}

const std::vector<LevelParser::ObjectInfo>& LevelParser::getObjects() const {
	return m_objects;
}
