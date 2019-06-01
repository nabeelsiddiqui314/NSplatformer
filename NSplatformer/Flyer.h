#pragma once
#include "Dynamic.h"
#include "IDmanager.h"

class Flyer : public Dynamic
{
public:
	Flyer(const std::string& name);
	int getID() const override;
	void interactWithOther(Dynamic* other) override;
	void update() override;
private:
	ObjectDataParser m_parser;
	sf::Vector2f m_targetVector;
	int m_damage;
	float m_velocity;
};

