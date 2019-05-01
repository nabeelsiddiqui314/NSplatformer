#pragma once
#include "Entity.h"
#include "WorldObj.h"
#include "Player.h"

class IDmanager
{
	IDmanager() = delete;
public:
	enum class Type {
		ENTITY = 0,
		WORLDOBJ
	};
	enum class Objects { //enum values represent id of all objects
		PLAYER = 0
	};
public:
	static const Type& getObjectType(int id);
	static const int getObjectID(const Objects& obj);
	static Entity* getNewEntity(int id, int parameter);
	static WorldObj* getNewWorldObj(int id, int parameter);
};

