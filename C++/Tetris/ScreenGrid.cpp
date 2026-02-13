#include "ScreenGrid.h"

Tile::Tile()
{
	collision = AABB({ (float)x,(float)y });
	x = collision.pos.x / tileSize;
	y = collision.pos.y / tileSize;
}

void Tile::DrawTile()
{

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

	for (int x = 0; x < columns, x++)
	{
		for (int y = 0; y < rows; y++)
		{
			listOfTiles_Grid[x][y] = Tile();
			for (int i = 0; i < allText.size(); i++)
			{
				if (allText == ".")
				{
					listOfTiles_Grid[x][y].tType = EMPTY;
				}
				if (allText == "#")
				{
					listOfTiles_Grid[x][y].tType = BRICK;
				}
			}
		}
	}
}

void ScreenGrid::Draw()
{
	
}
