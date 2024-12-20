#include "Ball.h"
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
static void Input(float delta);
static void Draw();

Player player1 = Player(1);
Player player2 = Player(2);

Ball ball = Ball({200, 30});

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

void SetUp()
{
	InitWindow(screenWidth, screenHeight, "Window");
	SetTargetFPS(60);

}

static void Input(float delta)
{
	player1.Input(delta);
	player2.Input(delta);

}


static void Update(float delta)
{
	player1.Update(delta);
	player2.Update(delta);

	
	ball.Update(delta);
}

static void Draw()
{
	BeginDrawing();
	ClearBackground(BLACK);
	//Map
	//edges
	DrawLineV({ 0,50 }, { screenWidth, 50 }, WHITE);
	DrawLineV({  0, screenHeight - 50}, {  screenWidth, screenHeight -50}, WHITE);
	//dividing line
	DrawLineV({ screenWidth / 2, 50 }, {screenWidth/2, screenHeight-50}, WHITE);

	//Player drawing
	player1.Draw();
	player2.Draw();

	ball.Draw();

	EndDrawing();
}
