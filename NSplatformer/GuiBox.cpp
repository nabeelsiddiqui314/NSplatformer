#include "stdafx.h"
#include "GuiBox.h"


GuiBox::GuiBox() {
	m_body.setPosition({0, 0});
	m_body.setSize({ 300, 120 });
	m_body.setFillColor(Data::Gui::box.color() - sf::Color(0, 0, 0, 155));
	m_body.setOutlineThickness(4);
	m_body.setOutlineColor(Data::Gui::boxBorder.color());

	m_title.setFont(Resources::fonts.get("8bitfont"));
	m_title.setCharacterSize(60);
	m_title.setOutlineThickness(5);
	m_title.setOutlineColor(sf::Color::Black);
	m_title.setFillColor(Data::Gui::title.color());
}

void GuiBox::setPos(const sf::Vector2f& pos) {
	sf::Vector2f deltaPos = {pos.x - m_body.getPosition().x, pos.y - m_body.getPosition().y};
	m_body.move(deltaPos);
	m_title.move(deltaPos);
	for (auto& component : m_components) {
		component->setPos({component->getPos().x + deltaPos.x, component->getPos().y + deltaPos.y });
	}
}

const sf::Vector2f& GuiBox::getSize() const {
	return m_body.getSize();
}

void GuiBox::setTitle(const std::string& text) {
	m_title.setString(text);
	m_title.setPosition({m_body.getPosition().x + m_body.getSize().x / 2 - m_title.getGlobalBounds().width / 2, m_body.getPosition().y - m_title.getGlobalBounds().height + Data::Gui::titleTopSpace});
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
	for (int i = 0; i < m_components.size(); i++) {
		if (m_components[i]->isHovering(window)) {
			m_components[i]->select();
			m_selectedIndex = i;
			for (int j = 0; j < m_components.size(); j++) {
				if (m_components[i] != m_components[j]) {
					m_components[j]->deselect();
				}
			}
		}
		else {
			if (InputManager::isClicked(InputManager::ArrowUp)) {
				if (i == m_selectedIndex && i != 0) {
					m_components[i]->deselect();
					m_components[i - 1]->select();
					m_selectedIndex--;
				}
			}
			if (InputManager::isClicked(InputManager::ArrowDown)) {
				if (i == m_selectedIndex && i != m_components.size() - 1) {
					m_components[i]->deselect();
					m_components[i + 1]->select();
					m_selectedIndex++;
					break; //to prevent it from incrementing in parellel with i to cause issues.
				}
			}
		}
		m_components[i]->update(window);
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
	if (m_components.size() == 0) {
		component->select();
	}
	float x = m_body.getPosition().x + Data::Gui::leftSpace;
	if (m_components.size() == 0) {
		component->setPos({ x, m_body.getPosition().y + m_title.getPosition().y + m_title.getGlobalBounds().height + Data::Gui::titleBottomSpace });
	}
	else {
		component->setPos({ x, m_components[m_components.size() - 1]->bottomPos() + Data::Gui::componentSpace});
	}
	m_body.setSize({m_body.getSize().x, m_body.getSize().y + component->height() + Data::Gui::componentSpace });
}
