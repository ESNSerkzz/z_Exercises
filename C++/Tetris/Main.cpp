#include "Collisions.h"
#include "Constants.h"
#include "ScreenGrid.h"
#include "Tetrominos.h"

static void SetUp(void);
static void Update(float delta);
static void Draw(void);
 


// TODO
// add a yellow text to signify that it is the current score that you just got to the scoreboard.

ScreenGrid grid;
//Tetrominos tetro;
//Tetrominos nextTetro;

std::vector<Tetrominos> tetros;
int lvl;
bool paused;
bool scoreHasBeenCalc;

bool setUp_firstTime = true;

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
	//setUp_firstTime = true;
	for (int i = 0; i <= 1; i++)
	{
		if (setUp_firstTime)
		{
			InitWindow(screenWidth, screenHeight, "Window");
			SetTargetFPS(60);
			srand(time(NULL));
			setUp_firstTime = false;

		}
	}
	

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
	scoreHasBeenCalc = false;

	//tetro = Tetrominos((ShapeType)(std::rand() % 7), &lvl, false);

}

static void Update(float delta)
{
	if (grid.gameOver == true)
	{
		
		if (scoreHasBeenCalc == true)
		{
			//grid.HighScoreCalc();
		}

		if (GetMousePosition().x > tileSize * 3 && GetMousePosition().x < tileSize * 3 + tileSize * 6)
		{
			if (GetMousePosition().y > tileSize * 5 && GetMousePosition().y < tileSize * 5 + tileSize * 4)
			{
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					std::cout << "Check Game over" << std::endl;
					tetros.clear();
					SetUp();
					/*grid = ScreenGrid(columns, rows, tileSize, "./Map.txt", &lvl);
					tetros.clear();
					tetros.push_back(Tetrominos((ShapeType)(std::rand() % 7), &lvl, false));
					tetros.push_back(Tetrominos((ShapeType)(std::rand() % 7), &lvl, true));
					tetros[0].nextTetro = &tetros[1];
					tetros[1].nextTetro = &tetros[0];*/

					/*for (int x = 0; x < grid.listOfTiles_Grid.size(); x++)
					{
						for (int y = 0; y < grid.listOfTiles_Grid.size(); y++)
						{
							if (grid.listOfTiles_Grid[x][y].tType == TETROMINO)
							{
								grid.listOfTiles_Grid[x][y].tType == EMPTY;
							}
						}
						
					}*/
				}
			}
		}
		
		return;
	}
	//add highscorecalc here later. V

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

	if (grid.gameOver == true)
	{

		DrawRectangle(tileSize * 3, tileSize * 5, tileSize * 6, tileSize * 4, BLACK);
		int x = GetMousePosition().x;
		int y = GetMousePosition().y;

		//restart game button
		if (x > tileSize * 3 && x < tileSize * 3 + tileSize * 6)
		{
			if (y > tileSize * 5 && y <  tileSize * 5 + tileSize * 4)
			{
				DrawRectangle(tileSize * 3, tileSize * 5, tileSize * 6, tileSize * 4, GRAY);
				
			}
		}
		DrawText(TextFormat("GAME OVER"), tileSize * 3.5, tileSize * 5.5, 35, WHITE);
		DrawText(TextFormat("Restart"), tileSize * 4.5, tileSize * 7.5, 30, WHITE);

		//scoreboard 
		DrawRectangle(tileSize * 2, tileSize * 10, tileSize * 8, tileSize * 5, DARKBLUE);
		DrawText(TextFormat("Score: %4i", grid.scores[0].second), tileSize * 2.5, tileSize * 10.5, 30, SKYBLUE);
		DrawText(TextFormat("Score: %4i", grid.scores[1].second), tileSize * 2.5, tileSize * 11.5, 30, SKYBLUE);
		DrawText(TextFormat("Score: %4i", grid.scores[2].second), tileSize * 2.5, tileSize * 12.5, 30, SKYBLUE);
		DrawText(TextFormat("Score: %4i", grid.scores[3].second), tileSize * 2.5, tileSize * 13.5, 30, SKYBLUE);
		
	}

	DrawText(TextFormat("Score: %4i", grid.score), posX, posY, 30, LIGHTGRAY);
	DrawText(TextFormat("Level: %4i", lvl), posX, posY + 50, 30, LIGHTGRAY);
}
