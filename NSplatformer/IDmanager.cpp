#include "stdafx.h"
#include "IDmanager.h"

const int IDmanager::getObjectID(const Objects& obj) {
	return static_cast<int>(obj);
}

Dynamic* IDmanager::getNewObj(int id, int parameter) {
	switch (id) {
	case 0:
		return new Player();
		break;
	case 1:
		return new Swordsman("lionMan");
		break;
	}
}