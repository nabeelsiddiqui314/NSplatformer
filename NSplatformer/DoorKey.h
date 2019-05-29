#pragma once
#include "Dynamic.h"
#include "IDmanager.h"

class DoorKey : public Dynamic
{
public:
	DoorKey(const std::string& param);
public:
	void interactWithOther(Dynamic* other);
	void update() override {}
	int getID() const override;
	void render(sf::RenderWindow& window) override;
private:
	int m_key;
	bool m_isObtained = false;
};