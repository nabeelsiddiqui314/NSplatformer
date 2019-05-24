#include "stdafx.h"
#include "Entity.h"

Entity::Entity(const std::string& name) : Dynamic(name) {
	m_attributeFile.open("data/attributes/" + name + ".txt");
	std::string temp;
	while (std::getline(m_attributeFile, temp)) {
		if (temp == "health") {
			std::getline(m_attributeFile, temp);
			m_attr.health = std::stoi(temp);
		}
		else if (temp == "damage") {
			std::getline(m_attributeFile, temp);
			m_attr.damage = std::stoi(temp);
		}
		else if (temp == "agility") {
			std::getline(m_attributeFile, temp);
			m_attr.agility = std::stoi(temp);
		}
	}
}

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
	m_velocity.x = 0;
	m_velocity.y += Data::physConsts::gravity;
	m_velocity.y = std::min(m_velocity.y, 10.0f);
	if (m_attr.health <= 0)
		this->destroy();
}

void Entity::walk(const xDirection& dir) {
	if (dir == xDirection::RIGHT) {
		m_velocity.x = m_attr.agility;
	}
	else {
		m_velocity.x = -m_attr.agility;
	}
	m_direction = dir;
}

void Entity::jump() {
	if (!m_isJumping) {
		m_velocity.y -= this->calculateJumpPower();
		m_isJumping = true;
	}
}

void Entity::damageOther(Dynamic* other) {
	other->takeDamage(m_attr.damage);
}

void Entity::loseHealth(int damage) {
	m_attr.health -= damage;
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
