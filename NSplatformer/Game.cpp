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
	m_gameView.moveCamera(m_playerPtr->getPos(), { m_playerPtr->getPos().x - m_playerPtr->getOldPos().x,
		m_playerPtr->getPos().y - m_playerPtr->getOldPos().y });
	if (sf::FloatRect(m_playerPtr->getPos(), m_playerPtr->getSize()).intersects(m_goalRegion)) {
		stateManager.setState(new Game("level_n"));
	}
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
	m_gameView.setWorldSize({m_parser->getDimensions().x * Data::tile::size,  m_parser->getDimensions().y * Data::tile::size });
	m_gameView.setSize({static_cast<float>(Data::camera::width), static_cast<float>(Data::camera::height)});
	m_objects->setMap(m_map);
	m_goalRegion = m_parser->getGoalRegion();

	int entityIndex = 0;
	for (auto& info : m_parser->getObjects()) {
		if (IDmanager::getObjectType(info.id) == IDmanager::ENTITY) {
			m_objects->addEntity(IDmanager::getNewEntity(info.id, info.parameter), info.pos);
			if (info.id == IDmanager::getObjectID(IDmanager::PLAYER)) {
				m_playerPtr = m_objects->getEntityAt(entityIndex);
				m_gameView.setPos({ m_playerPtr->getPos().x + m_playerPtr->getSize().x / 2,
								    m_playerPtr->getPos().y + m_playerPtr->getSize().y / 2 });
			}
			entityIndex++;
		}
		else if (IDmanager::getObjectType(info.id) == IDmanager::WORLDOBJ) {
			m_objects->addWordObj(IDmanager::getNewWorldObj(info.id, info.parameter), info.pos);
		}
	}
}
