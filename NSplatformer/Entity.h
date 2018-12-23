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
public:
	void setPos(const sf::Vector2f& pos);
	const sf::Vector2f& getPos() const;
	const sf::Vector2f& getOldPos() const;
	const sf::Vector2f& getSize() const;
	void stopFall(float yPos);
	void stopJump(float yPos);
	void stopLateral(float xPos);
	virtual void update() = 0;
	virtual void render(sf::RenderWindow& window);
protected:
	void setTexture(const std::string& name);
	void generalUpdate();
	void setSize(const sf::Vector2f& size);
	void walkRight();
	void walkLeft();
	void jump();
protected:
	Animation m_animation;
	Direction m_direction;
	double m_acceleration = 4.8;
	double m_friction = 0.5;
	double m_jumpPower = 20;
	bool m_isJumping = true;
private:
	sf::RectangleShape m_body;
	sf::Vector2f m_velocity = {0,0};
	sf::Vector2f m_oldPos;
};