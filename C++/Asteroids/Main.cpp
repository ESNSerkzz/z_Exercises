#include <iostream>
#include "Raylib.h"
#include "Constants.h"
#include "SpaceObjects.h"

static void SetUp(void);

static void Draw(void);

static void Update(float delta);

SpaceObject asteroid = SpaceObject();

int main(void)
{
	SetUp();
	while (!WindowShouldClose())
	{
		Draw();
		Update(GetFrameTime());
	}

};

static void SetUp(void)
{
	InitWindow(screenWidth, screenHeight, "Window");
	SetTargetFPS(60);

}

static void Draw(void)
{
	BeginDrawing();
	ClearBackground(BLACK);

	DrawFPS(10, 10);
	asteroid.Draw();

	EndDrawing();
}

static void Update(float delta)
{
	asteroid.Update(delta);

}