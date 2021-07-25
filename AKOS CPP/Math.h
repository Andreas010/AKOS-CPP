#pragma once

class Math {
public:
	static int Clamp(int curValue, int min, int max) {
		if (curValue < min)
			return min;
		else if (curValue > max)
			return max;
		else return curValue;
	}
};