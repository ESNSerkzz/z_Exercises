#include <iostream>
#include "Raylib.h"
#include "MapGrid.h"
#include "Pacman.h"
#include "Collisions.h"
#include "Constants.h"
#include "Palletes.h"


static void SetUp(void);
static void Update(void);
static void Draw(void);


Pacman ePacman = Pacman();

MapGrid grid = MapGrid(28, 36, 32);

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


	SetTargetFPS(60);

}

void Update(void)
{
	//TODO
	// 1)get pacman moving/ movement
	// 2.) map parts assignments.

	ePacman.Update();
}

static void Draw(void)
{
	BeginDrawing();
	ClearBackground(BLACK);

	ePacman.Draw();
	grid.Draw();
	DrawFPS(10, 10);

	EndDrawing();
}