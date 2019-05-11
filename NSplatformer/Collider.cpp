#include "stdafx.h"
#include "Collider.h"

void Collider::Collide(Dynamic* obj, const int tile, const int row, const int column) {
	switch (tile) {
	case 0:
		break;
	default:
		obj->interactWithTile({ static_cast<float>(Data::tile::size * column), 
			                    static_cast<float>(Data::tile::size * row)}, 
			                  { static_cast<float>(Data::tile::size),
			                    static_cast<float>(Data::tile::size)});;
	}
}