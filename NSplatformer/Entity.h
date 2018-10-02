#pragma once
#include <SFML/Graphics.hpp>
#include "Data.h"

class Entity
{
public:
	Entity();
public:
	void setPos(const sf::Vector2f& pos);
	const sf::Vector2f& getPos() const;
	const sf::Vector2f& getSize() const;
	void stopFall(float yPos);
	void update();
	void render(sf::RenderWindow& window);
protected:
	void setSize(const sf::Vector2f& size);
	void walkRight();
	void walkLeft();
	void jump();
private:
	sf::RectangleShape m_body;
	sf::Vector2f m_velocity;
	bool m_isJumping;
	double m_acceleration;
	double m_friction;
	double m_jumpPower;
};