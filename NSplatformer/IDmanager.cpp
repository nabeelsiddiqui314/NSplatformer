#include "stdafx.h"
#include "IDmanager.h"

const int IDmanager::getObjectID(const Objects& obj) {
	return static_cast<int>(obj);
}

Dynamic* IDmanager::getNewObj(int id, const std::string& parameter) {
	switch (id) {
	case 0:
		return new Player();
		break;
	case 1:
		return new Swordsman(parameter);
		break;
	}
}