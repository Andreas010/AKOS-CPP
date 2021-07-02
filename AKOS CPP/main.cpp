#define SDL_MAIN_HANDLED
#include "OperatingSystem.h"
#include "SDL.h"
#include "TextRenderer.h"

OperatingSystem* os = nullptr;

int main() {

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	os = new OperatingSystem();

	os->Init("AKOS", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600);

	while (os->Running()) {
		frameStart = SDL_GetTicks();

		os->HandleEvents();
		os->Update();
		os->Render();

		frameTime = SDL_GetTicks() - frameStart;
		
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}

	os->Clean();

	return 0;
}