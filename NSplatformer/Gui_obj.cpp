#include "stdafx.h"
#include "Gui_obj.h"

void Gui_obj::init() {
	m_text.setFont(Resources::fonts.get("8bitfont"));
	m_text.setCharacterSize(40);
	m_text.setOutlineThickness(4);
	m_text.setOutlineColor(sf::Color::Black);
	m_text.setFillColor(Data::GUI_white.color());
	m_selectSound.setBuffer(Resources::soundBuffers.get("guiselect"));
}

void Gui_obj::setPos(const sf::Vector2f& pos) {
	m_text.setPosition(pos);
}

const float Gui_obj::height() const {
	return m_text.getGlobalBounds().height;
}

const float Gui_obj::bottomPos() const {
	return m_text.getPosition().y + m_text.getGlobalBounds().height;
}

const sf::Vector2f& Gui_obj::getPos() const {
	return m_text.getPosition();
}

void Gui_obj::select() {
	m_selected = true;
	if(!m_selectedLastFrame)
		m_selectSound.play();
	m_selectedLastFrame = true;
}

void Gui_obj::deselect() {
	m_selected = false;
	m_selectedLastFrame = false;
}

bool Gui_obj::isHovering(const sf::RenderWindow& window) {
	return m_text.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
}

void Gui_obj::render(sf::RenderWindow& window) {
	window.draw(m_text);
}

void Gui_obj::setString(const std::string& string) {
	m_text.setString(string);
}

void Gui_obj::setColor(const sf::Color& color) {
	m_text.setFillColor(color);
}

bool Gui_obj::isSelected() {
	return m_selected;
}
