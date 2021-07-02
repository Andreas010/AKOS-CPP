#pragma once
#include "SDL.h"
#include "Vector2.h"

class MouseManager
{
public:
	static void Init();
	static void Update(SDL_Event mouseEvent);
	static bool GetMouse(int key);
	static bool GetMouseDown(int key);
	static bool GetMouseUp(int key);
	static int GetMouseWheel();
	static Vector2 GetMousePosition();
	static void ResetWheel();
};