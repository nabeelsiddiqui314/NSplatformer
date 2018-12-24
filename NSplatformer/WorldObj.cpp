#include "stdafx.h"
#include "WorldObj.h"

void WorldObj::setPos(const sf::Vector2f& pos) {
	m_body.setPosition(pos);
}

const sf::Vector2f& WorldObj::getPos() const {
	return m_body.getPosition();
}

const sf::Vector2f& WorldObj::getSize() const {
	return m_body.getSize();
}

bool WorldObj::isCollidingEntity(Entity* entity) const {
	return m_body.getGlobalBounds().intersects({entity->getPos(), entity->getSize()});
}

void WorldObj::render(sf::RenderWindow& window) {
	window.draw(m_body);
}

void WorldObj::setTexture(const std::string& name) {
	m_body.setTexture(&Resources::textures.get(name));
}

void WorldObj::setSize(const sf::Vector2f& size) {
	m_body.setSize(size);
}