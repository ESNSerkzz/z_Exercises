#include "Paddle.h"
#include "Constants.h"
#include <raylib.h>


static void SetUp();
static void Update();
static void Draw();

Paddle player = Paddle();

int main()
{
	SetUp();
	while (!WindowShouldClose())
	{
		Update();
		Draw();
	}
}

void SetUp()
{
	InitWindow(windowWidth, windowHeight, "WindowScreen");
}

void Update()
{
	player.Update();
}

void Draw()
{

	BeginDrawing();
	ClearBackground(BLACK);

	//Map line.
	DrawLine(0, windowHeight - 100, windowWidth, windowHeight - 100, WHITE);
	
	player.Draw();


	EndDrawing();
}