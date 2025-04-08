#include "raylib.h"
#include "raymath.h"
#include "Ball.h"
#include "BrickTiles.h"
#include "Paddle.h"
#include "Constants.h"
#include "iostream"
#include <string.h>
#include <vector>

std::vector<BrickTiles> LoadBricks(Vector2 topLeftCorner, Vector2 bottomRightCorner, const char* string);
static void SetUp();
static void Update(float delta);
static void Draw();

Paddle player = Paddle();
Ball ball = Ball();


//Ball ball = Ball(Raylib.Vector2(0.0f, 40.0f));
//BrickTiles brick = BrickTiles({ 50, 50 }, {70, 20});
std::vector <BrickTiles> Bricks;
const char* brickPattern =
"0000000002"
"0111111102"
"0110001102"
"0111011102";


int main()
{
	SetUp();
	while (!WindowShouldClose())
	{
		Update(GetFrameTime());
		Draw();
	}
}

std::vector<BrickTiles> LoadBricks(Vector2 _topLeftCorner, Vector2 _bottomRightCorner, const char* _string)
{ 
	std::vector <BrickTiles> returnBricks;
	returnBricks.push_back(BrickTiles());
	int columns;
	Vector2 BrickSize;
	
	for (int i = 0; i < (unsigned)strlen(_string); i++)
	{
		if (_string[i] == '2')
		{
			std::cout << std::endl << i << std::endl;
			BrickSize.x = (_bottomRightCorner.x - _topLeftCorner.x)/ i;
			BrickSize.y = (_bottomRightCorner.y - _topLeftCorner.y) / (strlen(_string) / (i + 1));
			columns = (strlen(_string)) / (i + 1);
			break;
		}


	}

	for (int i = 0; i < (unsigned)strlen(_string); i++)
	{
		if (_string[i] != '2')
		{

			returnBricks.push_back(BrickTiles(
				{
					_topLeftCorner.x + i * BrickSize.x,
					_topLeftCorner.y + ()


				},

				Vector2Subtract(BrickSize, { 2, 2 })

			
			));
		}
	}

	return returnBricks;
}

void SetUp()
{
	InitWindow(windowWidth, windowHeight, "WindowScreen");
	Bricks = LoadBricks({ 50, 50 }, {windowWidth - 50, 500}, brickPattern);
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
	bricks.Draw();

	for (auto i : Bricks) i.Draw();


	EndDrawing();
}