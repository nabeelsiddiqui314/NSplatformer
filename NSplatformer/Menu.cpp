#include "stdafx.h"
#include "Menu.h"


Menu::Menu() {
	m_menuGui.setTitle("Main Menu");
	m_menuGui.addButton("Play", [] { stateManager.setState(new Game()); });
	m_menuGui.addButton("Settings", [] {});
	m_menuGui.addButton("Quit", [] {});
	m_menuGui.setPos({Data::window::width/2 - m_menuGui.getSize().x/2, Data::window::height/2 - m_menuGui.getSize().y/2});

	m_introMusic.openFromFile("./resources/audio/menu.wav");
	m_introMusic.play();
	m_introMusic.setLoop(true);
}

void Menu::update(const sf::RenderWindow& window) {
	m_menuGui.update(window);
}

void Menu::render(sf::RenderWindow& window) {
	m_menuGui.render(window);
}