#pragma once
#include "DynamicManager.h"

class Level
{
public:
	void update();
	void render(sf::RenderWindow& window);
private:
	Map* m_map;
	DynamicManager* m_objects;
};

