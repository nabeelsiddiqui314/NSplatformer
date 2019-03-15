#pragma once
#include "State.h"
#include "StateManager.h"
#include "InputManager.h"
#include "Resources.h"
#include "LevelParser.h"
#include "DynamicManager.h"
#include "IDmanager.h"

class Game : public State
{
public:
	Game(); // if used outside the class
	Game(const std::string& levelFolder);
	~Game();
public:
	void update(const sf::RenderWindow& window) override;
	void render(sf::RenderWindow& window) override;
private:
	inline void init(const std::string& levelFolder);
private:
	LevelParser* m_parser;
	DynamicManager* m_objects;
	Map* m_map;
	GameView m_gameView;
	const Entity* m_playerPtr;
	sf::FloatRect m_goalRegion;
};

