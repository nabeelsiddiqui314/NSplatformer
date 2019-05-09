#include "stdafx.h"
#include "CollisionResponder.h"

void CollisionResponder::Collide(Entity* body, const sf::Vector2i& origin) {
	float x = body->getPos().x + body->getSize().x - origin.x;

	float y = body->getPos().y + body->getSize().y - origin.y;
	float oldY = body->getOldPos().y + body->getSize().y - origin.y;

	if (y > 1 && oldY <= 1 && x != 0) {
		body->stopFall(origin.y - body->getSize().y);
	}

	y = body->getPos().y - origin.y;
	oldY = body->getOldPos().y - origin.y;

	if (y < Data::tile::size && oldY >= Data::tile::size && x != 0) {
		body->stopJump(origin.y + Data::tile::size);
	}

	float oldX = body->getOldPos().x + body->getSize().x - origin.x;

	y = body->getPos().y + body->getSize().y - origin.y;

	if (x > 1 && oldX <= 1 && y != 0) {
		body->stopLateral(origin.x - body->getSize().x);
	}

	x = body->getPos().x - origin.x;
	oldX = body->getOldPos().x - origin.x;

	if (x < Data::tile::size && oldX >= Data::tile::size && y != 0) {
		body->stopLateral(origin.x + Data::tile::size);
	}
}