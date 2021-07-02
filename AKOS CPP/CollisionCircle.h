#pragma once
#include "Vector2.h"

class CollisionCircle {
public:
	Vector2 pos;
	int r;
	CollisionCircle() {
		pos = Vector2();
		r = 0;
	}
	CollisionCircle(Vector2 pos, int radius) {
		pos = pos;
		r = radius;
	}
	CollisionCircle(int x, int y, int radius) {
		pos = Vector2(x, y);
		r = radius;
	}
};