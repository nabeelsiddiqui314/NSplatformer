#include "stdafx.h"
#include "StateManager.h"


StateManager::StateManager() {
	m_state = new State();
}

void StateManager::setWindow(sf::RenderWindow& window) {
	m_window = &window;
}

void StateManager::setState(State* state) {
	delete m_state;
	m_state = state;
}

void StateManager::update() {
	m_state->handleInput();
	m_state->update();
}

void StateManager::render() {
	m_state->render(*m_window);
}

StateManager::~StateManager() {
	delete m_state;
}