#include "stdafx.h"
#include "DynamicManager.h"


void DynamicManager::setMap(const Map* map) {
	m_map = map;
}

void DynamicManager::addEntity(Entity* entity, const sf::Vector2f& pos) {
	entity->setPos(pos);
	m_entities.emplace_back(entity);
}

void DynamicManager::addWordObj(WorldObj* worldobj, const sf::Vector2f& pos) {
	worldobj->setPos(pos);
	m_worldobjs.emplace_back(worldobj);
}

void DynamicManager::update() {
	for (Dynamic* worldobj : m_worldobjs) {
		for (Dynamic* entity : m_entities) {
			worldobj->interactWithOther(entity);
		}
		worldobj->update();
		m_map->handleCollisions(worldobj);
	}
	for (Dynamic* entity1 : m_entities) {
		for (Dynamic* entity2 : m_entities) {
			entity1->interactWithOther(entity2);
		}
		entity1->update();
		m_map->handleCollisions(entity1);
	}
}

void DynamicManager::render(sf::RenderWindow& window, const GameView& view) {
	for (Dynamic* entity : m_entities) {
		if (view.isInView(entity->getPos(), entity->getSize())) {
			entity->render(window);
		}
	}
	for (Dynamic* worldobj : m_worldobjs) {
		if (view.isInView(worldobj->getPos(), worldobj->getSize())) {
			worldobj->render(window);
		}
	}
}

const Entity* DynamicManager::getEntityAt(int index) const {
	return dynamic_cast<Entity*>(m_entities[index]);
}

DynamicManager::~DynamicManager() {
	for (Dynamic* worldobj : m_worldobjs) {
		delete worldobj;
	}
	for (Dynamic* entity : m_entities) {
		delete entity;
	}
}