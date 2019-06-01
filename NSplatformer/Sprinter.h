#pragma once
#include "Entity.h"
#include "IDmanager.h"

class Sprinter : public Entity
{
public:
	Sprinter(const std::string& name);
public:
	int getID() const override;
	void interactWithOther(Dynamic* other) override;
	void recieveInt(int amount) override;
	void update() override;
private:
	bool m_stop = false;
	xDirection m_direction;
};

