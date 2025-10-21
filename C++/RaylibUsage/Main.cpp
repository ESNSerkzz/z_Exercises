#include <iostream>
#include "Raylib.h"
#include "MapGrid.h"
#include "Pacman.h"
#include "Ghosts.h"
#include "Collisions.h"
#include "Constants.h"
#include "Palletes.h"


static void SetUp(void);
static void Update(float delta);
static void Draw(void);


MapGrid grid = MapGrid(28, 36, 32, "./map.txt");
Pacman ePacman;
Ghosts eGhost;


int main(void)
{
	SetUp();
	while (!WindowShouldClose())
	{

		Draw();
		Update(GetFrameTime());
		EndDrawing();

	}

};

static void SetUp(void) 
{
	InitWindow(screenWidth, screenHeight, "Window");
	SetTargetFPS(60);
	ePacman = Pacman(&grid);
	eGhost = Ghosts(AABB({ screenWidth / 2, screenHeight / 2 }, {ghostSize, ghostSize}), RED_GHOST, &grid, "./PacmanAssets/assets.png");
	eGhost.pacman = &ePacman;
}

void Update(float delta)
{

	ePacman.Update(delta);
	ePacman.Input();

	eGhost.Update(delta);
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
	eGhost.Draw();

	
	DrawFPS(10, 10);
	DrawText("HIGH SCORE", {screenWidth/2 - 100},  10, 32, WHITE);
	DrawText(TextFormat("%02i", ePacman.score), { 32 * 5 }, 32, 32, WHITE);
	
}