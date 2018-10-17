#include "stdafx.h"
#include "Collider.h"

void Collider::Collide(Entity* entity, const int tile, const int row, const int column) {
	sf::Vector2i origin = { column * Data::tileSize, row * Data::tileSize };
	switch (tile) {
	case 1:
		CollisionDetector::CollideWall(CollisionDetector::Top, entity, origin, 0);
		CollisionDetector::CollideWall(CollisionDetector::Bottom, entity, origin, Data::tileSize);
		CollisionDetector::CollideWall(CollisionDetector::Left, entity, origin, 0);
		CollisionDetector::CollideWall(CollisionDetector::Right, entity, origin, Data::tileSize);
		break;
	case 2:
		CollisionDetector::CollideWall(CollisionDetector::Top, entity, origin, Data::tileSize);
		break;
	case 3:
		CollisionDetector::CollideSlopeTop(entity, origin, -1, 0);
		CollisionDetector::CollideWall(CollisionDetector::Top, entity, origin, Data::tileSize);
		break;
	case 4:
		CollisionDetector::CollideSlopeTop(entity, origin, 1, 0);
		CollisionDetector::CollideWall(CollisionDetector::Left, entity, origin, 0);
		break;
	}
}
