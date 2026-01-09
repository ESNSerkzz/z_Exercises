#include "ScreenGrid.h"

TileCoords::TileCoords()
{

}

TileCoords::TileCoords(int _x, int _y)
{
	rows = _x * tileSize;
	columns = _y * tileSize;
}
