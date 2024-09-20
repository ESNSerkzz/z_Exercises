#include <iostream>
#include "Raylib.h"
#include "Pacman.h"
#include "AABB.h"
#include "Pallates.h"

static void SetUp(void);

static void Draw(void);

int main(void)
{
	SetUp();
	while (!WindowShouldClose())
	{
		Draw();

	}

};

static void SetUp(void) 
{
	InitWindow(screenWidth, screenHeight, "Window");
	setTargetFPS(60);

}

static void Draw(void)
{
	BeginDrawing();
	ClearBackground(RAYWHITE);

	DrawFPS(10, 10);

	EndDrawing();
}