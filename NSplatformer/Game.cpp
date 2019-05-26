#include "stdafx.h"
#include "Game.h"

int Game::s_level = 1;

Game::Game() {
	this->init("1");
}

Game::Game(const std::string& levelFolder) {
	this->init(levelFolder);
}

void Game::update(const sf::RenderWindow& window) {
	m_objects->update();

	//camera
	m_gameView.setFocus(m_playerPtr->getDirection());
	m_gameView.moveCamera(m_playerPtr->getCentre(), m_playerPtr->isJumping());
	m_bg->update(m_gameView.getView().getCenter(), m_gameView.getVelocity().x);

	//if the player has reached the goal
	if (sf::FloatRect(m_playerPtr->getPos(), m_playerPtr->getSize()).intersects(m_goalRegion)) {
		if (this->doesDirExist("Levels/" + std::to_string(s_level + 1))) {
			s_level++;
			stateManager.setState(new Game(std::to_string(s_level)));
		}
		else {
			s_level = 1;
			stateManager.setState(new Menu());
		}
	}
}

void Game::render(sf::RenderWindow& window) {
	m_bg->render(window);
	window.setView(m_gameView.getView());
	m_map->render(window);
	m_objects->render(window, m_gameView);
}

inline void Game::init(const std::string& levelFolder) {
	m_parser = new LevelParser();
	m_map = new Map();
	m_objects = new DynamicManager();
	m_bg = new ParallaxBG();

	m_parser->parseMap("./Levels/" + levelFolder + "/map.txt");
	m_parser->parseObjects("./Levels/" + levelFolder + "/obj.txt");
	m_map->importTileset(m_parser->getTilesetName());
	m_map->importLevel(m_parser->getMap());
	m_map->setDimensions(m_parser->getDimensions());
	m_map->load();
	m_gameView.setWorldSize({m_parser->getDimensions().x * Data::tile::size,  m_parser->getDimensions().y * Data::tile::size });
	m_gameView.setSize({static_cast<float>(Data::camera::width), static_cast<float>(Data::camera::height)});
	m_objects->setMap(m_map);
	m_goalRegion = m_parser->getGoalRegion();
	m_bg->init(m_parser->getBGName(), m_parser->isYFixed());

	for (auto& info : m_parser->getObjects()) {
		m_objects->addObject(IDmanager::getNewObj(info.id, info.name, info.parameter), info.pos);
	}
	m_playerPtr = m_objects->getPlayer();
	m_gameView.setPos(m_playerPtr->getCentre());
}

bool Game::doesDirExist(const std::string & dir) {
	DWORD ftyp = GetFileAttributesA(dir.c_str());
	if (ftyp == INVALID_FILE_ATTRIBUTES)
		return false;  //something is wrong with your path!

	if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
		return true;   // this is a directory!

	return false;    // this is not a directory!
}

Game::~Game() {
	delete m_parser;
	delete m_map;
	delete m_objects;
	delete m_bg;
}