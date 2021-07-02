#pragma once

class Vector2
{
public:
	int x;
	int y;

	Vector2() {
		this->x = 0;
		this->y = 0;
	}
	Vector2(int x, int y) {
		this->x = x;
		this->y = y;
	}

	Vector2 Half() {
		return Vector2(x, y) / Vector2(2, 2);
	}

	int Distance(Vector2 a, Vector2 b) {
		return (Abs(b.x) + Abs(b.y)) - (Abs(a.x) + Abs(a.y));
	}

	Vector2 operator+(Vector2 value) {
		return Vector2(x + value.x, y + value.y);
	}
	Vector2 operator-(Vector2 value) {
		return Vector2(x - value.x, y - value.y);
	}
	Vector2 operator*(Vector2 value) {
		return Vector2(x * value.x, y * value.y);
	}
	Vector2 operator/(Vector2 value) {
		return Vector2(x / value.x, y / value.y);
	}
	bool operator==(Vector2 value) {
		return x == value.x && y == value.y;
	}

private:
	int Abs(int value) {
		if (value < 0)
			return -value;
		return value;
	}
};