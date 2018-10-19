#include "stdafx.h"
#include "InputManager.h"

InputManager::InputManager() {
	int buttons = 7;
	for (int i = 0; i < buttons; i++) {
		s_oldInput.emplace_back(false);
		s_currentInput.emplace_back(false);
	}
}

void InputManager::getCurrentInput() {
	currentInputHandler(Enter, sf::Keyboard::isKeyPressed(sf::Keyboard::Return));
	currentInputHandler(MouseLeft, sf::Mouse::isButtonPressed(sf::Mouse::Left));
	currentInputHandler(MouseRight, sf::Mouse::isButtonPressed(sf::Mouse::Right));
	currentInputHandler(ArrowUp, sf::Keyboard::isKeyPressed(sf::Keyboard::Up));
	currentInputHandler(ArrowDown, sf::Keyboard::isKeyPressed(sf::Keyboard::Down));
	currentInputHandler(ArrowLeft, sf::Keyboard::isKeyPressed(sf::Keyboard::Left));
	currentInputHandler(ArrowRight, sf::Keyboard::isKeyPressed(sf::Keyboard::Right));
}

void InputManager::getOldInput() {
	oldInputHandler(Enter, sf::Keyboard::isKeyPressed(sf::Keyboard::Return));
	oldInputHandler(MouseLeft, sf::Mouse::isButtonPressed(sf::Mouse::Left));
	oldInputHandler(MouseRight, sf::Mouse::isButtonPressed(sf::Mouse::Right));
	oldInputHandler(ArrowUp, sf::Keyboard::isKeyPressed(sf::Keyboard::Up));
	oldInputHandler(ArrowDown, sf::Keyboard::isKeyPressed(sf::Keyboard::Down));
	oldInputHandler(ArrowLeft, sf::Keyboard::isKeyPressed(sf::Keyboard::Left));
	oldInputHandler(ArrowRight, sf::Keyboard::isKeyPressed(sf::Keyboard::Right));
}

bool InputManager::isPressed(Button button) {
	return s_oldInput[static_cast<int>(button)] && !s_currentInput[static_cast<int>(button)];
}

void InputManager::currentInputHandler(Button button, bool condition) {
	s_currentInput[static_cast<int>(button)] = condition;
}

void InputManager::oldInputHandler(Button button, bool condition) {
	s_oldInput[static_cast<int>(button)] = condition;
}