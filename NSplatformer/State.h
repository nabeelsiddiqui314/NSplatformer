#pragma once
#include <SFML/Graphics.hpp>

class State
{
public:
	State() {}
	virtual ~State() {}
public:
	virtual void handleInput ()                         {};
	virtual void update      ()                         {};
	virtual void render      (sf::RenderWindow& window) {};
};


