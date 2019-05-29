#pragma once
#include "DoorKey.h"

class Door :public Dynamic
{
public:
	Door(const std::string& param);
public:
	int getID() const override;
	void interactWithOther(Dynamic* other) override;
	void update() override;
	void recieveInt(int amount) override;
private:
	int m_key;
	bool m_isLocked = true;
};

