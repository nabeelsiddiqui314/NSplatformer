#pragma once
#include "Dynamic.h"
#include "Player.h"
#include "Swordsman.h"
#include "Spawner.h"
#include "Door.h"
#include "Sprinter.h"

class IDmanager
{
	IDmanager() = delete;
public:
	enum class Objects { //enum values represent id of all objects
		PLAYER = 61,
		SWORDSMAN,
		SPAWNER,
		DOOR,
		KEY,
		PROJECTILE,
		SPRINTER
	};
public:
	static const int getObjectID(const Objects& obj);
	static Dynamic* getNewObj(int id, const std::string& name, const std::string& parameter);
};