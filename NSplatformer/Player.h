#pragma once
#include "Entity.h"
#include "InputManager.h"
#include "Projectile.h"
#include "IDmanager.h"

class Player : public Entity
{
public:
	Player();
public:
	int getID() const override;
	void update() override;
	void interactWithOther(Dynamic* other) override;
	void recieveInt(int amount) override;

	const sf::Vector2f getCentre() const;
private:
	bool m_isAttacking = false;
	bool m_isCrouching = false;
};

