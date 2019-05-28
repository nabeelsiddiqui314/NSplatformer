#pragma once
#include "Dynamic.h"
#include "ObjectDataParser.h"
#include "IDmanager.h"

class Spawner : public Dynamic
{
public:
	Spawner(const std::string& name, const std::string& parameter);
public:
	void interactWithOther(Dynamic* other) override;
	void update() override;
private:
	ObjectDataParser m_parser;
	sf::Clock m_spawnClock;
	sf::Vector2f m_spawnPos;
	int m_spawnFrequency;
	unsigned int m_gid;
	std::string m_objName;
	std::string m_direction;
	sf::Vector2i m_triggerTile;
	bool m_isInTile = false;
};