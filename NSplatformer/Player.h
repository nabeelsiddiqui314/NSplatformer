#pragma once
#include "Entity.h"
#include "InputManager.h"

class Player : public Entity
{
public:
	Player();
public:
	void update() override;
};

