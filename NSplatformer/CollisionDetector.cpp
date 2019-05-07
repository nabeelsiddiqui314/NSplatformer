#include "stdafx.h"
#include "CollisionDetector.h"

void CollisionDetector::Collide(Entity* body, const sf::Vector2i& origin) {
	float y = body->getPos().y + body->getSize().y - origin.y;
	float oldY = body->getOldPos().y + body->getSize().y - origin.y;

	if (y > 0 && oldY < 0) {
		body->stopFall(origin.y - body->getSize().y - 1); // -1 pushes it up so it falls back
	}

	y = body->getPos().y - origin.y;
	oldY = body->getOldPos().y - origin.y;

	if (y < Data::tile::size && oldY > Data::tile::size) {
		body->stopJump(origin.y + Data::tile::size + 1);
	}

	float x = body->getPos().x + body->getSize().x - origin.x;
	float oldX = body->getOldPos().x + body->getSize().x - origin.x;

	if (x > 0 && oldX < 0) {
		body->stopLateral(origin.x + 0 - body->getSize().x - 1);
	}

	x = body->getPos().x - origin.x;
	oldX = body->getOldPos().x - origin.x;

	if (x < Data::tile::size && oldX > Data::tile::size) {
		body->stopLateral(origin.x + Data::tile::size + 1);
	}
}