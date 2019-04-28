#include "stdafx.h"
#include "Player.h"


Player::Player() {
	this->setTexture("player");
	this->setSize({ 16, 30 });
	p_animation.setSize({ 16, 30 });
	p_animation.setFrame(0, 0);
	p_animation.setSpacing({ 16, 11 });
}

void Player::update() {
	if (InputManager::isClicked(InputManager::W)) {
		this->jump();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		this->walkLeft();
		p_animation.animate(1, 9, 100);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		p_animation.animate(3, 9, 100);
		this->walkRight();
	}
	if (this->isJumping()) {
		if (this->getDirection() == Left) {
			p_animation.animate(0, 9, 100);
		}
		else if (this->getDirection() == Right) {
			p_animation.animate(2, 9, 100);
		}
	}
	this->generalUpdate();
}
