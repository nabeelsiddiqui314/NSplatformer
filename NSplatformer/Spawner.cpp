#include "stdafx.h"
#include "Spawner.h"

Spawner::Spawner(const std::string& name, const std::string& parameter)
: Dynamic(name), m_parser(name) {
	m_spawnPos.x = std::stoi(m_parser.getValue("posX"));
	m_spawnPos.y = std::stoi(m_parser.getValue("posY"));
	m_spawnFrequency = std::stoi(m_parser.getValue("frequency"));
	m_gid = std::stoi(m_parser.getValue("type"));
	m_objName = m_parser.getValue("name");
	m_triggerTile.x = std::stoi(m_parser.getValue("tileX"));
	m_triggerTile.y = std::stoi(m_parser.getValue("tileY"));
	m_direction = parameter;
}

void Spawner::interactWithOther(Dynamic* other) {
	if (IDmanager::getObjectID(IDmanager::Objects::PLAYER) == other->getID()) {
		m_isInTile = (floor(other->getPos().x + other->getSize().x) / 2 == floor(other->getPos().x + other->getSize().x / 2 + m_triggerTile.x * Data::tile::size) &&
			floor(other->getPos().y + other->getSize().y / 2) == floor(other->getPos().y + other->getSize().y / 2 + m_triggerTile.y * Data::tile::size));
	}
}

void Spawner::update() {
	if (m_isInTile) {
		if (m_spawnClock.getElapsedTime().asMilliseconds() > m_spawnFrequency) {
			this->addObject(IDmanager::getNewObj(m_gid, m_objName, m_direction), m_spawnPos);
			m_spawnClock.restart();
		}
	}
}