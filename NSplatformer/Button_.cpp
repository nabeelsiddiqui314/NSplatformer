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

void Button_::update(const sf::RenderWindow& window) {
	switch (isSelected()) {
	case true:
		setColor(Data::Gui::highlighted.color());
		if (isHovering(window) && InputManager::isReleased(InputManager::MouseLeft)) {
			m_slot();
		}
		if (InputManager::isReleased(InputManager::Enter)) {
			m_slot();
		}
			break;
	case false:
		setColor(Data::Gui::white.color());
			break;
	}
}
