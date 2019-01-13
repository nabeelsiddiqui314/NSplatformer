#include "stdafx.h"
#include "Entity.h"


Entity::Entity() {
	m_animation.setRect(&m_body);
}

void Entity::setPos(const sf::Vector2f& pos) {
	m_body.setPosition(pos);
}

const sf::Vector2f& Entity::getPos() const {
	return m_body.getPosition();
}

const sf::Vector2f& Entity::getOldPos() const {
	return m_oldPos;
}

const sf::Vector2f& Entity::getSize() const {
	return m_body.getSize();
}

void Entity::stopFall(float yPos) {
	m_velocity.y = 0;
	m_body.setPosition(m_body.getPosition().x, yPos);
	m_isJumping = false;
}

void Entity::stopJump(float yPos) {
	m_velocity.y = 0;
	m_body.setPosition(m_body.getPosition().x, yPos);
}

void Entity::stopLateral(float xPos) {
	m_velocity.x = 0;
	m_body.setPosition(xPos, m_body.getPosition().y);
}

bool Entity::isCollidingWith(Entity* entity) const {
	return m_body.getGlobalBounds().intersects(entity->m_body.getGlobalBounds());
}

void Entity::generalUpdate() {
	m_oldPos = m_body.getPosition();
	m_body.move(m_velocity);
	m_velocity.x *= m_friction;
	m_velocity.y += Data::physConsts::gravity;
}

void Entity::render(sf::RenderWindow& window) {
	window.draw(m_body);
}

void Entity::setTexture(const std::string& name) {
	m_body.setTexture(&Resources::textures.get(name));
}

void Entity::setSize(const sf::Vector2f& size) {
	m_body.setSize(size);
}

void Entity::walkLeft() {
	m_velocity.x -= m_acceleration;
	m_direction = Left;
}

void Entity::walkRight() {
	m_velocity.x += m_acceleration;
	m_direction = Right;
}

void Entity::jump() {
	if (!m_isJumping) {
		m_velocity.y -= m_jumpPower;
		m_isJumping = true;
	}
}