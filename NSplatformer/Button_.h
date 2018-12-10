#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include "InputManager.h"

class Button_
{
public:
	Button_();
public:
	void setPos(const sf::Vector2f& pos);
	const sf::Vector2f& getPos() const;

	void setLabel(const std::string& label);
	void setSlot(std::function<void()> slot);

	void update(const sf::RenderWindow& window);
	void render(sf::RenderWindow& window);
private:
	sf::Text m_button;
	std::function<void()> m_slot;
};

