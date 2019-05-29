#include "stdafx.h"
#include "Door.h"

Door::Door(const std::string& param) : Dynamic("door") {
	p_animation.setFrame(0, 0, false, {0, 0});
	m_key = std::stoi(param);
}

int Door::getID() const {
	return IDmanager::getObjectID(IDmanager::Objects::DOOR);
}

void Door::interactWithOther(Dynamic* other) {
	if (m_isLocked) {
		if (other->getID() == IDmanager::getObjectID(IDmanager::Objects::PLAYER)) {
			if (this->isCollidingOther(other))
				other->interactWithTile(this->getPos(), this->getSize());
		}
	}
	else {
		if (sqrt(pow(this->getPos().x - other->getPos().x, 2) + pow(this->getPos().y - other->getPos().y, 2)) < 2 * Data::tile::size) {
			p_animation.setFrame(0, 1, false, { 0, 0 });
		}
	}
}

void Door::update() {
	p_animation.update();
}

void Door::recieveInt(int amount) {
	if (m_key == amount)
		m_isLocked = false;
}