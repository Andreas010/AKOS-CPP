#include "KeyboardManager.h"
#include "SDL.h"

bool keys[512];
bool lastKeys[512];

void KeyboardManager::Init() {

	for (int i = 0; i < 512; i++) {
		keys[i] = false;
		lastKeys[i] = false;
	}
}

void KeyboardManager::Update(SDL_Event keyEvent) {
	
	for (int i = 0; i < 512; i++) {
		lastKeys[i] = keys[i];
	}

	switch (keyEvent.type) {
		case SDL_KEYDOWN:
			keys[OperatingSystem::event.key.keysym.scancode] = true;
			break;
		case SDL_KEYUP:
			keys[OperatingSystem::event.key.keysym.scancode] = false;
			break;
		default:
			break;
	}
}

bool KeyboardManager::GetKey(SDL_Scancode key) {
	return keys[key];
}

bool KeyboardManager::GetKeyUp(SDL_Scancode key) {
	return !keys[key];
}

bool KeyboardManager::GetKeyDown(SDL_Scancode key) {
	return keys[key] && !lastKeys[key];
}