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

	void DrawTile(Color colour);
	//Pathfinding
	std::vector <Tile*> allNeighbours;
	Tile* prevTile;
	bool explored;
	float cost;

};
struct TileCoords
{

	int x;
	int y;
	TileCoords();
	TileCoords(int _x, int _y);
	TileCoords operator+ (const TileCoords &tileToADD);
	TileCoords operator- (const TileCoords& tileToSUB);
	void Invert();
	bool operator==(TileCoords tileComparason);
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
	std::vector<TileCoords> GetBricklessSpaceAroundOrigin(TileCoords _N);
	std::vector<TileCoords> dijkstrasPathing(TileCoords startPos, TileCoords endPos);

	std::vector<std::vector <Tile>> listOfTiles;
	
	//gets Tile USING tileCoords
	Tile GetTile(TileCoords coord);
	TileCoords GetCoordsV(Vector2 tilePos);
	Vector2 VposToCoords(TileCoords pos);
	
	void DrawBox(int x, int y);
	void Draw();

};