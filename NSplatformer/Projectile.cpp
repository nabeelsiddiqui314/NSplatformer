#include "stdafx.h"
#include "Projectile.h"


Projectile::Projectile() {

}

void Projectile::setType(const ProjectileType& type) {
	m_type = type;
	switch (type) {
		
	}
}

void Projectile::setTranslation(const xDirection& xDir, const yDirection& yDir, float velocity) {
	m_translation.x = static_cast<int>(xDir) * velocity;
	m_translation.y = static_cast<int>(yDir) * velocity;
}

const Projectile::ProjectileType& Projectile::getType() const {
	return m_type;
}

void Projectile::interactWithTile(const sf::Vector2f& tilePos, const sf::Vector2f& tileSize) {
	this->destroy();
}

void Projectile::update() {
	this->move(m_translation);
}