#pragma once
#include "Resources.h"
#include "InputManager.h"
#include "Button_.h"

class GuiBox
{
public:
	GuiBox();
public:
	void setPos(const sf::Vector2f& pos);

	void setTitle(const std::string& text);
	void addButton(const std::string& text, std::function<void()> slot);
	void addToggler(const std::string& text);

	void update(const sf::RenderWindow& window);
	void render(sf::RenderWindow& window);
private:
	sf::RectangleShape m_body;
	std::vector<std::shared_ptr<Gui_obj>> m_components;
};

