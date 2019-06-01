#include "stdafx.h"
#include "IDmanager.h"

const int IDmanager::getObjectID(const Objects& obj) {
	return static_cast<int>(obj);
}

Dynamic* IDmanager::getNewObj(int id, const std::string& name, const std::string& parameter) {
	Objects obj = static_cast<Objects>(id);
	switch (obj) {
	case Objects::PLAYER:
		return new Player();
		break;
	case Objects::SWORDSMAN:
		return new Swordsman(name);
		break;
	case Objects::SPAWNER:
		return new Spawner(name);
		break;
	case Objects::DOOR:
		return new Door(parameter);
		break;
	case Objects::KEY:
		return new DoorKey(parameter);
		break;
	case Objects::PROJECTILE:
		return new Projectile(name, parameter);
		break;
	case Objects::SPRINTER:
		return new Sprinter(name);
		break;
	case Objects::FLYER:
		return new Flyer(name);
		break;
	}
}