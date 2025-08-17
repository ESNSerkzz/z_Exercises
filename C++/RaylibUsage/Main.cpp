#include <iostream>
#include "Raylib.h"
#include "MapGrid.h"
#include "Pacman.h"
#include "Collisions.h"
#include "Constants.h"
#include "Palletes.h"


static void SetUp(void);
static void Update(void);
//static void Depenetration(void);
static void Draw(void);


MapGrid grid = MapGrid(28, 36, 32, "./map.txt");
Pacman ePacman = Pacman(&grid);


int main(void)
{
	SetUp();
	while (!WindowShouldClose())
	{
		Draw();
		Update();
		EndDrawing();

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

//void Depenetration(void)
//{
//	for(auto i)
//}

static void Draw(void)
{
	BeginDrawing();
	ClearBackground(BLACK);


	grid.Draw();
	ePacman.Draw();
	// loop through tiles and draw;
	

	DrawFPS(10, 10);

}