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
	for (WorldObj* worldobj : m_worldobjs) {
		for (Entity* entity : m_entities) {
			worldobj->entityInteract(entity);
		}
		worldobj->update();
	}
	for (Entity* entity1 : m_entities) {
		for (Entity* entity2 : m_entities) {
			entity1->interact(entity2);
		}
		entity1->update();
		m_map->handleCollisions(entity1);
	}
}

void DynamicManager::render(sf::RenderWindow& window) {
	for (WorldObj* worldobj : m_worldobjs) {
		worldobj->render(window);
	}
	for (Entity* entity : m_entities) {
		entity->render(window);
	}
}

DynamicManager::~DynamicManager() {
	for (WorldObj* worldobj : m_worldobjs) {
		delete worldobj;
	}
	for (Entity* entity : m_entities) {
		delete entity;
	}
}