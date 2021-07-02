#include "MouseManager.h"
#include <iostream>

bool mouseButton[5];
bool lastMouseButton[5];

int wheel;
float lastWheel;
Vector2 mousePosition;

void MouseManager::Init() {
	for (int i = 0; i < 5; i++)
	{
		mouseButton[i] = false;
		lastMouseButton[i] = false;
	}
}

void MouseManager::Update(SDL_Event mouseEvent) {
	for (int i = 0; i < 5; i++) {
		lastMouseButton[i] = mouseButton[i];
	}

	//SDL_MOUSEWHEEL SDL_MOUSEBUTTONDOWN SDL_MOUSEBUTTONUP SDL_MOUSEMOTION

	switch (mouseEvent.type) {
		case SDL_MOUSEBUTTONDOWN:
			mouseButton[mouseEvent.button.button-1] = true;
			break;
		case SDL_MOUSEBUTTONUP:
			mouseButton[mouseEvent.button.button-1] = false;
			break;
		case SDL_MOUSEWHEEL:
			wheel = mouseEvent.wheel.y;
			break;
		case SDL_MOUSEMOTION:
			mousePosition = Vector2(mouseEvent.motion.x, mouseEvent.motion.y);
			break;
		default:
			break;
	}
}

bool MouseManager::GetMouse(int index) {
	return mouseButton[index];
}

bool MouseManager::GetMouseUp(int index) {
	return !mouseButton[index];
}

bool MouseManager::GetMouseDown(int index) {
	return mouseButton[index] && !lastMouseButton[index];
}

int MouseManager::GetMouseWheel() {
	return wheel;
}

Vector2 MouseManager::GetMousePosition() {
	return mousePosition;
}

void MouseManager::ResetWheel() {
	wheel = 0;
}