#pragma once
#include <SFML/Graphics.hpp>

class State
{
public:
	State() {}
	virtual ~State() {}
public:
	virtual void update (const sf::RenderWindow& window) {};
	virtual void render (sf::RenderWindow& window) {};
};