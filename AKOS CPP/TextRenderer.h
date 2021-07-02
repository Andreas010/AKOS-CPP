#pragma once

#include "SDL.h"
#include "TextureManager.h"
#include "Color.h"

class TextRenderer
{
public:
	static void Init(SDL_Renderer* renderer);
	static void DrawCharacter(char character, Vector2 position, int size, Color color1, Color color2);
	static void DrawText(const char* text, Vector2 position, int size, Color color1, Color color2);
private:
	static void Setpixel(SDL_Surface* surface, int x, int y, Color pyxel);
};