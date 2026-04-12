#include "ScreenGrid.h"


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
