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

	box = AABB(_pos, {_size,_size});
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

	switch (pType)
	{

	case(Pallete):
		DrawCircleV(box.pos, palletSize, WHITE);
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