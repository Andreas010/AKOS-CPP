#pragma once

#include "SDL.h"
#include "Vector2.h"

class TextureManager {
public:
	static void Init(SDL_Renderer* renderer);
	static SDL_Texture* LoadTexture(const char* filename);
	static void DrawTexture(SDL_Texture* texture, Vector2 pos, Vector2 size);
	static void DrawTexture(SDL_Texture* texture, Vector2 pos1, Vector2 size1, Vector2 pos2, Vector2 size2);
};