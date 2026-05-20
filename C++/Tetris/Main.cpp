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
	srand(time(NULL));

	grid = ScreenGrid(columns, rows, tileSize, "./Map.txt");
	//tetro = Tetrominos(I_shape);
	//tetro = Tetrominos(O_shape);
	//tetro = Tetrominos(S_shape);
	//tetro = Tetrominos(Z_shape);
	//tetro = Tetrominos(T_shape);
	//tetro = Tetrominos(L_shape);
	//tetro = Tetrominos(J_shape);
	tetro = Tetrominos((ShapeType)(std::rand() % 7));

}

static void Update(float delta)
{
	tetro.Update(delta, &grid);
	tetro.Input();
}

static void Draw(void)
{
	BeginDrawing();
	ClearBackground(BLACK);

	grid.Draw();
	tetro.Draw();
}
