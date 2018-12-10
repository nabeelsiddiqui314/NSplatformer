#include "stdafx.h"
#include "Button_.h"


Button_::Button_() {
	//m_button.setCharacterSize();
	m_button.setOutlineThickness(1);
	m_button.setOutlineColor(sf::Color::Black);
	m_button.setFillColor(sf::Color(222, 222, 237));
}

void Button_::setPos(const sf::Vector2f& pos) {
	m_button.setPosition(pos);
}

const sf::Vector2f& Button_::getPos() const {
	return m_button.getPosition();
}

void Button_::setLabel(const std::string& label) {
	m_button.setString(label);
}

void Button_::setSlot(std::function<void()> slot) {
	m_slot = slot;
}

void Button_::update(const sf::RenderWindow& window) {
	bool isHovering = m_button.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
	switch (isHovering) {
	case true:
		m_button.setFillColor(sf::Color(224, 98, 35));
		if (InputManager::isReleased(InputManager::MouseLeft) || InputManager::isClicked(InputManager::Enter)) {
			m_slot();
		}
			break;
	case false:
		m_button.setFillColor(sf::Color(222, 222, 237));
			break;
	}
}

void Button_::render(sf::RenderWindow& window) {

}
