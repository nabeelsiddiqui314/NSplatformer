#pragma once
#include "Dynamic.h"
#include "Data.h"
#include "Direction.h"
#include "ObjectDataParser.h"

class Entity : public Dynamic
{
private:
	struct Attributes {
		int health;
		int damage;
		int agility;
	} m_attr;
public:
	Entity(const std::string& name);
public:
	void interactWithTile(const sf::Vector2f& tilePos, const sf::Vector2f& tileSize) override;

	const sf::Vector2f& getVelocity() const;
	bool isJumping() const;
	const xDirection& getDirection() const;
protected:
	void generalUpdate();
	void walk(const xDirection& dir);
	void jump();
	void damageOther(Dynamic* other);
	void loseHealth(int damage);
private:
	float calculateJumpPower();
protected: //defaults
	double p_acceleration = 2.8;
	double p_friction = 0.5;
	double p_jumpHeight = 128;
private:
	ObjectDataParser m_attrParser;
	sf::Vector2f m_velocity = {0,0};
	sf::Vector2f m_oldPos;
	xDirection m_direction;
	bool m_isJumping = true;
};