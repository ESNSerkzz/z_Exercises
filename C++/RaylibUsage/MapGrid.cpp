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
			listOfTiles[x].push_back({ 0,0,0 });
		}
	}

	for (int x = 0; x < columns; x++)
	{
		for (int y = 0; y < rows; y++) 
		{
			//Palletes palletIndex;
			//palletIndex = Palletes({(float)x *tileSize, (float)y * tileSize}, 2.0f);
			listOfTiles[x][y] = { x * tileSize, y * tileSize, tileSize, new Palletes()};
			listOfTiles[x][y].pallet->box.pos = { (float)x * tileSize + tileSize/2, (float)y * tileSize + tileSize/2 };

		}

	}
}

void MapGrid::Draw()
{
	for (auto column: listOfTiles)
	{
		for (auto tile : column)
		{

			DrawCircle(tile.x + tile.size/2 , tile.y + tile.size/2, 2, GREEN);
			tile.pallet->Draw();
		}
	}
}
