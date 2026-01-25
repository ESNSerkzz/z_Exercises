#include "ScreenGrid.h"

Tile::Tile()
{
}

void Tile::DrawTile()
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