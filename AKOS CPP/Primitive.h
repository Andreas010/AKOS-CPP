#pragma once
#include "SDL.h"
#include "Vector2.h"
#include "Vector4.h"
#include "Color.h"

class Primitive {
public:
	void Init(SDL_Renderer* renderer) {
		render = renderer;
	}
	void DrawBox(Vector4 box, Color color) {
		SDL_SetRenderDrawColor(render, color.r, color.g, color.b, color.a);
		SDL_Rect* rect = new SDL_Rect();
		rect->x = box.pos1.x;
		rect->y = box.pos1.y;
		rect->w = box.pos2.x;
		rect->h = box.pos2.y;
		SDL_RenderDrawRect(render, rect);
	}
	void DrawBoxFilled(Vector4 box, Color color) {
		SDL_SetRenderDrawColor(render, color.r, color.g, color.b, color.a);
		for (int i = 0; i < box.pos2.y - box.pos1.y; i++)
		{
			DrawLine(Vector2(box.pos1.x, box.pos1.y + i), Vector2(box.pos2.x, box.pos1.y + i), color);
		}
	}
	void DrawLine(Vector2 pos1, Vector2 pos2, Color color) {
		DrawLine(Vector4(pos1, pos2), color);
	}
	void DrawLine(int x1, int y1, int x2, int y2, Color color) {
		DrawLine(Vector4(x1, y1, x2, y2), color);
	}
	void DrawLine(Vector4 posPair, Color color) {
		SDL_SetRenderDrawColor(render, color.r, color.g, color.b, color.a);
		SDL_RenderDrawLine(render, posPair.pos1.x, posPair.pos1.y, posPair.pos2.x, posPair.pos2.y);
	}
	void DrawPixel(Vector2 pos, Color color) {
		SDL_SetRenderDrawColor(render, color.r, color.g, color.b, color.a);
		SDL_RenderDrawPoint(render, pos.x, pos.y);
	}
	void DrawPixel(int x, int y, Color color) {
		SDL_SetRenderDrawColor(render, color.r, color.g, color.b, color.a);
		SDL_RenderDrawPoint(render, x, y);
	}
private:
	SDL_Renderer* render;
};