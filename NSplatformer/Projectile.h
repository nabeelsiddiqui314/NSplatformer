#pragma once
#include "Dynamic.h"
#include "Direction.h"
#include "Data.h"
#include "IDmanager.h"

class Projectile : public Dynamic
{
public:
	Projectile(const std::string& name, const std::string& parameter);

	int getID() const override;
	void interactWithTile(const sf::Vector2f& tilePos, const sf::Vector2f& tileSize) override;
	void interactWithOther(Dynamic* other) override;
	void update() override;
private:
	ObjectDataParser m_parser;
	float m_translation;
	int m_damage;
	xDirection m_direction;
};