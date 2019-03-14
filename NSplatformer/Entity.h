#pragma once
#include "Data.h"
#include "Resources.h"
#include "Animation.h"

class Entity
{
protected:
	enum Direction {
		Right,
		Left
	};
public:
	Entity();
	virtual ~Entity() {}
public:
	void setPos(const sf::Vector2f& pos);
	const sf::Vector2f& getPos() const;
	const sf::Vector2f& getOldPos() const;
	const sf::Vector2f& getSize() const;
	void stopFall(float yPos);
	void stopJump(float yPos);
	void stopLateral(float xPos);
	bool isCollidingWith(Entity* entity) const;

	virtual void update() = 0;
	virtual void render(sf::RenderWindow& window);
	virtual void interact(Entity* entity) {}
protected:
	void setTexture(const std::string& name);
	void generalUpdate();
	void setSize(const sf::Vector2f& size);
	void walkRight();
	void walkLeft();
	void jump();
	bool isJumping();
	Direction getDirection() const;
protected:
	Animation p_animation;
	double p_acceleration = 4.8;
	double p_friction = 0.5;
	double p_jumpPower = 20;
private:
	sf::RectangleShape m_body;
	sf::Vector2f m_velocity = {0,0};
	sf::Vector2f m_oldPos;
	Direction m_direction;
	bool m_isJumping = true;
};