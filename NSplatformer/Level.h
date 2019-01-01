#pragma once
#include "DynamicManager.h"

class Level
{
public:
	void update();
	void render(sf::RenderWindow& window);
private:
	std::shared_ptr<Map> m_map;
	std::unique_ptr<DynamicManager> m_objects;

};

