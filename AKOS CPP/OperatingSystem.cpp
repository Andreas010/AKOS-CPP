#include "OperatingSystem.h"
#include "TextureManager.h"
#include "StartScreen.h"
#include "KeyboardManager.h"
#include "MouseManager.h"
#include "TextRenderer.h"
#include <string>

SDL_Event OperatingSystem::event;
StartScreen startScreen;
TextRenderer textRenderer;

OperatingSystem::OperatingSystem() {
	OperatingSystem::cnt = 0;
	OperatingSystem::isRunning = false;
	OperatingSystem::renderer = nullptr;
	OperatingSystem::window = nullptr;
}

OperatingSystem::~OperatingSystem() {

}

void OperatingSystem::Init(const char* title, int xPos, int yPos, int width, int height)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		Report("SUBSYSTEM_INITIALISED");

		window = SDL_CreateWindow(title, xPos, yPos, width, height, SDL_WINDOW_SHOWN);
		if (window) {
			Report("WINDOW_CREATED");
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			Report("RENDERER_CREATED");
		}

		TextureManager::Init(renderer);
		Report("TEXTUREMANAGER_INITIALISED");

		KeyboardManager::Init();
		Report("KEYBOARD_INITIALISED");

		startScreen.Init(renderer);
		Report("SCREENTEST_INITIALISED");

		TextRenderer::Init(renderer);
		Report("TEXTMANAGER_INITIALISED");

		MouseManager::Init();
		Report("MOUSE_INITIALISED");

		isRunning = true;
	}
	else {
		isRunning = false;
	}
}

void OperatingSystem::HandleEvents() {
	KeyboardManager::Init();
	MouseManager::Init();

	while (SDL_PollEvent(&event)) {
		Uint32 curEvent = event.type;

		//if (curEvent == SDL_QUIT)
		//	isRunning = false;
		//else if (curEvent == SDL_KEYDOWN || curEvent == SDL_KEYUP)
		//	KeyboardManager::Update(event);
		//else if (curEvent == SDL_MOUSEWHEEL || curEvent == SDL_MOUSEBUTTONDOWN || curEvent == SDL_MOUSEBUTTONUP || curEvent == SDL_MOUSEMOTION)
		//	MouseManager::Update(event);

		//switch (curEvent) {
		//case SDL_QUIT:
		//	isRunning = false;
		//	break;
		//case SDL_KEYDOWN:
		//case SDL_KEYUP:
		//	KeyboardManager::Update(event);
		//	break;
		//case SDL_MOUSEWHEEL:
		//case SDL_MOUSEBUTTONDOWN:
		//case SDL_MOUSEBUTTONUP:
		//case SDL_MOUSEMOTION:
		//	MouseManager::Update(event);
		//	break;
		//}

		if (curEvent == SDL_QUIT)
			isRunning = false;
		
		KeyboardManager::Update(event);
		MouseManager::Update(event);
	}
}

void OperatingSystem::Render() {
	SDL_RenderClear(renderer);
	//render stuff
	startScreen.ShowLoadingBar(0);

	SDL_RenderPresent(renderer);
}

void OperatingSystem::Update() {
	
}

void OperatingSystem::Clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	Report("OPERATINGSYSTEM_EXIT");
}