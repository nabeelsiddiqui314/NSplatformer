#pragma once
#include "Dynamic.h"
#include "ObjectDataParser.h"
#include "IDmanager.h"

class Spawner : public Dynamic
{
public:
	Spawner(const std::string& name);
public:
	void interactWithOther(Dynamic* other) override;
	int getID() const override;
	void update() override;
private:
	ObjectDataParser m_parser;
	sf::Vector2f m_spawnPos;
	int m_dt;
	unsigned int m_gid;
	int m_lastFrame = 0;
	std::string m_objName;
	std::string m_direction;
	sf::Vector2i m_triggerTile;
	bool m_isInTile = false;
};