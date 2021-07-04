#pragma once

class Vector4 {
public:
	Vector2 pos1;
	Vector2 pos2;

	Vector4() {
		pos1 = Vector2();
		pos2 = Vector2();
	}
	Vector4(Vector2 position1, Vector2 position2) {
		pos1 = position1;
		pos2 = position2;
	}
	Vector4(int x1, int y1, int x2, int y2) {
		pos1 = Vector2(x1, y1);
		pos2 = Vector2(y2, y2);
	}
};