#include "MapGrid.h"


MapGrid::MapGrid()
{

}

MapGrid::MapGrid(int columns, int rows, int tileSize)
{
	
	for (int x = 0; x < columns; x++) 
	{
		listOfTiles.push_back(std::vector<Tile>());
		for (int y = 0; y < rows; y++)
		{
			listOfTiles[x].push_back({AABB(), 0,0,0 });
		}
	}

	for (int x = 0; x < columns; x++)
	{
		for (int y = 0; y < rows; y++) 
		{
			//Palletes palletIndex;
			//palletIndex = Palletes({(float)x *tileSize, (float)y * tileSize}, 2.0f);
			listOfTiles[x][y] = {AABB({(float)x * tileSize, (float)y * tileSize}, {tileSize / 2.0f, tileSize / 2.0f}), x * tileSize, y * tileSize, tileSize, new Palletes()};
			listOfTiles[x][y].pallet->box.pos = { (float)x * tileSize + tileSize/2, (float)y * tileSize + tileSize/2 };

		}

	}
}

MapGrid::MapGrid(int columns, int rows, int tileSize, std::string filePath)
{
	std::fstream file;
	file.open(filePath);

	std::string currentLine;
	std::string allText;

	while (getline(file, currentLine))
	{
		std::cout << currentLine << std::endl;
		allText.append(currentLine);
	}
	for (int x = 0; x < columns; x++)
	{
		listOfTiles.push_back(std::vector<Tile>());
		for (int y = 0; y < rows; y++)
		{
			listOfTiles[x].push_back({ AABB(), 0,0,0 });

		}
	}

	for (int x = 0; x < columns; x++)
	{
		for (int y = 0; y < rows; y++)
		{
			//Palletes palletIndex;
			//palletIndex = Palletes({(float)x *tileSize, (float)y * tileSize}, 2.0f);
			listOfTiles[x][y] = { AABB({(float)x * tileSize, (float)y * tileSize}, {tileSize/2.0f, tileSize/2.0f}), x * tileSize, y * tileSize, tileSize, nullptr };
	
			if (allText[x + y * columns ] == '1')
			{
				listOfTiles[x][y].type = BRICK;
			}

			if (allText[x + y * columns] == '2')
			{
				listOfTiles[x][y].type = PALLETE;
				listOfTiles[x][y].pallet = new Palletes({ (float)x * tileSize + tileSize / 2, (float)y * tileSize + tileSize / 2 }, palletSize);
			}

			if (allText[x + y * columns] == '3')
			{
				listOfTiles[x][y].type = POWERPALLETE;
				listOfTiles[x][y].pallet = new Palletes({ (float)x * tileSize + tileSize / 2, (float)y * tileSize + tileSize / 2 }, palletSize, PowerPallete);
			}
			if (allText[x + y * columns] == '4')
			{
				listOfTiles[x][y].type = FRUIT;
				listOfTiles[x][y].pallet = new Palletes({ (float)x * tileSize + tileSize / 2, (float)y * tileSize + tileSize / 2 }, powerPalletSize, Fruit);
			}
		}

	}
}

void MapGrid::DrawBox(int x, int y)
{
	Tile tile = listOfTiles[x][y];
	
	DrawRectangleLines(tile.x, tile.y, tile.size, tile.size, WHITE);
}

void MapGrid::Draw()
{
	for (auto column: listOfTiles)
	{
		for (auto tile : column)
		{
			switch (tile.type)
			{
			case(BRICK):
				DrawRectangleV({ (float)tile.x,(float)tile.y }, { (float)tile.size, (float)tile.size }, BLUE);
				break;

			case(POWERPALLETE):
				//pallet->box.pos = { (float)x * tileSize + tileSize / 2, (float)y * tileSize + tileSize / 2 };
				tile.pallet->Draw();
				break;
			case(PALLETE):
				tile.pallet->Draw();
			default:
				break;
			}

			//tile.TileCollision.Draw();

			
		}
	}
}
