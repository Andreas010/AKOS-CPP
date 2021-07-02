#pragma once

#ifndef OperatingSystem_h

#define OperatingSystem_h
#include "SDL.h"
#include "KeyboardManager.h"
#include "StartScreen.h"
#include <iostream>
#include <windows.h>

class OperatingSystem {
public:
	OperatingSystem();
	~OperatingSystem();

	void Init(const char* title, int xPos, int yPos, int width, int height);
	
	void HandleEvents();
	void Update();
	void Render();
	void Clean();

	bool Running() { return isRunning; }

	static SDL_Event event;
private:
	bool isRunning;
	int cnt;
	SDL_Window* window;
	SDL_Renderer* renderer;

	void Report(const char* text) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 9);
		std::cout << '[';
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << "DEBUG";
		SetConsoleTextAttribute(hConsole, 9);
		std::cout << ']';
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << ' ' << text << std::endl;
		//SetConsoleTextAttribute(hConsole, 15);
	}
};

#endif /* OperatingSystem_hpp */