#include "stdafx.h"
#include "Swordsman.h"

Swordsman::Swordsman(const std::string& name) : Entity(name) {
	p_animation.setFrame(0,0, true, this->getSize());
	p_animation.update();
	m_swordDistance = p_animation.getFrameSize(1, 2).x - p_animation.getFrameSize(1, 0).x;
}

int Swordsman::getID() const {
	return IDmanager::getObjectID(IDmanager::Objects::SWORDSMAN);
}

void Swordsman::interactWithOther(Dynamic* other) {
	if (other->getID() == IDmanager::getObjectID(IDmanager::Objects::PLAYER)) {
		if (this->getPos().y + this->getSize().y != other->getPos().y + other->getSize().y) {
			m_stop = true;
			return;
		}
		else
			m_stop = false;

		if (this->getDirection() == xDirection::RIGHT &&
			this->getPos().x + this->getSize().x + m_swordDistance > other->getPos().x &&
			this->getPos().x + this->getSize().x + m_swordDistance < other->getPos().x + other->getSize().x) {
			p_animation.playOnce(1, 50, true, { 0, this->getSize().y }, Animation::Cycle);
			m_isAttacking = true;
		}
		else if (this->getDirection() == xDirection::LEFT &&
			this->getPos().x - m_swordDistance < other->getPos().x + other->getSize().x &&
			this->getPos().x - m_swordDistance > other->getPos().x) {
			p_animation.playOnce(1, 50, false, this->getSize(), Animation::Cycle);
			m_isAttacking = true;
		}
		else {
			m_isAttacking = false;
		}
		if (m_isAttacking && this->isCollidingOther(other) && !m_didHit) {
			this->damageOther(other);
		}
		m_didHit = m_isAttacking;

		if (other->getPos().x > this->getPos().x + this->getSize().x)
			m_direction = xDirection::RIGHT;
		else if (other->getPos().x + other->getSize().x < this->getPos().x)
			m_direction = xDirection::LEFT;
	}
}

void Swordsman::takeDamage(int damage) {
	this->loseHealth(damage);
}

void Swordsman::update() {
	if (!m_stop) {
		if (!p_animation.isPlayingOnce())
			this->walk(m_direction);
		if (this->getDirection() == xDirection::LEFT)
			p_animation.repeat(0, 100, false, { 0, this->getSize().y });
		else
			p_animation.repeat(0, 100, true, this->getSize());
	}
	else {
		if (m_direction == xDirection::LEFT)
			p_animation.setFrame(0, 0, false, {0, this->getSize().y});
		else
			p_animation.setFrame(0, 0, true, this->getSize());
	}
	p_animation.update();
	this->generalUpdate();
}