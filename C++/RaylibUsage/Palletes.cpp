#include "Collisions.h"
#include "Pacman.h"
#include "raylib.h"
#include "Palletes.h"

Palletes::Palletes()
{
	collision = AABB({ 0.0f , 0.0f }, {palletSize, palletSize});
	pType = Pallete;
}

Palletes::Palletes(Vector2 _pos, float _size)
{
	Vector2 pos = { _pos.x - _size,_pos.y - _size };
	collision = AABB(pos, {_size,_size});
	pType = Pallete;
}

Palletes::Palletes(Vector2 _pos, float _size, PalleteType type)
{
	collision = AABB(_pos, { _size,_size });
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
		pos = { collision.pos.x + collision.halfSize.x, collision.pos.y + collision.halfSize.y };
		DrawCircleV(pos, palletSize, WHITE);
		break;

	case(PowerPallete):
		DrawCircleV(collision.pos, powerPalletSize, WHITE);
		break;
	case(Fruit):
		DrawCircleV(collision.pos, powerPalletSize, RED);
		break;
	default:
		break;
	}

};