#include "stdafx.h"
#include "DoorKey.h"


DoorKey::DoorKey(const std::string& param) : Dynamic("key") {
	m_key = std::stoi(param);
}

void DoorKey::interactWithOther(Dynamic* other) {
	if (other->getID() == IDmanager::getObjectID(IDmanager::Objects::PLAYER)) {
		if (this->isCollidingOther(other))
			m_isObtained = true;;
	}
	if (m_isObtained && other->getID() == IDmanager::getObjectID(IDmanager::Objects::DOOR)) {
		other->recieveInt(m_key);
	}
}

int DoorKey::getID() const {
	return IDmanager::getObjectID(IDmanager::Objects::KEY);
}

void DoorKey::render(sf::RenderWindow& window) {
	if (!m_isObtained)
		Dynamic::render(window);
}