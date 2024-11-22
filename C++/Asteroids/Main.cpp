#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "Raylib.h"
#include "Constants.h"
#include "SpaceObjects.h"
#include "Player.h"
#include "MapGrid.h"
#include "Bullets.h"
#include "Asteroids.h"

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
	SetTargetFPS(120);
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

	DrawText(TextFormat("Score; %03i", player.getScore()), 200, 80, 100, RED);

	EndDrawing();
}

static void Update(float delta)
{
	std::vector<Asteroid*> newListOfAsteroids;
	
	for (auto& a : asteroids)
	{
		a->Update(delta);

	}
	//loop through all bullets, and check if bullet overlaps the asteroid -max
	player.Update(delta);
	
	for (auto& b : player.bullets)
	{
		for (auto& a : asteroids)
		{
			
			if (a->isOverlapped(b.locationInfo.pos)) 
			{
				a->toDelete = true;
				b.bulletDeletable = true;
				if (a->locationInfo.size > 32)
				{
					newListOfAsteroids.push_back(new Asteroid(a->locationInfo.pos, { (float)sin((float)rand() / RAND_MAX * 6.82) * 7, (float)-cos((float)rand() / RAND_MAX * 6.82) * 7 }, a->locationInfo.size / 2));  //new Asteroid * newListOfAsteroids;
					newListOfAsteroids.push_back(new Asteroid(a->locationInfo.pos, { (float)sin((float)rand() / RAND_MAX * 6.82) * 7, (float)-cos((float)rand() / RAND_MAX * 6.82) * 7 }, a->locationInfo.size /2 ));  //new Asteroid * newListOfAsteroids;
				}
				if (a->locationInfo.size == 128)
				{
					player.addPoints(50);
				}
				if (a->locationInfo.size == 64)
				{
					player.addPoints(75);
				}
				if (a->locationInfo.size == 32)
				{
					player.addPoints(100);
				}
			}
			//after deleting bullet and asteroid, create 2 new asteroids and add them to the end of NEW asteroid
			
			
			
		}
		
	}
	
	if (asteroids.size() > 0)
	{
		auto i = remove_if(asteroids.begin(), asteroids.end(),
			[&](Asteroid* o)
			{
				return (o->toDelete);
			}
		);

		if (i != asteroids.end())
		{
			asteroids.erase(i);
		}


	}
	
	for (auto a : newListOfAsteroids)
	{
		a->toDelete = false;
		
		asteroids.push_back(a);
	}

}