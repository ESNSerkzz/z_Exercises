#pragma once
#include <vector>
#include "Palletes.h"
#include "fstream"
#include <iostream>
#include <string>
#include "raylib.h"
enum TileType
{
	EMPTY, BRICK, PALLETE, POWERPALLETE, FRUIT
};

struct Tile
{
	AABB TileCollision;
	int x;
	int y;
	int size;
	Palletes* pallet;
	TileType type = (TileType) 0;

	void DrawTile();
	//Pathfinding
	std::vector <Tile*> allNeighbours;
	Tile* prevTile;
	bool explored;
	float cost;

};
struct tileCoords
{

	int x;
	int y;
	tileCoords();
	tileCoords(int _x, int _y);
};

class MapGrid
{
public:
	int columns = 28;
	int rows = 36;

	MapGrid();
	MapGrid(int _columns, int _rows, int tileSize);
	MapGrid(int _columns, int _rows, int tileSize, std::string filePath);

	std::vector<Tile> BoxesAroundPoint(Vector2 pos);
	std::vector<tileCoords> GetBricklessSpaceAroundOrigin(tileCoords _N);
	std::vector<tileCoords> dijkstrasPathing(tileCoords startPos, tileCoords endPos);

	std::vector<std::vector <Tile>> listOfTiles;
	
	//gets Tile USING tileCoords
	Tile GetTile(tileCoords coord);
	tileCoords GetCoords(Vector2 tilePos);
	Vector2 posToCoords(tileCoords pos);
	void DrawBox(int x, int y);
	void Draw();

};