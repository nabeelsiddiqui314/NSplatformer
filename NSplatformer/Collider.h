#pragma once
#include <SFML/Graphics.hpp>
#include "Data.h"
#include "Dynamic.h"

class Collider
{
public:
	Collider() = delete;
public:
	static void Collide(Dynamic* obj, const int tile, const int row, const int column);
};

