#include "stdafx.h"
#include "Player.h"


Player::Player() {
	this->setTexture("player");

	p_animation.setRowSpacing(60);

	p_animation.AddFrame({ 28, 49 });
	p_animation.AddFrame({28, 44});

	p_animation.addRow();
	p_animation.AddFrame({ 30, 47 });
	p_animation.AddFrame({ 29, 49 });
	p_animation.AddFrame({ 32, 44 });
	p_animation.AddFrame({ 30, 49 });
	p_animation.AddFrame({ 32, 50 });
	p_animation.AddFrame({ 32, 44 });

	p_animation.setFrame(0, 0, false, { 0, this->getSize().y });
	p_jumpHeight = 4 * 32;
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
			p_animation.setFrame(0, 1, true, { 0, 0 });
		}
		else if (this->getDirection() == xDirection::RIGHT) {
			p_animation.setFrame(0, 1, false, { this->getSize().x, 0 });
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		p_animation.animate(1, 100, true, { 0, this->getSize().y });
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		p_animation.animate(1, 100, false, this->getSize());
		
	}
	else {
		if (this->getDirection() == xDirection::LEFT) {
			p_animation.setFrame(0, 0, true, { 0, this->getSize().y });
		}
		else if (this->getDirection() == xDirection::RIGHT) {
			p_animation.setFrame(0, 0, false, this->getSize());
		}
	}
	this->generalUpdate();
}

const sf::Vector2f& Player::getVel() const {
	return Entity::getVelocity();
}

bool Player::isInJump() const {
	return Entity::isJumping();;
}

const xDirection& Player::getDir() const {
	return Entity::getDirection();
}

const sf::Vector2f Player::getCentre() const {
	return {this->getPos().x + this->getSize().x / 2,
		    this->getPos().y + this->getSize().y / 2 };
}
