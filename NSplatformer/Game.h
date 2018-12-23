#pragma once
#include "State.h"
#include "StateManager.h"
#include "InputManager.h"
#include "Resources.h"

class Game : public State
{
public:
	Game();
public:
	void update(const sf::RenderWindow& window) override;
	void render(sf::RenderWindow& window) override;
private:
	
};

