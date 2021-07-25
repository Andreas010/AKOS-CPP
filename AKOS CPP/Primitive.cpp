#include "Primitive.h"

SDL_Renderer* primitiveWindowRenderer;

void Primitive::Init(SDL_Renderer* renderer) {
	primitiveWindowRenderer = renderer;
}
void Primitive::DrawBox(Vector4 box, Color color) {
	SDL_SetRenderDrawColor(primitiveWindowRenderer, color.r, color.g, color.b, color.a);
	SDL_Rect* rect = new SDL_Rect();
	rect->x = box.pos1.x;
	rect->y = box.pos1.y;
	rect->w = box.pos2.x;
	rect->h = box.pos2.y;
	SDL_RenderDrawRect(primitiveWindowRenderer, rect);
}
void Primitive::DrawBoxFilled(Vector4 box, Color color) {
	SDL_SetRenderDrawColor(primitiveWindowRenderer, color.r, color.g, color.b, color.a);
	SDL_Rect* rect = new SDL_Rect();
	rect->x = box.pos1.x;
	rect->y = box.pos1.y;
	rect->w = box.pos2.x;
	rect->h = box.pos2.y;
	SDL_RenderFillRect(primitiveWindowRenderer, rect);
}
void Primitive::DrawLine(Vector2 pos1, Vector2 pos2, Color color) {
	DrawLine(Vector4(pos1, pos2), color);
}
void Primitive::DrawLine(int x1, int y1, int x2, int y2, Color color) {
	DrawLine(Vector4(x1, y1, x2, y2), color);
}
void Primitive::DrawLine(Vector4 posPair, Color color) {
	SDL_SetRenderDrawColor(primitiveWindowRenderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawLine(primitiveWindowRenderer, posPair.pos1.x, posPair.pos1.y, posPair.pos2.x, posPair.pos2.y);
}
void Primitive::DrawPixel(Vector2 pos, Color color) {
	SDL_SetRenderDrawColor(primitiveWindowRenderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawPoint(primitiveWindowRenderer, pos.x, pos.y);
}
void Primitive::DrawPixel(int x, int y, Color color) {
	SDL_SetRenderDrawColor(primitiveWindowRenderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawPoint(primitiveWindowRenderer, x, y);
}