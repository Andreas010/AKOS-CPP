#pragma once
#include "TextureManager.h"
#include "OperatingSystem.h"
#include "Vector2.h"

class StartScreen
{
public:
	void Init();
	void ShowLoadingBar(int curValue);
};