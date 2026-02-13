#include "Blocks.h"
#include "Collisions.h"
#include "Constants.h"
#include "ScreenGrid.h"

static void SetUp(void);
static void Update(float delta);
static void Draw(void);

ScreenGrid grid;

int main(void)
{
	SetUp();
	while (!WindowShouldClose())
	{

		Draw();
		Update(GetFrameTime());
		EndDrawing();
	}
}

static void SetUp(void)
{
	InitWindow(screenWidth,screenHeight, "Window");
	SetTargetFPS(60);

	grid = ScreenGrid(columns, rows, tileSize, "./Map.txt");
}

static void Update(float delta)
{

}

static void Draw(void)
{
	BeginDrawing();
	ClearBackground(BLACK);

	grid.Draw();

}
