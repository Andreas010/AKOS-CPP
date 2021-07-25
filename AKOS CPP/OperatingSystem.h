#pragma once

#include "SDL.h"
#include "KeyboardManager.h"
#include <iostream>
#include <windows.h>

class OperatingSystem {
public:
	OperatingSystem();

	void Init(const char* title, int xPos, int yPos, int width, int height);
	void InitClasses();

	void HandleEvents();
	void Update();
	void Render();
	void Clean();

	bool Running() { return isRunning; }

	static void Report(const char* type, const char* text) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 9);
		std::cout << '[';
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << type;
		SetConsoleTextAttribute(hConsole, 9);
		std::cout << ']';
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << ' ' << text << std::endl;
		//SetConsoleTextAttribute(hConsole, 15);
	}

	static SDL_Event event;
private:
	bool isRunning;
	int cnt;
	SDL_Window* window;
	SDL_Renderer* renderer;
};