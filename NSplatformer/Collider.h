#pragma once
#include <SFML/Graphics.hpp>
#include "CollisionDetector.h"

class Collider
{
public:
	Collider() = delete;
public:
	static void Collide(Entity* entity, const int tile, const int row, const int column);
};

