#include "Constants.h"
#include "Paddles.h"
#include "Player.h"
#include "ScreenObjects.h"
#include <raymath.h>
#include <raylib.h>
#include <vector>
#include <string>
#include <iostream>


static void SetUp();
static void Update(float delta);
static void Input();
static void Draw();

Player player1 = Player(1);
Player player2 = Player(2);

int main(void)
{

	SetUp();
	while (!WindowShouldClose())
	{
		//Input(GetFrameTime());
		Draw();
		//Update(GetFrameTime());


	}

};

void SetUp()
{
	InitWindow(screenWidth, screenHeight, "Window");
	SetTargetFPS(60);

}

static void Input()
{
	player1.Input();
	player2.Input();

}


static void Update(float delta)
{
	player1.Update();
	player2.Update();
}

static void Draw()
{
	BeginDrawing();

	//Map
	//edges
	DrawLineV({ 0,50 }, { screenWidth, 50 }, WHITE);
	DrawLineV({  0, screenHeight - 50}, {  screenWidth, screenHeight -50}, WHITE);
	//dividing line
	DrawLineV({ screenWidth / 2, 50 }, {screenWidth/2, screenHeight-50}, WHITE);

	//Player drawing
	player1.Draw();
	player2.Draw();

	EndDrawing();
}
