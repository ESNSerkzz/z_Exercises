#include <iostream>
#include "Raylib.h"
#include "Constants.h"
#include "SpaceObjects.h"
#include "Player.h"
#include "MapGrid.h"

static void SetUp(void);

static void Draw(void);

static void Update(float delta);

static void Input(float delta);

SpaceObject asteroid = SpaceObject();
Player player = Player();

int main(void)
{

	SetUp();
	while (!WindowShouldClose())
	{
		Input(GetFrameTime());
		Draw();
		Update(GetFrameTime());


	}

};

static void SetUp(void)
{
	InitWindow(screenWidth, screenHeight, "Window");
	SetTargetFPS(60);

}

static void Input(float delta)
{
	player.Input(delta);
}

static void Draw(void)
{
	BeginDrawing();
	ClearBackground(BLACK);

	DrawFPS(10, 10);
	asteroid.Draw();
	player.Draw();
	

	EndDrawing();
}

static void Update(float delta)
{
	asteroid.Update(delta);
	player.Update(delta);
}