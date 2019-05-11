#pragma once
#include "Player.h"
#include "Map.h"
#include "GameView.h"

class DynamicManager
{
public:
	~DynamicManager();
public:
	void setMap(const Map* map);
	void addObject(Dynamic* obj, const sf::Vector2f& pos);
	void update();
	void render(sf::RenderWindow& window, const GameView& view);

	const Player* getPlayer() const;
private:
	const Map* m_map;
	std::vector<Dynamic*> m_objects;
	int m_playerIndex;
};

