#pragma once
#include "State.h"
#include "StateManager.h"
#include "InputManager.h"
#include "Resources.h"
#include "LevelParser.h"
#include "DynamicManager.h"
#include "IDmanager.h"
#include <Windows.h>
#include "Menu.h"

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
	bool doesDirExist(const std::string& dir);
private:
	LevelParser* m_parser;
	DynamicManager* m_objects;
	Map* m_map;
	GameView m_gameView;
	const Player* m_playerPtr;
	sf::FloatRect m_goalRegion;
	static int s_level;

};

