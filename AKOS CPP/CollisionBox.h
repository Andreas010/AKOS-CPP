#pragma once
#include "Vector2.h"

class CollisionBox {
public:
	Vector2 pos;
	Vector2 size;

	CollisionBox() {
		pos = Vector2();
		size = Vector2();
	}
	CollisionBox(Vector2 position, Vector2 size) {
		pos = position;
		this->size = size;
	}
	CollisionBox(int x, int y, int w, int h) {
		pos = Vector2(x, y);
		size = Vector2(w, h);
	}
};