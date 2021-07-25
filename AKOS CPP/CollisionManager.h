#pragma once
#include "Vector4.h"
#include "Vector2.h"
#include "CollisionCircle.h"
#include "Primitive.h"
#include <math.h>

class CollisionManager {
public:
	static bool AABB(Vector4 box1, Vector4 box2, bool debug = false) {
		if (debug) {
			Primitive::DrawBox(box1, Color(0, 0, 255));
			Primitive::DrawBox(box2, Color(0, 0, 255));
		}

		return box1.pos1.x < box2.pos1.x + box2.pos2.x &&
			box1.pos1.x + box1.pos2.x > box2.pos1.x &&
			box1.pos1.y < box2.pos1.y + box2.pos2.y &&
			box1.pos1.y + box1.pos2.y > box2.pos1.y;
	}
	static bool AAB(Vector4 box1, Vector2 position, bool debug = false) {
		if (debug) {
			Primitive::DrawBox(box1, Color(0, 0, 255));
			Primitive::DrawPixel(position, Color(0, 0, 255));
		}

		return box1.pos1.x < position.x &&
			box1.pos1.x + box1.pos2.x > position.x &&
			box1.pos1.y < position.y &&
			box1.pos1.y + box1.pos2.y > position.y;
	}
	static bool AB(Vector2 position1, Vector2 position2, bool debug = false) {
		if (debug) {
			Primitive::DrawPixel(position1, Color(0, 0, 255));
			Primitive::DrawPixel(position2, Color(0, 0, 255));
		}
		return position1 == position2;
	}
	static bool CRCR(CollisionCircle circle1, CollisionCircle circle2, bool debug = false) {
		if (debug) {
			Vector4 box1 = Vector4(circle1.pos.x - circle1.r, circle1.pos.y - circle1.r, circle1.r * 2, circle1.r * 2);
			Primitive::DrawBox(box1, Color(0, 255, 255));
			Vector4 box2 = Vector4(circle2.pos.x - circle2.r, circle2.pos.y - circle2.r, circle2.r * 2, circle2.r * 2);
			Primitive::DrawBox(box2, Color(0, 255, 255));
		}
		int dx = circle1.pos.x - circle2.pos.x;
		int dy = circle1.pos.y - circle2.pos.y;

		double distance = sqrt(dx * dx + dy * dy);

		return distance < circle1.r + circle2.r;
	}
	static bool CRB(CollisionCircle circle, Vector2 position, bool debug = false) {
		if (debug) {
			Vector4 box = Vector4(circle.pos.x - circle.r, circle.pos.y - circle.r, circle.r * 2, circle.r * 2);
			Primitive::DrawBox(box, Color(0, 255, 255));
			Primitive::DrawPixel(position, Color(0, 0, 255));
		}
		int dx = circle.pos.x - position.x;
		int dy = circle.pos.y - position.y;

		double distance = sqrt(dx * dx + dy * dy);

		return distance < circle.r;
	}
};