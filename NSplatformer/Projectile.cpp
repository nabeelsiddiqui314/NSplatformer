#include "stdafx.h"
#include "Projectile.h"

Projectile::Projectile(const std::string& name, const std::string& parameter)
	: Dynamic(name), m_parser(name) {
	m_translation = std::stoi(m_parser.getValue("velocity"));
	p_isFriendly = m_parser.getValue("friend") == "true";
	m_damage = std::stoi(m_parser.getValue("damage"));
	if (parameter == "right") {
		m_direction = xDirection::RIGHT;
	}
	else {
		m_direction = xDirection::LEFT;
	}
}

int Projectile::getID() const {
	return static_cast<int>(IDmanager::Objects::PROJECTILE);
}

void Projectile::interactWithTile(const sf::Vector2f& tilePos, const sf::Vector2f& tileSize) {
	this->destroy();
}

void Projectile::interactWithOther(Dynamic* other) {
	if (this->isFriendly() != other->isFriendly()) {
		if (this->isCollidingOther(other)) {
			//other->takeDamage(m_damage);
			this->destroy();
		}
	}
}

void Projectile::update() {
	if (m_direction == xDirection::RIGHT) {
		this->setTextureRect({ 0,0, (int)getSize().x, (int)getSize().y }, { 0,0 });
	}
	else {
		this->setTextureRect({ (int)getSize().x, 0, -(int)getSize().x, (int)getSize().y }, { 0,0 });
		m_translation = -1 * abs(m_translation);
	}
	this->move({ m_translation, 0 });
}