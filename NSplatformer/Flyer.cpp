#include "stdafx.h"
#include "Flyer.h"


Flyer::Flyer(const std::string& name) : Dynamic(name), m_parser(name), m_targetVector(0,0) {
	m_damage = std::stoi(m_parser.getValue("damage"));
	m_velocity = std::stoi(m_parser.getValue("velocity"));
}

int Flyer::getID() const {
	return IDmanager::getObjectID(IDmanager::Objects::FLYER);
}

void Flyer::interactWithOther(Dynamic* other) {
	if (other->getID() == IDmanager::getObjectID(IDmanager::Objects::PLAYER)) {
		if (this->isCollidingOther(other)) {
			other->recieveInt(m_damage);
			this->destroy();
			return;
		}
		if (this->getPos().y > other->getPos().y && this->getPos().y + this->getSize().y < other->getPos().y + other->getSize().y) {
			m_targetVector.x = other->getPos().x - this->getPos().x;
			m_targetVector.y = 0;
		}
		else {
			if (other->getPos().x > this->getPos().x + this->getSize().x) {
				m_targetVector.x = (other->getPos().x + other->getSize().x) - (this->getPos().x + this->getSize().x / 2);
				m_targetVector.y = (other->getPos().y + other->getSize().y / 2) - (this->getPos().y + this->getSize().y / 2);
			}
			else if (other->getPos().x + other->getSize().x < this->getPos().x) {
				m_targetVector.x = (other->getPos().x) - (this->getPos().x + this->getSize().x / 2);
				m_targetVector.y = (other->getPos().y + other->getSize().y / 2) - (this->getPos().y + this->getSize().y / 2);
			}
		}
	}
}

void Flyer::update() {
	if (m_targetVector.x != 0 || m_targetVector.y != 0) {
		m_targetVector.x /= sqrt(pow(m_targetVector.x, 2) + pow(m_targetVector.y, 2));
		m_targetVector.y /= sqrt(pow(m_targetVector.x, 2) + pow(m_targetVector.y, 2));
	}
	m_targetVector.x *= m_velocity;
	m_targetVector.y *= m_velocity;
	if (m_targetVector.x > 0)
		p_animation.repeat(0, 50, true, { this->getSize().x, this->getSize().y / 2});
	else if (m_targetVector.x < 0)
		p_animation.repeat(0, 50, false, { 0, this->getSize().y / 2});
	this->move(m_targetVector);
	p_animation.update();
}