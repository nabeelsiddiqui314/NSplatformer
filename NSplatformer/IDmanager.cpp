#include "stdafx.h"
#include "IDmanager.h"

const IDmanager::Type& IDmanager::getObjectType(int id) {
	switch (id) {
	case 0:
		return Type::ENTITY;
		break;
	}
}

const int IDmanager::getObjectID(const Objects& obj) {
	return static_cast<int>(obj);
}

Entity* IDmanager::getNewEntity(int id, int parameter) {
	switch (id) {
	case 0:
		return new Player();
		break;
	}
}

WorldObj* IDmanager::getNewWorldObj(int id, int parameter) {
	return nullptr; //temp
}


