#pragma once
#include "Dynamic.h"
#include "Player.h"
#include "Swordsman.h"

class IDmanager
{
	IDmanager() = delete;
public:
	enum class Objects { //enum values represent id of all objects
		PLAYER = 0,
		SWORDSMAN
	};
public:
	static const int getObjectID(const Objects& obj);
	static Dynamic* getNewObj(int id, int parameter);
};