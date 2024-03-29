#pragma once
#include "Entity.h"
#include "IDmanager.h"

class Swordsman : public Entity
{
public:
	Swordsman(const std::string& name);
public:
	int getID() const override;
	void interactWithOther(Dynamic* other) override;
	void recieveInt(int amount) override;
	void update() override;
private:
	xDirection m_direction;
	float m_swordDistance;
	bool m_stop = true;
	bool m_didHit = false;
};

