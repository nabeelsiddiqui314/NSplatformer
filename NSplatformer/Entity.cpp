#include "stdafx.h"
#include "Entity.h"


Entity::Entity() {
	p_animation.setRect(&m_body);
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

const sf::Vector2f Entity::getCentre() const {
	return { m_body.getPosition().x + m_body.getSize().x / 2,
			 m_body.getPosition().y + m_body.getSize().y / 2 };
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
	m_velocity.x *= p_friction;
	m_velocity.y += Data::physConsts::gravity;
	m_velocity.y *= 0.9;
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
	m_velocity.x -= p_acceleration;
	m_direction = xDirection::LEFT;
}

void Entity::walkRight() {
	m_velocity.x += p_acceleration;
	m_direction = xDirection::RIGHT;
}

void Entity::jump() {
	if (!m_isJumping) {
		m_velocity.y -= p_jumpPower;
		m_isJumping = true;
	}
}

bool Entity::isJumping() const {
	return m_isJumping;
}

xDirection Entity::getDirection() const {
	return m_direction;
}
