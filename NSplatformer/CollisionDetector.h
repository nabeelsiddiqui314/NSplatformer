#pragma once
#include <SFML/Graphics.hpp>
#include "Data.h"
#include "Entity.h"

class CollisionDetector
{
public:
	enum Type {
		Top,
		Bottom,
		Left,
		Right
	};
public:
	CollisionDetector() = delete;
public:
	static void CollideWall(Type type, Entity* body, const sf::Vector2i& origin, float offset);
	static void CollideSlopeTop(Entity* body, const sf::Vector2i& origin, float slope, float intercept);

};

