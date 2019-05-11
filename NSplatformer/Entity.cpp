#include "stdafx.h"
#include "Entity.h"


Entity::Entity() {
	m_jumpPower = sqrt(2 * Data::physConsts::gravity * p_jumpHeight);
}

const sf::Vector2f& Entity::getOldPos() const {
	return m_oldPos;
}

const sf::Vector2f& Entity::getVelocity() const {
	return m_velocity;
}

const sf::Vector2f Entity::getCentre() const {
	return { this->getPos().x + this->getSize().x / 2,
			 this->getPos().y + this->getSize().y / 2 };
}

void Entity::stopFall(float yPos) {
	m_velocity.y = 0;
	this->setPos(this->getPos().x, yPos);
	m_isJumping = false;
}

void Entity::stopJump(float yPos) {
	m_velocity.y = 0;
	this->setPos(this->getPos().x, yPos);
}

void Entity::stopLateral(float xPos) {
	m_velocity.x = 0;
	this->setPos(xPos, this->getPos().y);
}

void Entity::generalUpdate() {
	m_oldPos = this->getPos();
	this->move(m_velocity);
	m_velocity.x *= p_friction;
	m_velocity.y += Data::physConsts::gravity;
	m_velocity.y = std::min(m_velocity.y, 10.0f);
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
		m_velocity.y -= m_jumpPower;
		m_isJumping = true;
	}
}

bool Entity::isJumping() const {
	return m_isJumping;
}

xDirection Entity::getDirection() const {
	return m_direction;
}