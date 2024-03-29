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
	const sf::Vector2f& getSize() const;

	void setTitle(const std::string& text);
	void addButton(const std::string& text, std::function<void()> slot);
	void addToggler(const std::string& text);

	void update(const sf::RenderWindow& window);
	void render(sf::RenderWindow& window);
private:
	void placeComponent(std::shared_ptr<Gui_obj> component);
private:
	sf::Text m_title;
	sf::RectangleShape m_body;
	std::vector<std::shared_ptr<Gui_obj>> m_components;
	int m_selectedIndex = 0;
};

