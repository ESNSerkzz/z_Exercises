#include "Constants.h"
#include "Paddles.h"
#include "ScreenObjects.h"
#include <raymath.h>
#include <raylib.h>
#include <vector>
#include <string>
#include <iostream>


static void SetUp();
static void Update();
static void Input();
static void Draw();

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

static void Input(float delta)
{

}

static void Update(float delta)
{

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

	EndDrawing();
}
