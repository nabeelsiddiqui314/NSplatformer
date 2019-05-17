#include "stdafx.h"
#include "Player.h"


Player::Player() {
	p_id = static_cast<int>(IDmanager::Objects::PLAYER);
	p_isFriendly = true;
	this->setTexture("player");

	p_animation.setRowSpacing(60);

	p_animation.AddFrame({ 28, 49 });
	p_animation.AddFrame({ 28, 44});
	p_animation.AddFrame({ 27, 38 });
	p_animation.AddFrame({ 27, 38 });

	p_animation.addRow();
	p_animation.AddFrame({ 30, 47 });
	p_animation.AddFrame({ 29, 49 });
	p_animation.AddFrame({ 32, 44 });
	p_animation.AddFrame({ 30, 49 });
	p_animation.AddFrame({ 32, 50 });
	p_animation.AddFrame({ 32, 44 });

	p_animation.addRow();
	p_animation.AddFrame({ 25, 43 });

	p_animation.setFrame(0, 0, false, { 0, this->getSize().y });
	p_jumpHeight = 4 * 32;
}

void Player::update() {
	if (!this->isJumping()) {
		if (InputManager::isClicked(InputManager::Ctrl)) {
			if (this->getDirection() == xDirection::LEFT) {
				p_animation.playOnce(0, 50, true, { 0, this->getSize().y });
			}
			else if (this->getDirection() == xDirection::RIGHT) {
				p_animation.playOnce(0, 50, false, this->getSize());
			}
			m_isCrouching = true;
		}
		else if (InputManager::isReleased(InputManager::Ctrl) && m_isCrouching) {
			if (this->getDirection() == xDirection::LEFT) {
				p_animation.playOnce(0, 50, true, { 0, this->getSize().y }, true);
			}
			else if (this->getDirection() == xDirection::RIGHT) {
				p_animation.playOnce(0, 50, false, this->getSize(), true);
			}
			m_isCrouching = false;
		}
	}

	if (InputManager::isClicked(InputManager::W)) {
		this->jump();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !m_isCrouching && !p_animation.isPlayingOnce()) {
		this->walkLeft();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !m_isCrouching && !p_animation.isPlayingOnce()) {
		this->walkRight();
	}

	if (this->isJumping()) {
		if (this->getDirection() == xDirection::LEFT) {
			p_animation.setFrame(2, 0, true, { 0, 0 });
		}
		else if (this->getDirection() == xDirection::RIGHT) {
			p_animation.setFrame(2, 0, false, { this->getSize().x, 0 });
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !m_isCrouching) {
		p_animation.repeat(1, 100, true, { 0, this->getSize().y });
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !m_isCrouching) {
		p_animation.repeat(1, 100, false, this->getSize());
		
	}
	else {
		if (this->getDirection() == xDirection::LEFT) {
			if (m_isCrouching)
				p_animation.setFrame(0, 3, true, { 0, this->getSize().y });
			else
				p_animation.setFrame(0, 0, true, { 0, this->getSize().y });
		}
		else if (this->getDirection() == xDirection::RIGHT) {
			if (m_isCrouching)
				p_animation.setFrame(0, 3, false, { 0, this->getSize().y });
			else
				p_animation.setFrame(0, 0, false, this->getSize());
		}
	}
	p_animation.update();
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
