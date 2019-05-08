#include "stdafx.h"
#include "Player.h"


Player::Player() {
	this->setTexture("player");
	this->setSize({ 17, 30 });
	p_animation.setSize({ 17, 30 });
	p_animation.setFrame(3, 0, false);
	p_animation.setSpacing({ 0, 0 });
}

void Player::update() {
	if (InputManager::isClicked(InputManager::W)) {
		this->jump();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		this->walkLeft();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		this->walkRight();
	}

	if (this->isJumping()) {
		if (this->getDirection() == xDirection::LEFT) {
			p_animation.setFrame(0, 1, true);
		}
		else if (this->getDirection() == xDirection::RIGHT) {
			p_animation.setFrame(0, 1, false);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		p_animation.animate(0, 9, 100, true);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		p_animation.animate(0, 9, 100, false);
	}
	else {
		if (this->getDirection() == xDirection::LEFT) {
			p_animation.setFrame(0, 3, true);
		}
		else if (this->getDirection() == xDirection::RIGHT) {
			p_animation.setFrame(0, 3, false);
		}
	}
	this->generalUpdate();
}
