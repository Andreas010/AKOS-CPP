#pragma once

#include "SDL.h"
#include "Vector2.h"
#include "Vector4.h"
#include "Color.h"

class Primitive {
public:
	static void Init(SDL_Renderer* renderer);
	static void DrawBox(Vector4 box, Color color);
	static void DrawBoxFilled(Vector4 box, Color color);
	static void DrawLine(Vector2 pos1, Vector2 pos2, Color color);
	static void DrawLine(int x1, int y1, int x2, int y2, Color color);
	static void DrawLine(Vector4 posPair, Color color);
	static void DrawPixel(Vector2 pos, Color color);
	static void DrawPixel(int x, int y, Color color);
};