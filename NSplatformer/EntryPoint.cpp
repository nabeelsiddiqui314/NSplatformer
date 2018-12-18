#include "stdafx.h"
#include "EntryPoint.h"
#include <iostream>

EntryPoint::EntryPoint() {
	m_window.create(sf::VideoMode(992, 576), "NSP");
	InputManager::init();
	Resources::init();
	stateManager.setWindow(m_window);
	g.setTitle("Title");
	g.addButton("Play", [] { std::cout << "play "; });
	g.addButton("Settings", [] {std::cout << "set "; });
	g.addButton("Credits", [] {std::cout << "cre "; });
	g.addButton("Quit", [] {std::cout << "qui "; });

	g.setPos({ 400, 200 });
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
		while (m_accumulator > m_ups) {
			m_accumulator -= m_ups;
			InputManager::getInput();
			//stateManager.update();
			g.update(m_window);
			InputManager::updateOldInput();
		}
		m_accumulator += m_clock.restart();

		g.render(m_window);
		//stateManager.render();
		m_window.display();
	}
}