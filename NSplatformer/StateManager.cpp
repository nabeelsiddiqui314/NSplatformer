#include "stdafx.h"
#include "StateManager.h"


StateManager::StateManager() {
	m_state = new State();
}

void StateManager::setWindow(sf::RenderWindow& window) {
	m_window = &window;
	m_window->setFramerateLimit(60);
}

void StateManager::setState(State* state) {
	delete m_state;
	m_state = state;
	m_window->setView(m_window->getDefaultView());
}

void StateManager::update() {
	m_state->update(*m_window);
}

void StateManager::render() {
	m_state->render(*m_window);
}

StateManager::~StateManager() {
	delete m_state;
}