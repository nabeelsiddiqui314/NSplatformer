#include "stdafx.h"
#include "CollisionDetector.h"

void CollisionDetector::CollideWall(Type type, Entity* body, const sf::Vector2i& origin, float offset) {
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
			body->stopJump(origin.y + offset + 1);
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

void CollisionDetector::CollideSlopeTop(Entity* body, const sf::Vector2i& origin, float slope, float intercept) {
	float x = slope < 0 ? body->getPos().x - body->getSize().x - origin.x : body->getPos().x - origin.x;
	float oldX = slope < 0 ? body->getOldPos().x - body->getSize().x - origin.x : body->getOldPos().x - origin.x;
	float y = body->getPos().y + body->getSize().y - origin.y;
	float oldY = body->getOldPos().y + body->getSize().y - origin.y;

	float crossProduct = x * slope - y;
	float oldCrossProduct = oldX * slope - oldY;

	if (crossProduct < 1 && oldCrossProduct > -1) {
		body->stopFall(origin.y + slope * x + intercept - body->getSize().y - 1.2);
	}
}



