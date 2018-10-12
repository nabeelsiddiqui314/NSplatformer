#include "stdafx.h"
#include "CollisionDetector.h"

void CollisionDetector::isCollidingWall(Type type, Entity* body, const sf::Vector2f& origin, float offset) {
	switch (type) {
	case Type::Top:
	{
		float y = body->getPos().y + body->getSize().y - origin.y;
		float oldY = body->getOldPos().y + body->getSize().y - origin.y;

		if (y > offset && oldY < offset) {
			body->stopFall(origin.y + offset - body->getSize().y);
		}
	}
		break;

	case Type::Bottom:
	{
		float y = body->getPos().y - origin.y;
		float oldY = body->getOldPos().y - origin.y;

		if (y < offset && oldY > offset) {
			body->stopJump();
		}
	}
		break;

	case Type::Left:
	{
		float x = body->getPos().x + body->getSize().x - origin.x;
		float oldX = body->getOldPos().x + body->getSize().x - origin.x;

		if (x > offset && oldX < offset) {
			body->stopLateral(origin.x + offset - body->getSize().x);
		}
	}
		break;

	case Type::Right:
	{
		float x = body->getPos().x - origin.x;
		float oldX = body->getOldPos().x - origin.x;

		if (x < offset && oldX > offset) {
			body->stopLateral(origin.x + offset);
		}
	}
		break;
	}
}

void CollisionDetector::isCollidingSlopeTop(Entity* body, int row, int column, float slope) {
	
}



