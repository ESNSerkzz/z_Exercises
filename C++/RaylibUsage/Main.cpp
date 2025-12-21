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

MapGrid grid;
Pacman ePacman;

std::vector<Ghosts> ghosts;

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

	//grid = MapGrid(28, 36, 32, "./emptyMap.txt");
	grid = MapGrid(28, 36, 32, "./map.txt");
	ePacman = Pacman(&grid);

		
		ghosts.push_back(Ghosts(CC(Vector2Add(grid.VposToCoords({ 13,14 }), { ghostSize,ghostSize }), ghostSize),
			RED_GHOST,
			&grid,
			"./PacmanAssets/assets.png",
			&ePacman));
		ghosts.push_back(Ghosts(CC(Vector2Add(grid.VposToCoords({ 13,17 }), { ghostSize,ghostSize }), ghostSize),
			PINK_GHOST,
			&grid,
			"./PacmanAssets/assets.png",
			&ePacman));
		ghosts.push_back(Ghosts(CC(Vector2Add(grid.VposToCoords({ 11,17 }), { ghostSize,ghostSize }), ghostSize),
			CYAN_GHOST,
			&grid,
			"./PacmanAssets/assets.png",
			&ePacman));
		ghosts.push_back(Ghosts(CC(Vector2Add(grid.VposToCoords({ 15,17 }), { ghostSize,ghostSize }), ghostSize),
			ORANGE_GHOST,
			&grid,
			"./PacmanAssets/assets.png",
			&ePacman));
	

	
}

void Update(float delta)
{

	ePacman.Update(delta);
	ePacman.Input();
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) 
	{
		std::cout << "Mouse POS: " << grid.GetCoordsV(GetMousePosition()).x << " " << grid.GetCoordsV(GetMousePosition()).y << std::endl;
	}
	
	for (auto & i : ghosts)
	{
		i.Update(delta);
	}
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
	
	for (int i = 0; i < ghosts.size(); i++)
	{
		ghosts[i].Draw();
	}
	
	DrawFPS(10, 10);
	DrawText("HIGH SCORE", {screenWidth/2 - 100},  10, 32, WHITE);
	DrawText(TextFormat("%02i", ePacman.score), { 32 * 5 }, 32, 32, WHITE);
	
}