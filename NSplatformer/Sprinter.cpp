#include "stdafx.h"
#include "Sprinter.h"


Sprinter::Sprinter(const std::string& name) : Entity(name) {
	p_animation.setFrame(0, 0, true, this->getSize());
	p_animation.update();
}

int Sprinter::getID() const {
	return IDmanager::getObjectID(IDmanager::Objects::SPRINTER);
}

void Sprinter::interactWithOther(Dynamic* other) {
	if (other->getID() == IDmanager::getObjectID(IDmanager::Objects::PLAYER)) {
		if (this->getPos().y + this->getSize().y != other->getPos().y + other->getSize().y) {
			m_stop = true;
			return;
		}
		else
			m_stop = false;

		if (this->isCollidingOther(other)) {
			this->damageOther(other);
			this->destroy();
			return;
		}
		else if (other->getPos().x > this->getPos().x + this->getSize().x)
			m_direction = xDirection::RIGHT;
		else if (other->getPos().x + other->getSize().x < this->getPos().x)
			m_direction = xDirection::LEFT;
	}
}

void Sprinter::recieveInt(int amount) {
	this->destroy();
}

void Sprinter::update() {
	if (!m_stop) {
		this->walk(m_direction);
		if (this->getDirection() == xDirection::LEFT)
			p_animation.repeat(0, 100, false, { 0, this->getSize().y });
		else
			p_animation.repeat(0, 100, true, this->getSize());
	}
	else {
		if (m_direction == xDirection::LEFT)
			p_animation.setFrame(0, 0, false, { 0, this->getSize().y });
		else
			p_animation.setFrame(0, 0, true, this->getSize());
	}
	this->generalUpdate();
	p_animation.update();
}
