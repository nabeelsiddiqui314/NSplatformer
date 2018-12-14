#include "stdafx.h"
#include "GuiBox.h"


GuiBox::GuiBox() {
	m_body.setPosition({0, 0});
}

void GuiBox::setPos(const sf::Vector2f& pos) {
	sf::Vector2f deltaPos = {pos.x - m_body.getPosition().x, pos.y - m_body.getPosition().y};
	m_body.move(deltaPos);
}

void GuiBox::setTitle(const std::string& text) {

}

void GuiBox::addButton(const std::string& text) {
	

}

void GuiBox::addToggler(const std::string& text) {

}
