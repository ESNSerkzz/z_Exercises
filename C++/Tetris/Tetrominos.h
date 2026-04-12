#pragma once
#include "collisions.h"
#include "raylib.h"
#include <vector>
enum ShapeType
{
	I_shape, O_shape, T_shape, S_shape, Z_shape, L_shape, J_shape
};

enum TileType
{
	EMPTY, BRICK, TETROMINO	
};

struct Tile
{
	int x; // in grid coords X.
	int y; // in grid coords Y.
	TileType tType = TileType(0);
	Tile();
	Tile(Vector2 _pos);
	Tile(TileType _type, int _x, int _y);

	void DrawTile(Color _lines, Color _fill);
	void Draw();
};

class Tetrominos
{
public:
	std::vector<Tile>tetrominos;
	float descentRateTimer;

	ShapeType shape;

	Tetrominos();
	Tetrominos(ShapeType _bType);
	
	
	std::vector<Tile> BlockCanvas(Tetrominos tetromino);
	void Decention();

	void Input();
	void Update(float delta);
	void Draw();
};
