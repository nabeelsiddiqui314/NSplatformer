#pragma once
#include "Entity.h"
#include "WorldObj.h"
#include "Map.h"
#include "GameView.h"

class DynamicManager
{
public:
	~DynamicManager();
public:
	void setMap(const Map* map);
	void addEntity(Entity* entity, const sf::Vector2f& pos);
	void addWordObj(WorldObj* worldobj, const sf::Vector2f& pos);
	void update();
	void render(sf::RenderWindow& window, const GameView& view);

	const Entity* getEntityAt(int index) const;
private:
	const Map* m_map;
	std::vector<Dynamic*> m_entities;
	std::vector<Dynamic*> m_worldobjs;
};

