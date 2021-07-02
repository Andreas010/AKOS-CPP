#pragma once
#include "CollisionBox.h"
#include "Vector2.h"
#include "CollisionCircle.h"
#include <math.h>

class CollisionManager {
public:
	static bool AABB(CollisionBox box1, CollisionBox box2) {
		return box1.pos.x < box2.pos.x + box2.size.x &&
			box1.pos.x + box1.size.x > box2.pos.x &&
			box1.pos.y < box2.pos.y + box2.size.y &&
			box1.pos.y + box1.size.y > box2.pos.y;
	}
	static bool AAB(CollisionBox box1, Vector2 position) {
		return box1.pos.x < position.x &&
			box1.pos.x + box1.size.x > position.x &&
			box1.pos.y < position.y &&
			box1.pos.y + box1.size.y > position.y;
	}
	static bool AB(Vector2 position1, Vector2 position2) {
		return position1 == position2;
	}
	static bool CRCR(CollisionCircle circle1, CollisionCircle circle2) {
		int dx = circle1.pos.x - circle2.pos.x;
		int dy = circle1.pos.y - circle2.pos.y;

		double distance = sqrt(dx * dx + dy * dy);

		return distance < circle1.r + circle2.r;
	}
	static bool CRB(CollisionCircle circle, Vector2 position) {
		int dx = circle.pos.x - position.x;
		int dy = circle.pos.y - position.y;

		double distance = sqrt(dx * dx + dy * dy);

		return distance < circle.r;
	}
};