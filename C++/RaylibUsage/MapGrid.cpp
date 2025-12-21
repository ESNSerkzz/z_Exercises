#include "MapGrid.h"


MapGrid::MapGrid()
{

}

MapGrid::MapGrid(int _columns, int _rows, int tileSize)
{
	columns = _columns;
	rows = _rows;
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
			listOfTiles[x][y].pallet->collision.pos = { (float)x * tileSize + tileSize/2, (float)y * tileSize + tileSize/2 };

		}
	}
}

MapGrid::MapGrid(int _columns, int _rows, int tileSize, std::string filePath)
{
	columns = _columns;
	rows = _rows;

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
			listOfTiles[x][y] = { AABB(), x * tileSize, y * tileSize, tileSize, nullptr };
	
			if (allText[x + y * columns ] == '1')
			{
				listOfTiles[x][y].type = BRICK;
				listOfTiles[x][y].TileCollision = AABB({ (float)x * tileSize, (float)y * tileSize }, { tileSize / 2.0f, tileSize / 2.0f });
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
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			if (listOfTiles[i][j].type != BRICK)
			{
				std::vector<TileCoords> bricklessSpaces = GetBricklessSpaceAroundOrigin({ i,j });
				for (int a = 0; a < bricklessSpaces.size(); a++)
				{
					listOfTiles[i][j].allNeighbours.push_back(&listOfTiles[bricklessSpaces[a].x][bricklessSpaces[a].y]);
				}
			}
		}
	}
}

std::vector<Tile> MapGrid::BoxesAroundPoint(Vector2 pos)
{
	int posX = pos.x / 32;
	int posY = pos.y / 32;

	std::vector<Tile> BAP; 
	if (posX < columns && posX >= 0 && posY < rows && posY >= 0)
	{
		if (posX != 0)
		{
			if (posY != 0)
			{				
				BAP.push_back(listOfTiles[posX - 1] [posY - 1]); //top left
			}
			if (posY != rows - 1)
			{
				BAP.push_back(listOfTiles[posX - 1] [posY + 1]); //bottom left
			}

			BAP.push_back(listOfTiles[posX - 1] [posY]); //middle left
		}
		if (posX != columns - 1)
		{
			if (posY != 0)
			{
				BAP.push_back(listOfTiles[posX + 1] [posY - 1]); //top right
				
			}
			if (posY != rows - 1)
			{
				BAP.push_back(listOfTiles[posX + 1] [posY + 1]); //bottom right
				
			}
			BAP.push_back(listOfTiles[posX + 1] [posY]); //middle right
		}
		//Centre piece (middle, where Pac-man is).
		
		BAP.push_back(listOfTiles[posX][posY]);
		if (posY != 0)
		{	
			BAP.push_back(listOfTiles[posX][posY + 1]); //bottom middle

		}
		if (posY != rows - 1) 
		{
			BAP.push_back(listOfTiles[posX][posY - 1]); //top middle
		}
		
	}
	return BAP;
}

std::vector<TileCoords> MapGrid::GetBricklessSpaceAroundOrigin(TileCoords _origin)
{
	std::vector<TileCoords> list;
	
		if (_origin.x != 0)
		{
			if (listOfTiles[_origin.x - 1][_origin.y].type != BRICK)
			{
				//left
				list.push_back({ _origin.x - 1, _origin.y });

			}
		}

		if (_origin.x != columns - 1)
		{
			if (listOfTiles[_origin.x + 1][_origin.y].type != BRICK)
			{
				//right
				list.push_back({ _origin.x + 1,_origin.y });

			}
		}
		
		if (_origin.y != 0)
		{
			if (listOfTiles[_origin.x][_origin.y - 1].type != BRICK)
			{
				//top
				list.push_back({ _origin.x, _origin.y - 1 });

			}
		}

		if (_origin.y != rows - 1)
		{
			if (listOfTiles[_origin.x][_origin.y + 1].type != BRICK)
			{
				//bottom
				list.push_back({ _origin.x,_origin.y + 1 });

			}
		}

	return list;
}

std::vector<TileCoords> MapGrid::dijkstrasPathing(TileCoords startPos, TileCoords endPos)
{
	std::vector<Tile*> openList;
	std::vector<Tile*> closedList;
	Tile* currentTile = &listOfTiles[startPos.x][startPos.y];
	for (int i = 0; i < listOfTiles.size(); i++)
	{
		for (int j = 0; j < listOfTiles[i].size(); j++)
		{
			openList.push_back(&listOfTiles[i][j]);
		}
	}

	for (int i = 0; i < openList.size(); i++)
	{
		//before being explored. Setting cost to highest possible values in of every element of openlist to begin with
		openList[i]->cost = std::numeric_limits<float>::max();
		openList[i]->explored = false;

	}

	currentTile->cost = 0;
	currentTile->explored = true;
	bool pathImcomplete = true;
	

	while (pathImcomplete)
	{
		for (int i = 0; i < currentTile->allNeighbours.size(); i++)
		{
			//if the cost of the neighbouring tile is greater than the distance of the currentTile
			// and the next neighboring tile in line (refering to allNeighbour)
			if (currentTile->allNeighbours[i]->cost > Vector2Distance(currentTile->TileCollision.pos, currentTile->allNeighbours[i]->TileCollision.pos) + currentTile->cost)
			{
				float newCost;
				newCost = Vector2Distance(
					{(float)currentTile->x, (float)currentTile->y},
					{ (float)currentTile->allNeighbours[i]->x, (float)currentTile->allNeighbours[i]->y});
				currentTile->allNeighbours[i]->cost = newCost + currentTile->cost;

				//currentTile->prevTile = currentTile->allNeighbours[i];
				currentTile->allNeighbours[i]->prevTile = currentTile;
			}
		}

		currentTile->explored = true;
		Tile* cheapestTile = nullptr;
		int toDelete = -1;
		for (int i = 0; i < openList.size(); i++)
		{
			if (currentTile == openList[i])
			{
				toDelete = i;
			}
		}
		openList.erase(openList.begin() + toDelete);
		//finding the cheapest unexplored tile
		for (int i = 0; i < openList.size(); i++)
		{
			if (cheapestTile == nullptr)
			{
				cheapestTile = openList[i];
				
			}
			if (openList[i]->cost < cheapestTile->cost)
			{
				cheapestTile = openList[i];
			}
		}
	
		if (cheapestTile->y /32  == endPos.y && cheapestTile->x /32 == endPos.x)
		{
			//cheapestTile->prevTile = currentTile;
			pathImcomplete = false;
		}
		currentTile = cheapestTile;
	}

	std::vector <TileCoords> completePath;

	while (currentTile != &listOfTiles[startPos.x][startPos.y])
	{

		
		completePath.push_back({ currentTile->x / 32, currentTile->y /32 });
		if (currentTile->prevTile == nullptr)
		{
			std::cout << "Error" << std::endl;
			break;
		}
		currentTile = currentTile->prevTile;
	}
	completePath.push_back(startPos);
	std::reverse(completePath.begin(), completePath.end());
	return completePath;
}

Tile MapGrid::GetTile(TileCoords coord)
{

	return listOfTiles[coord.x][coord.y];
	
}

TileCoords MapGrid::GetCoordsV(Vector2 tilePos)
{
	TileCoords returnTileCoords;
	returnTileCoords.x = tilePos.x/32;
	returnTileCoords.y = tilePos.y/32;
	return returnTileCoords;
}

Vector2 MapGrid::VposToCoords(TileCoords pos)
{


	return { (float)32 * pos.x, (float)32 * pos.y };
}

void MapGrid::DrawBox(int x, int y)
{
	if (x < columns && x >= 0 && y < rows && y >= 0)
	{
		Tile tile = listOfTiles[x][y];
	
		DrawRectangleLines(tile.x, tile.y, tile.size, tile.size, WHITE);
	}
}

void MapGrid::Draw()
{
	for (auto column: listOfTiles)
	{
		for (auto tile : column)
		{

			//tile.DrawTile();
			switch (tile.type)
			{
			case(BRICK):
				DrawRectangleV({ (float)tile.x,(float)tile.y }, { (float)tile.size, (float)tile.size }, BLUE);
				break;

			case(POWERPALLETE):
				//pallet->box.pos = { (float)x * tileSize + tileSize / 2, (float)y * tileSize + tileSize / 2 };
				tile.pallet->Draw();
				tile.pallet->collision.Draw();
				break;
			case(PALLETE):
				tile.pallet->Draw();
			default:
				break;
			}
		}
	}
}

void Tile::DrawTile(Color colour)
{
	DrawRectangleLines(x, y, size, size, colour);
}

TileCoords::TileCoords()
{
}

TileCoords::TileCoords(int _x, int _y)
{

	//int distToCenter = 32 / 2;
	x = _x;
	y = _y;

}

TileCoords TileCoords::operator+(const TileCoords& tileToADD)
{
	TileCoords addedTiles;
	addedTiles.x = x + tileToADD.x;
	addedTiles.y = y + tileToADD.y;
	return addedTiles;
}

TileCoords TileCoords::operator-(const TileCoords& tileToSUB)
{
	TileCoords subtactTiles;
	subtactTiles.x = x + tileToSUB.x;
	subtactTiles.y = y + tileToSUB.y;
	return subtactTiles;
}

bool TileCoords::operator==(TileCoords tileComparason)
{
	if (x == tileComparason.x && y == tileComparason.y)
	{
		return true;
	}
	return false;
}
