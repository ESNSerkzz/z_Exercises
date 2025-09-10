#include "Collisions.h"
#include "Pacman.h"
#include "raylib.h"
#include "Palletes.h"

Palletes::Palletes()
{
	box = AABB({ 0.0f , 0.0f }, {palletSize, palletSize});
	pType = Pallete;
}

Palletes::Palletes(Vector2 _pos, float _size)
{
	Vector2 pos = { _pos.x - _size,_pos.y - _size };
	box = AABB(pos, {_size,_size});
	pType = Pallete;
}

Palletes::Palletes(Vector2 _pos, float _size, PalleteType type)
{
	box = AABB(_pos, { _size,_size });
	pType = type;
}

void Palletes::Update()
{

}

void Palletes::Draw()
{
	Vector2 pos;
	switch (pType)
	{

	case(Pallete):
		pos = { box.pos.x + box.halfSize.x, box.pos.y + box.halfSize.y };
		DrawCircleV(pos, palletSize, WHITE);
		break;

	case(PowerPallete):
		DrawCircleV(box.pos, powerPalletSize, WHITE);
		break;
	case(Fruit):
		DrawCircleV(box.pos, powerPalletSize, RED);
		break;
	default:
		break;
	}

	

};