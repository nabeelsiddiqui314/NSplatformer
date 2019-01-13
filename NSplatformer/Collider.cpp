#include "stdafx.h"
#include "Collider.h"

void Collider::Collide(Entity* entity, const int tile, const int row, const int column) {
	switch (tile) {
	case 0:
		break;
	default:
		CollisionDetector::Collide(entity, { column * Data::tile::size, row * Data::tile::size });
	}
}
