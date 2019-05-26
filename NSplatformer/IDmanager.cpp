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
	}
}