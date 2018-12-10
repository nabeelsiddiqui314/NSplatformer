#include "stdafx.h"
#include "Gui_obj.h"

void Gui_obj::init() {
	m_text.setCharacterSize(1);
	m_text.setOutlineThickness(1);
	m_text.setOutlineColor(sf::Color::Black);
	m_text.setFillColor(sf::Color(222, 222, 237));
}

void Gui_obj::setPos(const sf::Vector2f& pos) {
	m_text.setPosition(pos);
}

const sf::Vector2f& Gui_obj::getPos() const {
	return m_text.getPosition();
}

void Gui_obj::render(sf::RenderWindow & window) {
	window.draw(m_text);
}

void Gui_obj::setString(const std::string& string) {
	m_text.setString(string);
}

void Gui_obj::setColor(const sf::Color& color) {
	m_text.setFillColor(color);
}

bool Gui_obj::isHovered(const sf::RenderWindow& window) {
	return m_text.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
}
