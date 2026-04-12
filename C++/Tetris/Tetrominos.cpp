#include "Tetrominos.h"
Tile::Tile()
{
}

Tile::Tile(Vector2 _pos)
{
	tType = BRICK;
}

Tile::Tile(TileType _type, int _x, int _y)
{
	tType = _type;
	x = _x;
	y = _y;

}

void Tile::DrawTile(Color _lines, Color _fill)
{
	DrawRectangleV({ (float)x * tileSize, (float)y * tileSize }, { tileSize, tileSize }, _fill);
	DrawRectangleLines(x * tileSize, y * tileSize, tileSize, tileSize, _lines);
}

void Tile::Draw()
{
	

}

//------------------------------------|||||
Tetrominos::Tetrominos()
{
	
}

Tetrominos::Tetrominos(ShapeType _bType)
{
	shape = _bType;
	descentRateTimer = 5;

		switch (_bType)
		{
		case I_shape:
			tetrominos.push_back(Tile(TETROMINO, 0, -1));
			tetrominos.push_back(Tile(TETROMINO, 0, 0));
			tetrominos.push_back(Tile(TETROMINO, 0, 1));
			tetrominos.push_back(Tile(TETROMINO, 0, 2));
			break;
		case O_shape:

			break;

		case T_shape:

			break;

		case S_shape:

			break;

		case Z_shape:

			break;

		case L_shape:

			break;

		case J_shape:

			break;
		}
		for (int i = 0; i < tetrominos.size(); i++)
		{
			tetrominos[i].x += Xspawn;
			tetrominos[i].y += Yspawn;
		}
	
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
	for (int i = 0; i < tetrominos.size(); i++)
	{
		tetrominos[i].y = tetrominos[i].y + 1;
	}
}

void Tetrominos::Input()
{

}

void Tetrominos::Update(float delta)
{
	descentRateTimer = descentRateTimer - delta;
	if (descentRateTimer < 0)
	{
		descentRateTimer = 0.3f;
		Decention();
	}
}

void Tetrominos::Draw()
{
	for (int i = 0; i < tetrominos.size(); i++)
	{
		switch (shape)
		{
			
		case I_shape:
			tetrominos[i].DrawTile(BLUE, SKYBLUE);
			break;

		case O_shape:
			tetrominos[i].DrawTile(GOLD, YELLOW);
			break;

		case T_shape:
			tetrominos[i].DrawTile(VIOLET, PURPLE);
			break;

		case S_shape:
			tetrominos[i].DrawTile(LIME, GREEN);
			break;

		case Z_shape:
			tetrominos[i].DrawTile(MAROON, RED);
			break;

		case L_shape:
			tetrominos[i].DrawTile({ 255,120,0,255 }, ORANGE);
			break;

		case J_shape:
			tetrominos[i].DrawTile(DARKBLUE, BLUE);
			break;
		}
	}
	

}
