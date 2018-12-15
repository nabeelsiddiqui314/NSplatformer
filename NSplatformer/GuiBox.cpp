#include "stdafx.h"
#include "GuiBox.h"


GuiBox::GuiBox() {
	m_body.setPosition({0, 0});
	m_body.setSize({ 400, 90 });
	m_body.setFillColor(sf::Color(128, 255, 0, 100));
	m_body.setOutlineThickness(4);
	m_body.setOutlineColor(sf::Color::Green);

	//m_title.setFont(Resources::fonts.get("8bitfont"));
	m_title.setCharacterSize(60);
	m_title.setOutlineThickness(5);
	m_title.setOutlineColor(sf::Color::Black);
	m_title.setFillColor(sf::Color(224, 224, 224));
}

void GuiBox::setPos(const sf::Vector2f& pos) {
	sf::Vector2f deltaPos = {pos.x - m_body.getPosition().x, pos.y - m_body.getPosition().y};
	m_body.move(deltaPos);
	m_title.move(deltaPos);
	for (auto& component : m_components) {
		component->setPos({component->getPos().x + deltaPos.x, component->getPos().y + deltaPos.y });
	}
}

void GuiBox::setTitle(const std::string& text) {
	m_title.setFont(Resources::fonts.get("8bitfont"));
	m_title.setString(text);
	m_title.setPosition({m_body.getPosition().x + m_body.getSize().x / 2 - m_title.getGlobalBounds().width / 2, 0});
}

void GuiBox::addButton(const std::string& text, std::function<void()> slot) {
	auto button = std::make_shared<Button_>();
	button->setLabel(text);
	button->setSlot(slot);
	placeComponent(button);
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
	window.draw(m_body);
	window.draw(m_title);

	for (auto& component : m_components) {
		component->render(window);
	}
}

void GuiBox::placeComponent(std::shared_ptr<Gui_obj> component) {
	float x = m_body.getPosition().x + 20;
	if (m_components.size() == 0) {
		component->setPos({ x, m_body.getPosition().y + m_title.getPosition().y + m_title.getGlobalBounds().height + 20 });
	}
	else {
		component->setPos({ x, m_components[m_components.size() - 1]->bottomPos() + 5});
	}
	m_body.setSize({m_body.getSize().x, m_body.getSize().y + component->height() + 5});
}
