#include "stdafx.h"
#include "Collider.h"

void Collider::Collide(Dynamic* obj, const int tile, const int row, const int column) {
	if (tile % 6 <= 3 && tile % 6 != 0) {
		obj->interactWithTile(sf::Vector2f(column * Data::tile::size, row * Data::tile::size), sf::Vector2f(Data::tile::size, Data::tile::size));
	}
}