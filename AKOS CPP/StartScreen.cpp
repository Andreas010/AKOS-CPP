#include "StartScreen.h"
#include "KeyboardManager.h"
#include "MouseManager.h"
#include "FileSystem.h"
#include "CollisionCircle.h"
#include "CollisionManager.h"

int curValue;
int maxValue;

void StartScreen::Init() {
	maxValue = 60 * 5;
}

void StartScreen::ShowLoadingBar() {
	curValue++;

	
}