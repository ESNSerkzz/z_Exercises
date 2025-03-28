#include "raylib.h"
static void SetUp();
static void Update();
static void Draw();

int Main()
{
	SetUp();
	while (!WindowShouldClose())
	{
		Draw();
		Update();
	}
	return 0;
};

void SetUp()
{
	InitWindow(500, 500, "window");
}

void Update()
{

}

void Draw()
{
	BeginDrawing();
	ClearBackground(BLACK);

	DrawRectangleV({ 20,20 }, {20, 20}, BLUE);
	EndDrawing();
}