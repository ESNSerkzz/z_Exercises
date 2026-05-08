#include "ScreenGrid.h"

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
	switch (tType)
	{
	case EMPTY:

		DrawTile(GRAY, LIGHTGRAY);
		break;
	case BRICK:
		DrawTile(DARKGRAY, DARKGRAY);
		break;

	case TETROMINO:
		DrawTile(colourLines, colourFill);

	default:
		break;

	}

}
//----------------------------------------------------------------//

ScreenGrid::ScreenGrid()
{

}

ScreenGrid::ScreenGrid(int _columns, int _rows, int _tileSize, std::string _mapFilePath)
{

	std::fstream file;
	file.open(_mapFilePath);

	std::string currentLine;
	std::string allText;

	while (getline(file, currentLine))
	{
		std::cout << currentLine << std::endl;
		allText.append(currentLine);
	}
	for (int i = 0; i < columns; i++)
	{
		listOfTiles_Grid.push_back(std::vector<Tile>());
		for (int j = 0; j < rows; j++)
		{
			if (allText[i + j * columns] == '.')
			{
				listOfTiles_Grid[i].push_back(Tile(EMPTY, i, j));
			}
			else
			{
				listOfTiles_Grid[i].push_back(Tile(BRICK, i, j));
			}

		}
	}



}

void ScreenGrid::HandleTetroLanding(std::vector<Tile> tetro)
{
	for (int i = 0; i < tetro.size(); i++)
	{
		listOfTiles_Grid[tetro[i].x][tetro[i].y].tType = TETROMINO;
		listOfTiles_Grid[tetro[i].x][tetro[i].y].colourFill = tetro[i].colourFill;
		listOfTiles_Grid[tetro[i].x][tetro[i].y].colourLines = tetro[i].colourLines;
	}
	if (FilledRowCheck().size() > 0)
	{
		
	}
	std::cout << FilledRowCheck().size() << std::endl;
}

std::vector<int> ScreenGrid::FilledRowCheck()
{
	std::vector<int> rowToClear;
	for (int y = 2; y <= 21; y++)
	{
		bool clear = true;
		for (int x = 1; x < 10; x++)
		{
			if (listOfTiles_Grid[x][y].tType != TETROMINO)
			{
				clear = false;
				
			}

		}
		if (clear == true)
		{
			rowToClear.push_back(y);

		}
	}
	

	return rowToClear;
}

void ScreenGrid::Draw()
{

	for (int x = 0; x < columns; x++)
	{
		for (int y = 0; y < rows; y++)
		{
			listOfTiles_Grid[x][y].Draw();
			
		}
	}
}
