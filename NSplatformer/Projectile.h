#pragma once
#include "Dynamic.h"
#include "Direction.h"
#include "Data.h"

class Projectile : public Dynamic
{
public:
	void init(const std::string& name, float velocity, int damage, bool friendly);
	void setDirection(const xDirection& dir);

	void interactWithTile(const sf::Vector2f& tilePos, const sf::Vector2f& tileSize) override;
	void interactWithOther(Dynamic* other) override;
	void update() override;
private:
	float m_translation;
	int m_damage;
};