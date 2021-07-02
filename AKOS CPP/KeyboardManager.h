#pragma once
#include "OperatingSystem.h"
#include "SDL.h"

class KeyboardManager
{
public:
	static void Init();
	static void Update(SDL_Event keyEvent);
	static bool GetKey(SDL_Scancode key);
	static bool GetKeyDown(SDL_Scancode key);
	static bool GetKeyUp(SDL_Scancode key);
};

