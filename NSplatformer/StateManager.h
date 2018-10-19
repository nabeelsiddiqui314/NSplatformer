#pragma once
#include "State.h"

class StateManager
{
public:
	StateManager();
	~StateManager();
public:
	void setWindow(sf::RenderWindow& window);
	void setState(State* state);

	void update();
	void render();
private:
	sf::RenderWindow* m_window;
	State*            m_state;
};

extern StateManager stateManager;