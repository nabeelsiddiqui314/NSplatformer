#include "stdafx.h"
#include "Button_.h"


Button_::Button_() {
	init();
}

void Button_::setLabel(const std::string& label) {
	setString(label);
}

void Button_::setSlot(std::function<void()> slot) {
	m_slot = slot;
}

void Button_::update() {
	switch (isSelected()) {
	case true:
		setColor(sf::Color(224, 98, 35));
		if (InputManager::isReleased(InputManager::MouseLeft) || InputManager::isReleased(InputManager::Enter)) {
			m_slot();
		}
			break;
	case false:
		setColor(sf::Color(222, 222, 237));
			break;
	}
}
