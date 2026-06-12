#include "Tetrominos.h"

Tetrominos::Tetrominos()
{
	
}

Tetrominos::Tetrominos(ShapeType _bType, int* _lvl, bool inCanvas)
{
	lvl =_lvl;
	CreateTetro(_bType, inCanvas);
	if (inCanvas)
	{
		paused = true;
	}
	else
	{
		descentRateTimer = 5;
	}
	//Tetrominos nextTetro = Tetrominos((ShapeType(Z_shape)), _lvl, true);
}

void Tetrominos::CreateTetro(ShapeType _type, bool inCanvas)
{
	shape = _type;

	x = Xspawn;
	y = Yspawn;

	if (inCanvas)
	{
		x = c_Xspawn;
		y = c_Yspawn;
	}

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
		tetroTiles[i].x += x;
		tetroTiles[i].y += y;
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

void Tetrominos::SetToCanvas()
{
	CreateTetro((ShapeType)(std::rand() % 7), true);
	paused = true;
	x = c_Xspawn;
	y = c_Yspawn;

	//CreateTetro((ShapeType)(std::rand() % 7), true);
	
}

void Tetrominos::SetToGame()
{
	
	//CreateTetro(shape, false);
	x = Xspawn;
	y = Yspawn;
	paused = false;
	for (int i = 0; i < tetroTiles.size(); i++)
	{
		tetroTiles[i].x += Xspawn - c_Xspawn;
		tetroTiles[i].y += Yspawn - c_Yspawn;
	}


	//CreateTetro(shape, false);
}



void Tetrominos::Input()
{
	if (paused == true)
	{
		return;
	}
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

	
	
}

void Tetrominos::Update(float delta, ScreenGrid* map)
{
	screenMap = map;
	if (paused == true)
	{
		return;
	}
	descentRateTimer = descentRateTimer - delta;
	if (descentRateTimer < 0)
	{

		switch (*lvl)
		{
		case 0:
			descentRateTimer = (float)0.01674 * 53;

			break;
		case 1:
			descentRateTimer = (float)0.01674 * 49;
			break;
		case 2:
			descentRateTimer = (float)0.01674 * 45;
			break;
		case 3:
			descentRateTimer = (float)0.01674 * 41;
			break;
		case 4:
			descentRateTimer = (float)0.01674 * 37;
			break;
		case 5:
			descentRateTimer = (float)0.01674 * 33;
			break;
		case 6:
			descentRateTimer = (float)0.01674 * 28;
			break;
		case 7:
			descentRateTimer = (float)0.01674 * 22;
			break;
		case 8:
			descentRateTimer = (float)0.01674 * 17;
			break;
		case 9:
			descentRateTimer = (float)0.01674 * 11;
			break;
		case 10:
			descentRateTimer = (float)0.01674 * 10;
			break;
		case 11:
			descentRateTimer = (float)0.01674 * 9;
			break;
		case 12:
			descentRateTimer = (float)0.01674 * 8;
			break;
		case 13:
			descentRateTimer = (float)0.01674 * 7;
			break;
		case 14:
			descentRateTimer = (float)0.01674 * 6;
			break;
		case 15:
			descentRateTimer = (float)0.01674 * 6;
			break;
		case 16:
			descentRateTimer = (float)0.01674 * 5;
			break;
		case 17:
			descentRateTimer = (float)0.01674 * 5;
			break;
		case 18:
			descentRateTimer = (float)0.01674 * 4;
			break;
		case 19:
			descentRateTimer = (float)0.01674 * 4;
			break;
		case 20:
			descentRateTimer = (float)0.01674 * 3;
			break;


		}
		if (IsKeyDown(KEY_S))
		{

			descentRateTimer = descentRateTimer / 5;
			if (descentRateTimer < 1)
			{
				map->score = map->score + 1;

			}
		}
		bool landed = false;

		for (int i = 0; i < tetroTiles.size(); i++)
		{
			if (map->listOfTiles_Grid[tetroTiles[i].x][tetroTiles[i].y + 1].tType != EMPTY)
			{
				landed = true;
			}
			//if (map->listOfTiles_Grid[tetroTiles[i].x][tetroTiles[i].y].tType == tetroTiles[i].tType)
			//{
			//	paused = true;
			//	landed = false;
			//	std::cout << "overlapped" << std::endl;
			//	//map->listOfTiles_Grid.clear();
			//}
			//else paused = false;
		
		}
		if (landed)
		{
			map->HandleTetroLanding(tetroTiles);
			ResetTetro();
			SetToCanvas();
			nextTetro->SetToGame();
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
