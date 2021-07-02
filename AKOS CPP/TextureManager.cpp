#include "TextureManager.h"
#include "SDL_image.h"

SDL_Renderer* rend;

void TextureManager::Init(SDL_Renderer* renderer) {
	rend = renderer;
}

SDL_Texture* TextureManager::LoadTexture(const char* filename) {
	SDL_Surface* tmpSurface = IMG_Load(filename);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(rend, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	return texture;
}

void TextureManager::DrawTexture(SDL_Texture* texture, Vector2 pos, Vector2 size) {
	SDL_Rect rect;
	rect.x = pos.x;
	rect.y = pos.y;
	rect.w = size.x;
	rect.h = size.y;

	SDL_RenderCopy(rend, texture, NULL, &rect);
}

void TextureManager::DrawTexture(SDL_Texture* texture, Vector2 pos1, Vector2 size1, Vector2 pos2, Vector2 size2) {
	SDL_Rect rect1;
	rect1.x = pos1.x;
	rect1.y = pos1.y;
	rect1.w = size1.x;
	rect1.h = size1.y;

	SDL_Rect rect2;
	rect2.x = pos2.x;
	rect2.y = pos2.y;
	rect2.w = size2.x;
	rect2.h = size2.y;

	SDL_RenderCopy(rend, texture, &rect1, &rect2);
}