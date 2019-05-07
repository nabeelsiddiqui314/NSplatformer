#include "stdafx.h"
#include "EntryPoint.h"

EntryPoint::EntryPoint() {
	m_window.create(sf::VideoMode(Data::window::width, Data::window::height), "NSP");
	InputManager::init();
	Resources::init();
	stateManager.setWindow(m_window);
	stateManager.setState(new Menu());
}

void EntryPoint::runloop() {
	while (m_window.isOpen()) {
		sf::Event evnt;
		while (m_window.pollEvent(evnt)) {
			if (evnt.type == sf::Event::Closed) {
				m_window.close();
			}
		}
		m_window.clear();

		InputManager::getInput();
		stateManager.update();
		InputManager::updateOldInput();

		stateManager.render();
		m_window.display();
	}
}