#pragma once
#include <SFML/Graphics.hpp>
#include "Data.h"
#include "Entity.h"

class CollisionDetector
{
public:
	CollisionDetector() = delete;
public:
	static void Collide(Entity* body, const sf::Vector2i& origin);
};