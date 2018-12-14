#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include "InputManager.h"
#include "Button_.h"

class GuiBox
{
public:
	GuiBox();
public:
	void setPos(const sf::Vector2f& pos);

	void setTitle(const std::string& text);
	void addButton(const std::string& text);
	void addToggler(const std::string& text);
private:
	sf::RectangleShape m_body;
	sf::Font m_font;
	std::vector<std::shared_ptr<Gui_obj>> m_components;
};

