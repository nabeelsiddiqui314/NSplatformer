#include "stdafx.h"
#include "InputManager.h"

std::vector<bool> InputManager::s_oldInput;
std::vector<bool> InputManager::s_currentInput;

void InputManager::init() {
	int buttons = 13;
	for (int i = 0; i < buttons; i++) {
		s_oldInput.emplace_back(false);
		s_currentInput.emplace_back(false);
	}
}

void InputManager::getInput() {
	detectCurrentInput(Enter, sf::Keyboard::isKeyPressed(sf::Keyboard::Return));
	detectCurrentInput(MouseLeft, sf::Mouse::isButtonPressed(sf::Mouse::Left));
	detectCurrentInput(MouseRight, sf::Mouse::isButtonPressed(sf::Mouse::Right));
	detectCurrentInput(ArrowUp, sf::Keyboard::isKeyPressed(sf::Keyboard::Up));
	detectCurrentInput(ArrowDown, sf::Keyboard::isKeyPressed(sf::Keyboard::Down));
	detectCurrentInput(ArrowLeft, sf::Keyboard::isKeyPressed(sf::Keyboard::Left));
	detectCurrentInput(ArrowRight, sf::Keyboard::isKeyPressed(sf::Keyboard::Right));
	detectCurrentInput(W, sf::Keyboard::isKeyPressed(sf::Keyboard::W));
	detectCurrentInput(A, sf::Keyboard::isKeyPressed(sf::Keyboard::A));
	detectCurrentInput(S, sf::Keyboard::isKeyPressed(sf::Keyboard::S));
	detectCurrentInput(D, sf::Keyboard::isKeyPressed(sf::Keyboard::D));
	detectCurrentInput(Ctrl, sf::Keyboard::isKeyPressed(sf::Keyboard::LControl));
}

void InputManager::updateOldInput() {
	updateInputFor(Enter);
	updateInputFor(MouseLeft);
	updateInputFor(MouseRight);
	updateInputFor(ArrowUp);
	updateInputFor(ArrowDown);
	updateInputFor(ArrowLeft);
	updateInputFor(ArrowRight);
	updateInputFor(W);
	updateInputFor(A);
	updateInputFor(S);
	updateInputFor(D);
	updateInputFor(Ctrl);
}

bool InputManager::isClicked(const Button& button) {
	return !s_oldInput[static_cast<int>(button)] && s_currentInput[static_cast<int>(button)];
}

bool InputManager::isReleased(const Button& button) {
	return s_oldInput[static_cast<int>(button)] && !s_currentInput[static_cast<int>(button)];
}

void InputManager::detectCurrentInput(const Button& button, bool condition) {
	s_currentInput[static_cast<int>(button)] = condition;
}

void InputManager::updateInputFor(const Button& button) {
	s_oldInput[static_cast<int>(button)] = s_currentInput[static_cast<int>(button)];
}