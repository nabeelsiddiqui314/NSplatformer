#include "stdafx.h"
#include "Spawner.h"

Spawner::Spawner(const std::string& name)
: Dynamic(name), m_parser(name) {
	m_spawnPos.x = std::stoi(m_parser.getValue("posX"));
	m_spawnPos.y = std::stoi(m_parser.getValue("posY"));
	m_dt = std::stoi(m_parser.getValue("dt"));
	m_gid = std::stoi(m_parser.getValue("type"));
	m_objName = m_parser.getValue("name");
	m_triggerTile.x = std::stoi(m_parser.getValue("tileX"));
	m_triggerTile.y = std::stoi(m_parser.getValue("tileY"));
	m_direction = m_parser.getValue("direction");
	m_isDestructible = m_parser.getValue("destructible") == "true";
	p_isFriendly = false;
	p_animation.setFrame(0,0, false, { this->getSize().x / 2, this->getSize().y });
	p_animation.update();
}

void Spawner::interactWithOther(Dynamic* other) {
	if (IDmanager::getObjectID(IDmanager::Objects::PLAYER) == other->getID()) {
		if (floor((other->getPos().x + other->getSize().x / 2) / Data::tile::size) == floor((this->getPos().x + (m_triggerTile.x * Data::tile::size)) / Data::tile::size) &&
			floor((other->getPos().y + other->getSize().y / 2) / Data::tile::size) == floor((this->getPos().y + (m_triggerTile.y * Data::tile::size)) / Data::tile::size))
			m_isInTile = true;
	}
}

void Spawner::recieveInt(int amount) {
	if (m_isDestructible) {
		this->destroy();
	}
}

int Spawner::getID() const {
	return IDmanager::getObjectID(IDmanager::Objects::SPAWNER);
}

void Spawner::update() {
	if (m_isInTile || (m_triggerTile.x == 0 && m_triggerTile.y == 0)) {
		p_animation.repeat(0, m_dt, false, { this->getSize().x, this->getSize().y });
		if (p_animation.getCurrentFrame() == p_animation.getLastFrame(0) && m_lastFrame == p_animation.getLastFrame(0) - 1) {
			this->addObject(IDmanager::getNewObj(m_gid, m_objName, m_direction), { m_spawnPos.x + this->getPos().x, m_spawnPos.y + this->getPos().y });
		}
	}
	else {
		p_animation.setFrame(0, 0, false, { this->getSize().x, this->getSize().y });
	}
	m_lastFrame = p_animation.getCurrentFrame();
	p_animation.update();
}