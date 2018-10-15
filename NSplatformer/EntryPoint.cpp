#include "stdafx.h"
#include "EntryPoint.h"


EntryPoint::EntryPoint() {
	m_window.create(sf::VideoMode(992, 576), "NSP");
	m.importTileset("tileset");
	m.importLevel("Level1");
	m.load();
	e.setPos({0,0});
	e.setSize({16, 30});
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
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				e.jump();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				e.walkLeft();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				e.walkRight();
			}
			e.update();
			m.handleCollisions(&e);
		}
		m.render(m_window);
		e.render(m_window);
		m_accumulator += m_clock.restart();
		m_window.display();
	}
}