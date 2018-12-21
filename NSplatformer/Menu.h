#pragma once
#include "State.h"
#include "StateManager.h"
#include "InputManager.h"
#include "Resources.h"
#include "GuiBox.h"

class Menu : public State
{
public:
	Menu();
public:
	void update(const sf::RenderWindow& window) override;
	void render(sf::RenderWindow& window) override;
private:
	GuiBox m_menuGui;
	sf::Music m_introMusic;
};

