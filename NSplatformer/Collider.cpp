#include "stdafx.h"
#include "Collider.h"

void Collider::Collide(Entity* entity, const int tile, const int row, const int column) {
	sf::Vector2i origin = { column * Data::tileSize, row * Data::tileSize };
	switch (tile) {
	case 1:
		CollisionDetector::isCollidingWall(CollisionDetector::Top, entity, origin, 1);
		CollisionDetector::isCollidingWall(CollisionDetector::Bottom, entity, origin, Data::tileSize);
		if (entity->getPos().y + entity->getSize().y > origin.y) {
			CollisionDetector::isCollidingWall(CollisionDetector::Left, entity, origin, 1);
			CollisionDetector::isCollidingWall(CollisionDetector::Right, entity, origin, Data::tileSize);
		}
		break;
	case 2:
		CollisionDetector::isCollidingWall(CollisionDetector::Top, entity, origin, Data::tileSize);
		break;
	}
}
