#pragma once
#include "Entity.h"
#include "InputManager.h"

class Player : public Entity
{
public:
	Player();
public:
	void update() override;

	const sf::Vector2f& getVel() const;
	bool isInJump() const;
	const xDirection& getDir() const;
	const sf::Vector2f getCentre() const;
};

