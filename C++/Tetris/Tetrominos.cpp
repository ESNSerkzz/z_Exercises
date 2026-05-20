#include "Tetrominos.h"


//------------------------------------|||||
Tetrominos::Tetrominos()
{
	
}

Tetrominos::Tetrominos(ShapeType _bType)
{
	descentRateTimer = 5;
	CreateTetro(_bType);
	
}

std::vector<Tile> Tetrominos::BlockCanvas(Tetrominos tetromino)
{

	int rows = 4;
	int columns = 4;
	std::vector<Tile>blockCanvas;
	/*blockCanvas.push_back(new Tile());*/
	for (int i = 0; i < blockCanvas.size(); i ++)
	{
		
		blockCanvas.push_back(Tile(EMPTY, columns, rows));
		
	}
	
		

	return blockCanvas;
}

void Tetrominos::Decention()
{
	if (paused != true)
	{
		y++;
		for (int i = 0; i < tetroTiles.size(); i++)
		{
			tetroTiles[i].y = tetroTiles[i].y + 1;
		}
	}
	
	
}

void Tetrominos::ResetTetro()
{
	tetroTiles.clear();
	CreateTetro((ShapeType)(std::rand() % 7));
}

void Tetrominos::CreateTetro(ShapeType _type)
{
	shape = _type;
	x = Xspawn;
	y = Yspawn;

	switch (_type)
	{
	case I_shape:
		tetroTiles.push_back(Tile(TETROMINO, 0, 1));
		tetroTiles.push_back(Tile(TETROMINO, 0, 0));
		tetroTiles.push_back(Tile(TETROMINO, 0, -1));
		tetroTiles.push_back(Tile(TETROMINO, 0, -2));
		break;
	case O_shape:
		tetroTiles.push_back(Tile(TETROMINO, 0, 0));
		tetroTiles.push_back(Tile(TETROMINO, -1, 0));
		tetroTiles.push_back(Tile(TETROMINO, -1, 1));
		tetroTiles.push_back(Tile(TETROMINO, 0, 1));
		break;

	case T_shape:
		tetroTiles.push_back(Tile(TETROMINO, 0, 0));
		tetroTiles.push_back(Tile(TETROMINO, -1, 0));
		tetroTiles.push_back(Tile(TETROMINO, 1, 0));
		tetroTiles.push_back(Tile(TETROMINO, 0, 1));
		break;

	case S_shape:
		tetroTiles.push_back(Tile(TETROMINO, 0, 0));
		tetroTiles.push_back(Tile(TETROMINO, -1, 0));
		tetroTiles.push_back(Tile(TETROMINO, -1, 1));
		tetroTiles.push_back(Tile(TETROMINO, -2, 1));
		break;

	case Z_shape:
		tetroTiles.push_back(Tile(TETROMINO, -1, 0));
		tetroTiles.push_back(Tile(TETROMINO, -2, 0));
		tetroTiles.push_back(Tile(TETROMINO, -1, 1));
		tetroTiles.push_back(Tile(TETROMINO, 0, 1));
		break;

	case L_shape:
		tetroTiles.push_back(Tile(TETROMINO, -1, 1));
		tetroTiles.push_back(Tile(TETROMINO, -1, 0));
		tetroTiles.push_back(Tile(TETROMINO, -1, -1));
		tetroTiles.push_back(Tile(TETROMINO, 0, 1));
		break;

	case J_shape:
		tetroTiles.push_back(Tile(TETROMINO, 0, 1));
		tetroTiles.push_back(Tile(TETROMINO, 0, 0));
		tetroTiles.push_back(Tile(TETROMINO, 0, -1));
		tetroTiles.push_back(Tile(TETROMINO, -1, 1));
		break;
	}
	for (int i = 0; i < tetroTiles.size(); i++)
	{
		tetroTiles[i].x += Xspawn;
		tetroTiles[i].y += Yspawn;
		switch (_type)
		{
		case I_shape:
			tetroTiles[i].colourFill = SKYBLUE;
			tetroTiles[i].colourLines = BLUE;
			break;
		case O_shape:
			tetroTiles[i].colourFill = YELLOW;
			tetroTiles[i].colourLines = GOLD;
			break;

		case T_shape:
			tetroTiles[i].colourFill = PURPLE;
			tetroTiles[i].colourLines = VIOLET;
			break;

		case S_shape:
			tetroTiles[i].colourFill = GREEN;
			tetroTiles[i].colourLines = LIME;
			break;

		case Z_shape:
			tetroTiles[i].colourFill = RED;
			tetroTiles[i].colourLines = MAROON;
			break;

		case L_shape:
			tetroTiles[i].colourFill = ORANGE;
			tetroTiles[i].colourLines = { 255,120,0,255 };
			break;

		case J_shape:
			tetroTiles[i].colourFill = BLUE;
			tetroTiles[i].colourLines = DARKBLUE;
			break;
		}
	}

}

void Tetrominos::RotateTetro(double _rotation)
{
	

	std::vector<Tile> tempList(tetroTiles);

	for (int i = 0; i < tempList.size(); i++)
	{

		
		tempList[i].x = tempList[i].x - x;
		tempList[i].y = tempList[i].y - y;

		double tempX;
		double tempY;

		tempX = tempList[i].x;
		tempY = tempList[i].y;


		tempX = (double)tempList[i].x * cos(_rotation) - (double)tempList[i].y * sin(_rotation);
		tempY = (double)tempList[i].x * sin(_rotation) + (double)tempList[i].y * cos(_rotation);

		tempList[i].x = tempX * 1.1f;
		tempList[i].y = tempY * 1.1f;

		tempList[i].x = tempList[i].x + x;
		tempList[i].y = tempList[i].y + y;
	}
	bool canRotate = true;
	for (int i = 0; i < tempList.size() ; i++)
	{
		if (screenMap->listOfTiles_Grid[tempList[i].x][tempList[i].y].tType != EMPTY)
		{
			canRotate = false;

		}
	}
	if (canRotate == true)
	{
		tetroTiles = tempList;
	}
	
}

void Tetrominos::Input()
{
	
	if (IsKeyPressed(KEY_A))
	{
		//checking if we can move to the left.

		bool canMoveDir = true;

		for (int i = 0; i < tetroTiles.size(); i++)
		{
			if (screenMap->listOfTiles_Grid[tetroTiles[i].x - 1][tetroTiles[i].y].tType == BRICK)
			{
				
				canMoveDir = false;
			}
			if (screenMap->listOfTiles_Grid[tetroTiles[i].x - 1][tetroTiles[i].y].tType == TETROMINO)
			{
				canMoveDir = false;
			}
		}
	
		//then actually moving left if nothing obstruct

		if (canMoveDir == true)
		{
			for (int i = 0; i < tetroTiles.size(); i++)
			{
				tetroTiles[i].x = tetroTiles[i].x -= 1;
			}
			x--;
		}


	}
	if (IsKeyPressed(KEY_D))
	{
		//checking if we can move to the right.

		bool canMoveDir = true;

		for (int i = 0; i < tetroTiles.size(); i++)
		{
			if (screenMap->listOfTiles_Grid[tetroTiles[i].x + 1][tetroTiles[i].y].tType == BRICK)
			{
				canMoveDir = false;
			}
			if (screenMap->listOfTiles_Grid[tetroTiles[i].x + 1][tetroTiles[i].y].tType == TETROMINO)
			{
				canMoveDir = false;
			}

		}

		//then actually moving left if nothing obstruct

		if (canMoveDir == true)
		{
			for (int i = 0; i < tetroTiles.size(); i++)
			{
				tetroTiles[i].x = tetroTiles[i].x += 1;
			}
			x++;
		}
	}

	if (IsKeyPressed(KEY_R))
	{
		if (shape != O_shape)
		{
			RotateTetro(PI/2);
		}
		
	}

	
	if (IsKeyPressed(KEY_Q))  
	{
		
		if (paused == false)
		{
			paused = true;
		}
		else paused = false;
		
	}
	
	
}

void Tetrominos::Update(float delta, ScreenGrid* map)
{
	screenMap = map;
	descentRateTimer = descentRateTimer - delta;
	if (descentRateTimer < 0)
	{
		descentRateTimer = 0.3f;
		if (IsKeyDown(KEY_S))
		{
			descentRateTimer = descentRateTimer / 4;
		}
		bool shouldStop = false;

		for (int i = 0; i < tetroTiles.size(); i++)
		{
			if (map->listOfTiles_Grid[tetroTiles[i].x][tetroTiles[i].y + 1].tType != EMPTY)
			{
				std::cout << "example" << std::endl;
				shouldStop = true;
			}
		
		
		}
		if (shouldStop)
		{
			map->HandleTetroLanding(tetroTiles);
			ResetTetro();
			//tetrominos
		}
		else
		{
			Decention();

		}
	}

	
}

void Tetrominos::Draw()
{
	for (int i = 0; i < tetroTiles.size(); i++)
	{
		tetroTiles[i].Draw();
	}
	

}
