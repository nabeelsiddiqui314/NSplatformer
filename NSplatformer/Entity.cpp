#include "stdafx.h"
#include "Entity.h"

void Entity::interactWithTile(const sf::Vector2f& tilePos, const sf::Vector2f& tileSize) {
	float x = this->getPos().x + this->getSize().x - tilePos.x;

	float y = this->getPos().y + this->getSize().y - tilePos.y;
	float oldY = m_oldPos.y + this->getSize().y - tilePos.y;

	if (y > 1 && oldY <= 1 && x != 0) {
		m_velocity.y = 0;
		this->setPos(this->getPos().x, tilePos.y - this->getSize().y);
		m_isJumping = false;
	}

	y = this->getPos().y - tilePos.y;
	oldY = m_oldPos.y - tilePos.y;

	if (y < tileSize.y && oldY >= tileSize.y && x != 0) {
		m_velocity.y = 0;
		this->setPos(this->getPos().x, tilePos.y + tileSize.y);
	}

	float oldX = m_oldPos.x + this->getSize().x - tilePos.x;

	y = this->getPos().y + this->getSize().y - tilePos.y;

	if (x > 1 && oldX <= 1 && y != 0) {
		m_velocity.x = 0;
		this->setPos(tilePos.x - this->getSize().x, this->getPos().y);
	}

	x = this->getPos().x - tilePos.x;
	oldX = m_oldPos.x - tilePos.x;

	if (x < tileSize.x && oldX >= tileSize.x && y != 0) {
		m_velocity.x = 0;
		this->setPos(tilePos.x + tileSize.x, this->getPos().y);
	}
}

const sf::Vector2f& Entity::getVelocity() const {
	return m_velocity;
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
		m_velocity.y -= this->calculateJumpPower();
		m_isJumping = true;
	}
}

bool Entity::isJumping() const {
	return m_isJumping;
}

const xDirection& Entity::getDirection() const {
	return m_direction;
}

float Entity::calculateJumpPower() {
	return sqrt(2 * Data::physConsts::gravity * p_jumpHeight);
}
