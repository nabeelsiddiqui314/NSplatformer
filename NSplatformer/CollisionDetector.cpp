#include "stdafx.h"
#include "CollisionDetector.h"

void CollisionDetector::isCollidingWall(Type type, Entity* body, const sf::Vector2i& origin, float offset) {
	switch (type) {
	case Type::Top:
	{
		float y = body->getPos().y + body->getSize().y - origin.y;
		float oldY = body->getOldPos().y + body->getSize().y - origin.y;

		if (y > offset && oldY < offset) {
			body->stopFall(origin.y + offset - body->getSize().y - 1); // -1 is pushes he tile up so it falls back
		}
	}
		break;

	case Type::Bottom:
	{
		float y = body->getPos().y - origin.y;
		float oldY = body->getOldPos().y - origin.y;

		if (y < offset && oldY > offset) {
			body->stopJump(origin.y + offset);
		}
	}
		break;

	case Type::Left:
	{
		float x = body->getPos().x + body->getSize().x - origin.x;
		float oldX = body->getOldPos().x + body->getSize().x - origin.x;

		if (x > offset && oldX < offset) {
			body->stopLateral(origin.x + offset - body->getSize().x - 1);
		}
	}
		break;

	case Type::Right:
	{
		float x = body->getPos().x - origin.x;
		float oldX = body->getOldPos().x - origin.x;

		if (x < offset && oldX > offset) {
			body->stopLateral(origin.x + offset + 1);
		}
	}
		break;
	}
}

void CollisionDetector::isCollidingSlopeTop(Entity* body, int row, int column, float slope) {
	
}



