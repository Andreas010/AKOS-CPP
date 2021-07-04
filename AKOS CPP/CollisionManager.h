#pragma once
#include "Vector4.h"
#include "Vector2.h"
#include "CollisionCircle.h"
#include <math.h>

class CollisionManager {
public:
	static bool AABB(Vector4 box1, Vector4 box2) {
		return box1.pos1.x < box2.pos1.x + box2.pos2.x &&
			box1.pos1.x + box1.pos2.x > box2.pos1.x &&
			box1.pos1.y < box2.pos1.y + box2.pos2.y &&
			box1.pos1.y + box1.pos2.y > box2.pos1.y;
	}
	static bool AAB(Vector4 box1, Vector2 position) {
		return box1.pos1.x < position.x &&
			box1.pos1.x + box1.pos2.x > position.x &&
			box1.pos1.y < position.y &&
			box1.pos1.y + box1.pos2.y > position.y;
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