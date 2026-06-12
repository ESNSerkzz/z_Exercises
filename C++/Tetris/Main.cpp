#include "Collisions.h"
#include "Constants.h"
#include "ScreenGrid.h"
#include "Tetrominos.h"

static void SetUp(void);
static void Update(float delta);
static void Draw(void);

ScreenGrid grid;
//Tetrominos tetro;
//Tetrominos nextTetro;

std::vector<Tetrominos> tetros;
int lvl;
bool paused;

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

	lvl = 0;
	grid = ScreenGrid(columns, rows, tileSize, "./Map.txt", &lvl);
	//tetro = Tetrominos(I_shape);
	//tetro = Tetrominos(O_shape);
	//tetro = Tetrominos(S_shape);
	//tetro = Tetrominos(Z_shape);
	//tetro = Tetrominos(T_shape);
	//tetro = Tetrominos(L_shape);
	//tetro = Tetrominos(J_shape);
	tetros.push_back(Tetrominos((ShapeType)(std::rand() % 7), &lvl, false));
	tetros.push_back(Tetrominos((ShapeType)(std::rand() % 7), &lvl, true));
	tetros[0].nextTetro = &tetros[1];
	tetros[1].nextTetro = &tetros[0];
	paused = false;

	//tetro = Tetrominos((ShapeType)(std::rand() % 7), &lvl, false);

}

static void Update(float delta)
{
	if (grid.gameOver == true)
	{
		return;
	}
	if (IsKeyPressed(KEY_Q))
	{

		if (paused == false)
		{
			paused = true;
		}
		else paused = false;

	}
	if (paused != false)
	{
		return;
	}
	for (int i = 0; i < tetros.size(); i++)
	{
		
		tetros[i].Update(delta, &grid);
		tetros[i].Input();
	}
	
}

static void Draw(void)
{
	BeginDrawing();
	ClearBackground(BLACK);

	int posX = 13 * tileSize;
	int posY = 8 * tileSize;

	grid.Draw();
	for (int i = 0; i < tetros.size(); i++)
	{
		tetros[i].Draw();
	}

	if (paused == true)
	{
		DrawRectangle(3 * tileSize, 7 * tileSize, 6*tileSize, tileSize, DARKGRAY);
		DrawText(TextFormat("PAUSED"), 5* tileSize - tileSize/2, 7* tileSize + 5, 30, WHITE);
	}
	DrawText(TextFormat("Score: %4i", grid.score), posX, posY, 30, LIGHTGRAY);
	DrawText(TextFormat("Level: %4i", lvl), posX, posY + 50, 30, LIGHTGRAY);
}
