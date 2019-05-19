#include "stdafx.h"
#include "Projectile.h"

Projectile::Projectile(const std::string& name, float velocity, int damage, bool friendly) 
	: Dynamic(name) {
	m_translation = velocity;
	p_isFriendly = friendly;
	m_damage = damage;
}

void Projectile::setDirection(const xDirection& dir) {
	if (dir == xDirection::RIGHT) {
		this->setTextureRect({ 0,0, (int)getSize().x, (int)getSize().y }, { 0,0 });
	}
	else {
		this->setTextureRect({ (int)getSize().x, 0, -(int)getSize().x, (int)getSize().y }, { 0,0 });
		m_translation *= -1;
	}

}

void Projectile::interactWithTile(const sf::Vector2f& tilePos, const sf::Vector2f& tileSize) {
	this->destroy();
}

void Projectile::interactWithOther(Dynamic* other) {
	if (this->isFriendly() != other->isFriendly()) {
		if (this->isCollidingOther(other)) {
			other->takeDamage(m_damage);
			this->destroy();
		}
	}
}

void Projectile::update() {
	this->move({ m_translation, 0 });
}