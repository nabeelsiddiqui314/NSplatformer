#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
public:
	Entity();
public:
	void setPos(const sf::Vector2f& pos);
	const sf::Vector2f& getPos() const;
	const sf::Vector2f& getSize() const;
	void update();
protected:
	void setSize(const sf::Vector2f& size);
	void walk();
protected:
	sf::Vector2f p_velocity;
	bool p_isJumping = false;
	float p_acceleration = 0.7;
	float p_friction = 0.3;
private:
	sf::RectangleShape m_body;
};

