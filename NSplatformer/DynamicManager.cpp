#include "stdafx.h"
#include "DynamicManager.h"


void DynamicManager::setMap(const Map* map) {
	m_map = map;
}

void DynamicManager::addObject(Dynamic* obj, const sf::Vector2f& pos) {
	obj->setPos(pos);
	obj->setDynamicManager(this);
	m_objects.emplace_back(obj);

	if (Player* p = dynamic_cast<Player*>(obj)) {
		m_playerIndex = m_objects.size() - 1;
	}
}

void DynamicManager::update(const GameView& view) {
	for (int i = 0; i < m_objects.size(); i++) {
		for (Dynamic* obj2 : m_objects) {
			if (m_objects[i] != obj2) {
				if (view.isInView(m_objects[i]->getPos(), m_objects[i]->getSize())) {
					m_objects[i]->interactWithOther(obj2);
				}
			}
		}
		m_objects[i]->update();
		m_map->handleCollisions(m_objects[i]);
		if (m_objects[i]->isDestroyed()) {
			delete m_objects[i];
			m_objects.erase(m_objects.begin() + i);
		}
	}
}

void DynamicManager::render(sf::RenderWindow& window, const GameView& view) {
	for (Dynamic* obj : m_objects) {
		if (view.isInView(obj->getPos(), obj->getSize())) {
			obj->render(window);
		}
	}
}

const Player* DynamicManager::getPlayer() const {
	return dynamic_cast<const Player*>(m_objects[m_playerIndex]);
}

DynamicManager::~DynamicManager() {
	for (Dynamic* obj : m_objects) {
		delete obj;
	}
}