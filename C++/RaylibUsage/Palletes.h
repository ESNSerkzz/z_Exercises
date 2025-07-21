#pragma once
#include "Raylib.h"
#include "Collisions.h"
#include "Constants.h"
#include <vector>
enum PalleteType
{
	Pallete, PowerPallete, Fruit
};
class Palletes
{
public:
	PalleteType pType;
	AABB box;
	Palletes();
	Palletes(Vector2 _pos, float _size);
	Palletes(Vector2 _pos, float _size, PalleteType type);
	void Update();
	void Draw();
};
