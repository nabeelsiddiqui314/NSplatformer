#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include "InputManager.h"
#include "Gui_obj.h"

class Button_ : Gui_obj
{
public:
	Button_();
public:
	void setLabel(const std::string& label);
	void setSlot(std::function<void()> slot);
	void update(const sf::RenderWindow& window) override;
private:
	std::function<void()> m_slot;
};

