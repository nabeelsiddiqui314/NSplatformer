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

void GuiBox::addButton(const std::string& text, std::function<void()> slot) {
	auto button = std::make_shared<Button_>();
	button->setLabel(text);
	button->setSlot(slot);
	m_components.push_back(button);
}

void GuiBox::addToggler(const std::string& text) {

}

void GuiBox::update(const sf::RenderWindow& window) {
	for (auto& component : m_components) {
		if (component->isHovering(window)) {
			component->select();
		}
		else {
			component->deselect();
		}
		component->update();
	}
}

void GuiBox::render(sf::RenderWindow& window) {
	for (auto& component : m_components) {
		component->render(window);
	}
}
