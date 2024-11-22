#include "Asteroids.h"
#include <iostream>

Asteroid::Asteroid()
{
	locationInfo =
	{
		{(float)rand() / RAND_MAX * screenWidth * 2,
		(float)rand() / RAND_MAX * screenHeight * 2},
		{
			(float)sin((float)rand() / RAND_MAX * 6.82) * 7,
			(float)-cos((float)rand() / RAND_MAX * 6.82) * 7
		},
		(float)(rand() / RAND_MAX * 6.82),
		128
	};

	tiles = MapGrid (ASTEROID);
	toDelete = false;
	return;
}

Asteroid::Asteroid(Vector2 startPos, Vector2 velocity, int size)
{
	locationInfo =
	{
		startPos, velocity, 4, size
	};
	
	tiles = MapGrid(ASTEROID);
	toDelete = false;

	std::cout << size << "\n";
	return;

}

void Asteroid::Draw()
{
	tiles.Draw(locationInfo.rotation, { (float)locationInfo.size / 5, (float)locationInfo.size /5} , locationInfo.pos);
}

void Asteroid::Update(float delta)
{
	SpaceObject::Update(delta);

	locationInfo.rotation += 0.05f;

}
