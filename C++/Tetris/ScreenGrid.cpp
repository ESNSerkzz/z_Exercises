#include "ScreenGrid.h"

Tile::Tile()
{
	collision = AABB({ (float)x,(float)y });
	x = collision.pos.x / tileSize;
	y = collision.pos.y / tileSize;
	
}

Tile::Tile(Vector2 _pos)
{
	x = _pos.x;
	y = _pos.y;

	collision = AABB(_pos);
	tType = BRICK;
}

void Tile::DrawTile(Color _lines, Color _fill)
{
	DrawRectangleV({ (float)x * tileSize, (float)y * tileSize }, {tileSize, tileSize}, _fill);
	DrawRectangleLines(x* tileSize, y * tileSize, tileSize, tileSize, _lines);
}

void Tile::Draw()
{


}

TileCoords::TileCoords()
{
}

TileCoords::TileCoords(int _x, int _y)
{
	x = _x * tileSize;
	y = _y * tileSize;
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
			listOfTiles_Grid[i].push_back(Tile());
		}
	}

	for (int x = 0; x < columns; x++)
	{
		for (int y = 0; y < rows; y++)
		{
			for (int i = 0; i < allText.size(); i++)
			{
				listOfTiles_Grid[x][y] = Tile({(float)x,(float)y});

				
				if (allText[x + y * columns] == '.')
				{  
					listOfTiles_Grid[x][y].tType = EMPTY;
					listOfTiles_Grid[x][y].collision = AABB();
				}
				if (allText[x + y * columns] == '#')
				{
					listOfTiles_Grid[x][y].tType = BRICK;
					listOfTiles_Grid[x][y].collision = AABB({ (float)x * tileSize, (float)y * tileSize });
				}
			}
		}
	}
}

void ScreenGrid::Draw()
{

	for (int x = 0; x < columns; x++)
	{
		for (int y = 0; y < rows; y++)
		{
			switch (listOfTiles_Grid[x][y].tType)
			{
			case EMPTY:

				listOfTiles_Grid[x][y].DrawTile(GRAY, LIGHTGRAY);
				break;
			case BRICK:
				listOfTiles_Grid[x][y].DrawTile(DARKGRAY, DARKGRAY);
				break;

			default:
				break;

			}
			
		}
	}
}
