#include "stdafx.h"
#include "EntryPoint.h"


EntryPoint::EntryPoint() {
	m_window.create(sf::VideoMode(1000, 600), "NSP");
	m.importTileset("Tileset1");
	m.importLevel("Level1");
	m.load();
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
		}
		m.render(m_window);
		m_accumulator += m_clock.restart();
		m_window.display();
	}
}