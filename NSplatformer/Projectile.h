#pragma once
#include "Dynamic.h"
#include "Direction.h"

class Projectile : public Dynamic
{
public:
	enum ProjectileType {

	};
public:
	Projectile();
public:
	void setType(const ProjectileType& type);
	void setTranslation(const xDirection& xDir, const yDirection& yDir, float velocity);
	const ProjectileType& getType() const;

	void interactWithTile(const sf::Vector2f& tilePos, const sf::Vector2f& tileSize) override;
	void update() override;
private:
	sf::Vector2f m_translation;
	ProjectileType m_type;
	float m_baseDamage;
};