#include "stdafx.h"
#include "Game.h"


Game::Game() {
	this->init("level_1");
}

Game::Game(const std::string& levelFolder) {
	this->init(levelFolder);
}

void Game::update(const sf::RenderWindow& window) {
	m_objects->update();
}

void Game::render(sf::RenderWindow& window) {
	m_gameView.setView(window);
	m_map->render(window);
	m_objects->render(window, m_gameView);
}

inline void Game::init(const std::string& levelFolder) {
	m_parser->parseMap("levels/" + levelFolder + "/map.txt");
	m_parser->parseObjects("levels/" + levelFolder + "/obj.txt");
	m_map->importTileset(m_parser->getTilesetName());
	m_map->importLevel(m_parser->getMap());
	for (auto& info : m_parser->getObjects()) {
		if (IDmanager::getObjectType(info.id) == IDmanager::ENTITY) {
			m_objects->addEntity(IDmanager::getNewEntity(info.id, info.parameter), info.pos);
		}
		else if (IDmanager::getObjectType(info.id) == IDmanager::WORLDOBJ) {
			m_objects->addWordObj(IDmanager::getNewWorldObj(info.id, info.parameter), info.pos);
		}
	}
}
