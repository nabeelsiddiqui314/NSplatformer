#pragma once
#include "Dynamic.h"
#include "Data.h"
#include "Direction.h"

class Entity : public Dynamic
{
public:
	Entity();
	virtual ~Entity() {}
public:
	void interactWithTile(const sf::Vector2f& tilePos, const sf::Vector2f& tileSize) override;

	const sf::Vector2f& getVelocity() const;
	const sf::Vector2f getCentre() const;
	bool isJumping() const;
	xDirection getDirection() const;
protected:
	void generalUpdate();
	void walkRight();
	void walkLeft();
	void jump();
protected: //defaults
	double p_acceleration = 2.8;
	double p_friction = 0.5;
	double p_jumpHeight = 128;
private:
	sf::Vector2f m_velocity = {0,0};
	sf::Vector2f m_oldPos;
	xDirection m_direction;
	bool m_isJumping = true;
	double m_jumpPower;
};