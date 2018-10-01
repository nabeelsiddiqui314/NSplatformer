#include "stdafx.h"
#include "Entity.h"


Entity::Entity() : p_velocity({0,0}) {
}

void Entity::setPos(const sf::Vector2f & pos) {
	m_body.setPosition(pos);
}

const sf::Vector2f& Entity::getPos() const {
	return m_body.getPosition();
}

const sf::Vector2f& Entity::getSize() const {
	return m_body.getSize();
}

void Entity::update() {

}

void Entity::setSize(const sf::Vector2f& size) {
	m_body.setSize(size);
}
