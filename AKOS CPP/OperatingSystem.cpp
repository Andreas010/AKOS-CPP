#include "OperatingSystem.h"
#include "TextureManager.h"
#include "KeyboardManager.h"
#include "MouseManager.h"
#include "TextRenderer.h"
#include "Primitive.h"
#include "CollisionManager.h"
#include <string>

#include "ExampleClass.h"

SDL_Event OperatingSystem::event;

//Put your references here
//e.g.
//TestClass* testClass;
ExampleClass* exampleClass;

OperatingSystem::OperatingSystem() {
	OperatingSystem::cnt = 0;
	OperatingSystem::isRunning = false;
	OperatingSystem::renderer = nullptr;
	OperatingSystem::window = nullptr;
}

void OperatingSystem::Init(const char* title, int xPos, int yPos, int width, int height)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		Report("Debug", "SUBSYSTEM_INITIALISED");
		Report("Debug", "");
		Report("Debug", "Engine by Andy010#6381");
		Report("Debug", "Version 1.0");
		Report("Debug", "");

		window = SDL_CreateWindow(title, xPos, yPos, width, height, SDL_WINDOW_SHOWN);
		if (window) {
			Report("Debug", "WINDOW_CREATED");
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			Report("Debug", "RENDERER_CREATED");
		}

		TextureManager::Init(renderer);
		Report("Debug", "TEXTUREMANAGER_INITIALISED");

		KeyboardManager::Init();
		Report("Debug", "KEYBOARD_INITIALISED");

		TextRenderer::Init(renderer);
		Report("Debug", "TEXTMANAGER_INITIALISED");

		MouseManager::Init();
		Report("Debug", "MOUSE_INITIALISED");

		Primitive::Init(renderer);
		Report("Debug", "PRIMITIVE_INITIALISED");

		InitClasses();

		isRunning = true;
	}
	else {
		isRunning = false;
	}
}

void OperatingSystem::InitClasses() {
	//Put your initialisation code here

	exampleClass->Init(renderer);
}

void OperatingSystem::HandleEvents() {
	//KeyboardManager::Init();
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

void OperatingSystem::Update() {
	//Put your update loops here
	exampleClass->Update();
}

void OperatingSystem::Render() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	//Put render code here
	exampleClass->Render();

	SDL_RenderPresent(renderer);
}
void OperatingSystem::Clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	Report("Debug", "OPERATINGSYSTEM_EXIT");
}