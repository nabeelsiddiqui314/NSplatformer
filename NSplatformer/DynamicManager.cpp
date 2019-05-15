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

void DynamicManager::update() {
	for (Dynamic* obj1 : m_objects) {
		for (Dynamic* obj2 : m_objects) {
			obj1->interactWithOther(obj2);
		}
		obj1->update();
		m_map->handleCollisions(obj1);
		if (obj1->isDestroyed()) {
			delete obj1;
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