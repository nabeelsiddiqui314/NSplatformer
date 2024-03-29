#include "stdafx.h"
#include "Player.h"


Player::Player() 
	: Entity("player") {
	p_isFriendly = true;

	p_animation.setFrame(0, 0, false, { 0, this->getSize().y });
	p_animation.update();
	p_jumpHeight = 4 * 32;
}

int Player::getID() const {
	return IDmanager::getObjectID(IDmanager::Objects::PLAYER);
}

void Player::update() {
	if (!this->isJumping()) {
		if (InputManager::isClicked(InputManager::Ctrl) && !m_isCrouching) {
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
				p_animation.playOnce(0, 50, true, { 0, this->getSize().y }, Animation::Reverse);
			}
			else if (this->getDirection() == xDirection::RIGHT) {
				p_animation.playOnce(0, 50, false, this->getSize(), Animation::Reverse);
			}
			m_isCrouching = false;
		}
		if (InputManager::isClicked(InputManager::MouseLeft) && !m_isAttacking) {
			if (!m_isCrouching) {
				if (this->getDirection() == xDirection::LEFT) {
					p_animation.playOnce(4, 50, true, this->getSize(), Animation::Cycle);
				}
				else if (this->getDirection() == xDirection::RIGHT) {
					p_animation.playOnce(4, 50, false, { 0, this->getSize().y }, Animation::Cycle);
				}
			}
			else {
				if (this->getDirection() == xDirection::LEFT) {
					p_animation.playOnce(5, 50, true, this->getSize(), Animation::Cycle);
				}
				else if (this->getDirection() == xDirection::RIGHT) {
					p_animation.playOnce(5, 50, false, { 0, this->getSize().y }, Animation::Cycle);
				}
			}
			m_isAttacking = true;
		}
		else if (m_isAttacking && !p_animation.isPlayingOnce())
			m_isAttacking = false;
	}

	if (InputManager::isClicked(InputManager::W) && !m_isCrouching) {
		this->jump();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !m_isCrouching && !p_animation.isPlayingOnce()) {
		this->walk(xDirection::LEFT);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !m_isCrouching && !p_animation.isPlayingOnce()) {
		this->walk(xDirection::RIGHT);
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
				p_animation.setFrame(0, 3, false, this->getSize());
			else
				p_animation.setFrame(0, 0, false, this->getSize());
		}
	}
	p_animation.update();
	this->generalUpdate();
}

void Player::interactWithOther(Dynamic* other) {
	if (m_isAttacking && this->isCollidingOther(other)) {
		if ((other->getPos().x > this->getPos().x && this->getDirection() == xDirection::RIGHT) ||
			(other->getPos().x + other->getSize().x < this->getPos().x + this->getSize().x && this->getDirection() == xDirection::LEFT)) {
			if (other->getPos().y > this->getPos().y / 4) {
				if (m_isCrouching)
					this->damageOther(other);
			}
			else
				this->damageOther(other);
		}
	}
}

void Player::recieveInt(int amount) {
	if (!m_isAttacking)
		this->loseHealth(amount);
}

const sf::Vector2f Player::getCentre() const {
	return {this->getPos().x + this->getSize().x / 2,
		    this->getPos().y + this->getSize().y / 2 };
}