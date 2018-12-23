#include "stdafx.h"
#include "Entity.h"


Entity::Entity() 
	: m_velocity({0,0})
	, m_isJumping(true)
	, m_acceleration(4.8)
	, m_friction(0.5)
	, m_jumpPower(20) {
	m_body.setFillColor(sf::Color::Red);
}

void Entity::setPos(const sf::Vector2f & pos) {
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

void Entity::generalUpdate() {
	m_oldPos = m_body.getPosition();
	m_body.move(m_velocity);
	m_velocity.x *= m_friction;
	m_velocity.y += Data::gravity;
}

void Entity::render(sf::RenderWindow& window) {
	window.draw(m_body);
}

void Entity::setSize(const sf::Vector2f& size) {
	m_body.setSize(size);
}

void Entity::walkLeft() {
	m_velocity.x -= m_acceleration;
}


void Entity::walkRight() {
	m_velocity.x += m_acceleration;
}

void Entity::jump() {
	if (!m_isJumping) {
		m_velocity.y -= m_jumpPower;
		m_isJumping = true;
	}
}