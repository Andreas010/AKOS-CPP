#include "TextRenderer.h"
#include "SDL_image.h"
#include<map>
#include<iostream>

SDL_Renderer* textWindowRenderer;
SDL_Surface* fontImageSurface;
const char* path = "assets/fontImage.png";

std::map<char, int> my_map;

void TextRenderer::Init(SDL_Renderer* renderer) {
	textWindowRenderer = renderer;
	fontImageSurface = IMG_Load(path);
	my_map = std::map<char, int>{
		{' ', 0  },
		{'A', 8  },
		{'0', 8  },
		{'B', 16 },
		{'1', 16 },
		{'C', 24 },
		{'2', 24 },
		{'D', 32 },
		{'3', 32 },
		{'E', 40 },
		{'4', 40 },
		{'F', 48 },
		{'5', 48 },
		{'G', 56 },
		{'6', 56 },
		{'H', 64 },
		{'7', 64 },
		{'I', 72 },
		{'8', 72 },
		{'J', 80 },
		{'9', 80 },
		{'K', 88 },
		{'L', 96 },
		{'M', 104},
		{'N', 112},
		{'O', 120},
		{'P', 128},
		{'Q', 136},
		{'R', 144},
		{'S', 152},
		{'T', 160},
		{'U', 168},
		{'V', 176},
		{'W', 184},
		{'X', 192},
		{'Y', 200},
		{'Z', 208}
	};
}

void TextRenderer::RenderCharacter(char character, Vector2 position, int size, Color color1, Color color2) {
	int index = my_map[character];
	//TextureManager::DrawTexture(render, fontImage, Vector2(index, 0), Vector2(8, 8), position, Vector2(8 * size, 8 * size));

	SDL_Rect rect1;
	rect1.x = index;
	rect1.y = 0;
	rect1.w = 8;
	rect1.h = 8;

	SDL_Rect rect2;
	rect2.x = position.x;
	rect2.y = position.y;
	rect2.w = 8 * size;
	rect2.h = 8 * size;

	//SDL_SetColorKey(fontImageSurface, SDL_TRUE, SDL_MapRGB(fontImageSurface->format, 255, 255, 255));
	SDL_LockSurface(fontImageSurface);

	fontImageSurface->format->palette->ncolors = 2;

	fontImageSurface->format->palette->colors[0].r = color2.r;
	fontImageSurface->format->palette->colors[0].g = color2.g;
	fontImageSurface->format->palette->colors[0].b = color2.b;
	fontImageSurface->format->palette->colors[0].a = color2.a;

	fontImageSurface->format->palette->colors[1].r = color1.r;
	fontImageSurface->format->palette->colors[1].g = color1.g;
	fontImageSurface->format->palette->colors[1].b = color1.b;
	fontImageSurface->format->palette->colors[1].a = color1.a;

	SDL_UnlockSurface(fontImageSurface);

	SDL_Texture* fontImage = SDL_CreateTextureFromSurface(textWindowRenderer, fontImageSurface);

	SDL_RenderCopy(textWindowRenderer, fontImage, &rect1, &rect2);

	SDL_DestroyTexture(fontImage);
}

void TextRenderer::RenderText(const char* text, Vector2 position, int size, Color color1, Color color2) {
	for (int i = 0; i < SDL_strlen(text); i++)
	{
		RenderCharacter(text[i], Vector2(position.x + (i * 8 * size), position.y), size, color1, color2);
	}
}