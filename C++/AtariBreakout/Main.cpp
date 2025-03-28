#include "raylib.h"
#include "raymath.h"
#include "Ball.h"
#include "BrickTiles.h"
#include "Paddle.h"
#include "Constants.h"


static void SetUp();
static void Update(float delta);
static void Draw();

Paddle player = Paddle();
Ball ball = Ball();

Vector2 pos;
//Ball ball = Ball(Raylib.Vector2(0.0f, 40.0f));
//BrickTiles brick = BrickTiles({ 50.0f, 50.0f }, brickSize);


int main()
{
	SetUp();
	while (!WindowShouldClose())
	{
		Update(GetFrameTime());
		Draw();
	}
}

void SetUp()
{
	InitWindow(windowWidth, windowHeight, "WindowScreen");
}

void Update(float delta)
{
	ball.Update(delta);
	player.Update();
	player.Input(delta);
}

void Draw()
{

	BeginDrawing();
	ClearBackground(BLACK);

	ball.ballCollision.isOverlapped(player.boxCollision);

	//Map line.
	DrawLine(0, windowHeight - 100, windowWidth, windowHeight - 100, WHITE);

	player.Draw();
	ball.Draw();

	EndDrawing();
}