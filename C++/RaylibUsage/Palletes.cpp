#include "Collisions.h"
#include "Pacman.h"
#include "raylib.h"
#include "Palletes.h"

Palletes::Palletes()
{
	box = AABB({ 0.0f , 0.0f }, {palletSize, palletSize});
}

Palletes::Palletes(Vector2 _pos, float _size)
{

	box = AABB(_pos, {_size,_size});
}

void Palletes::Update()
{
}

void Palletes::Draw()
{
	DrawCircleV(box.pos, box.halfSize.x, BEIGE);

};