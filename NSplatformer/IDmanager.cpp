#include "stdafx.h"
#include "IDmanager.h"

const IDmanager::Type& IDmanager::getObjectType(int id) {
	return Type::ENTITY; //temp
}

const int IDmanager::getObjectName(const Objects& obj) {
	return static_cast<int>(obj);
}

Entity* IDmanager::getNewEntity(int id, int parameter) {
	return nullptr; //temp
}

WorldObj* IDmanager::getNewWorldObj(int id, int parameter) {
	return nullptr; //temp
}


