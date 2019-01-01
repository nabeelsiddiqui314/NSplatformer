#pragma once
#include "Entity.h"
#include "WorldObj.h"
#include "Map.h"

class DynamicManager
{
public:
	~DynamicManager();
public:
	void setMap(std::shared_ptr<const Map> map);
	void addEntity(Entity* entity, const sf::Vector2f& pos);
	void addWordObj(WorldObj* worldobj, const sf::Vector2f& pos);
	void update();
	void render(sf::RenderWindow& window);
private:
	std::shared_ptr<const Map> m_map;
	std::vector<Entity*> m_entities;
	std::vector<WorldObj*> m_worldobjs;
};

