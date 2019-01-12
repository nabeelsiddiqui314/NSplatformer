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
public:
	void update(const sf::RenderWindow& window) override;
	void render(sf::RenderWindow& window) override;
private:
	inline void init(const std::string& levelFolder);
private:
	std::unique_ptr<LevelParser> m_parser;
	std::unique_ptr<DynamicManager> m_objects;
	std::shared_ptr<Map> m_map;
	GameView m_gameView;
};

