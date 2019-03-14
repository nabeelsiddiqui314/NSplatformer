#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player();
public:
	void update() override;
};

