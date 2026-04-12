#include "Collisions.h"
#include "Constants.h"
#include "ScreenGrid.h"
#include "Tetrominos.h"

static void SetUp(void);
static void Update(float delta);
static void Draw(void);

ScreenGrid grid;
Tetrominos tetro;

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
	tetro = Tetrominos(I_shape);
}

static void Update(float delta)
{
	tetro.Update(delta);
}

static void Draw(void)
{
	BeginDrawing();
	ClearBackground(BLACK);

	grid.Draw();
	tetro.Draw();
}
