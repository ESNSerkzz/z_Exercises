#include <iostream>
#include "Raylib.h"
#include "Constants.h"
#include "SpaceObjects.h"
#include "Player.h"
#include "MapGrid.h"
#include "Bullets.h"
#include "Asteroids.h"
#include <vector>

static void SetUp(void);

static void Draw(void);

static void Update(float delta);

static void Input(float delta);

std::vector<Asteroid*> asteroids;


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
	for (int i = 0; i < 10; i++)
	{
		asteroids.push_back(new Asteroid());
	}

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
	player.Draw();
	
	for (auto& a : asteroids)
	{
		a->Draw();

	}

	EndDrawing();
}

static void Update(float delta)
{
	
	for (auto& a : asteroids)
	{
		a->Update(delta);

	}
	//loop through all bullets, and check if bullet overlaps the asteroid -max
	player.Update(delta);
	
	
}