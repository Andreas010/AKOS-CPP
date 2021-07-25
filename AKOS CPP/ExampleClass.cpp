#include "ExampleClass.h"
#include "TextureManager.h"
#include "Vector2.h"
#include "CollisionManager.h"
#include "Vector4.h"
#include "Primitive.h"
#include "Color.h"
#include "TextRenderer.h"
#include "Math.h"

#include "KeyboardManager.h"
#include "MouseManager.h"

//Name: ClassName + Renderer
SDL_Renderer* ExampleClassRenderer;

SDL_Texture* playerTexture;
SDL_Texture* obstacleTexture;
int speed;
Vector2 pos;
Vector2 lastPos;
Vector2 vel;

void ExampleClass::Init(SDL_Renderer* renderer) {
	//Load the player Texture
	playerTexture = TextureManager::LoadTexture("assets/Player.png");
	//Load some obstacle Texture
	obstacleTexture = TextureManager::LoadTexture("assets/checkBox.png");
	//Screen size = 800x600 aka place the player at the center of the screen
	pos = Vector2(400, 300);

	speed = 2;
}

void ExampleClass::Update() {
	//Reset the velocity
	vel = Vector2();

	//Check for input
	if (KeyboardManager::GetKey(SDL_SCANCODE_A))
		vel.x = -speed;
	else if (KeyboardManager::GetKey(SDL_SCANCODE_D))
		vel.x = speed;
	if (KeyboardManager::GetKey(SDL_SCANCODE_W))
		vel.y = -speed;
	else if (KeyboardManager::GetKey(SDL_SCANCODE_S))
		vel.y = speed;

	//Apply the velocity
	pos = pos + vel;

	//Crude CollisionSystem

	if (CollisionManager::AABB(
		Vector4(pos - Vector2(32, 32), Vector2(64, 64)),
		Vector4(Vector2(600, 200) - Vector2(64, 64), Vector2(128, 128))
	))
	{
		pos = lastPos;
		OperatingSystem::Report("ExampleClass", "Collision Detected");
	}

	pos.x = Math::Clamp(pos.x, 32, 800 - 32);
	pos.y = Math::Clamp(pos.y, 32, 600 - 32);

	lastPos = pos;
}

void ExampleClass::Render() {
	TextureManager::DrawTexture(playerTexture, pos - Vector2(32, 32), Vector2(64, 64));
	TextureManager::DrawTexture(obstacleTexture, Vector2(600, 200) - Vector2(64, 64), Vector2(128, 128));

	//Draw the players and obsticales collision model for debug purposes
	Primitive::DrawBox(Vector4(Vector2(600, 200) - Vector2(64, 64), Vector2(128, 128)), Color(255, 255, 0));
	Primitive::DrawBox(Vector4(pos - Vector2(32, 32), Vector2(64, 64)), Color(255, 255, 0));
}