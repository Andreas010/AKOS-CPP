#pragma once

#include "SDL.h"

class Color {
public:
	Uint8 r;
	Uint8 g;
	Uint8 b;
	Uint8 a;

	Color() {
		r = 0;
		g = 0;
		b = 0;
		a = 255;
	}
	Color(Uint8 red, Uint8 green, Uint8 blue) {
		r = red;
		g = green;
		b = blue;
		a = 255;
	}
	Color(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha) {
		r = red;
		g = green;
		b = blue;
		a = alpha;
	}
};