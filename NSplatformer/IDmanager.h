#pragma once
#include "Entity.h"
#include "WorldObj.h"

class IDmanager
{
	IDmanager() = delete;
public:
	enum Objects { //enum values represent id of all objects
		Player = 0
	};
public:
	const int getObject(const Objects& obj) const;
	Entity* createEntity(int id, int parameter);
	WorldObj* createWorldobj(int id, int parameter);
};

