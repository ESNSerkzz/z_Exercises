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
MapGrid grid = MapGrid(28, 36, 32, "./map.txt");
MapGrid surroundingAOE = MapGrid(3, 3, 30);


int main(void)
{
	SetUp();
	while (!WindowShouldClose())
	{
		Update();
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
	// AABB that surrounds the boxes near pacman, then draw that box
	// start checking tiles with said box

	ePacman.Update();
	ePacman.Input();
}

static void Draw(void)
{
	BeginDrawing();
	ClearBackground(BLACK);

	ePacman.Draw();
	grid.Draw();
	
	int pacmanPosX = ePacman.box.pos.x / 32;
	int pacmanPosY = ePacman.box.pos.y / 32;

	

	grid.DrawBox(pacmanPosX, pacmanPosY);
	grid.DrawBox(pacmanPosX - 1, pacmanPosY);
	grid.DrawBox(pacmanPosX + 1, pacmanPosY);
	grid.DrawBox(pacmanPosX, pacmanPosY- 1);
	grid.DrawBox(pacmanPosX, pacmanPosY + 1);
	grid.DrawBox(pacmanPosX+1, pacmanPosY- 1);
	grid.DrawBox(pacmanPosX-1, pacmanPosY - 1);
	grid.DrawBox(pacmanPosX+1, pacmanPosY + 1);
	grid.DrawBox(pacmanPosX - 1, pacmanPosY + 1);

	DrawFPS(10, 10);

	EndDrawing();
}