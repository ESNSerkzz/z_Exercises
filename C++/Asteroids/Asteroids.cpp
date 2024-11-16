#include "Asteroids.h"

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
		16
	};

	tiles = MapGrid (ASTEROID);
	toDelete = false;
	return;
}

Asteroid::Asteroid(Vector2 startPos, Vector2 velocity, int size)
{
	locationInfo =
	{
		startPos, velocity, 0, size
	};
	
	tiles = MapGrid(ASTEROID);
	toDelete = false;
	return;

}

void Asteroid::Draw()
{
	tiles.Draw(locationInfo.rotation, { (float)locationInfo.size, (float)locationInfo.size }, locationInfo.pos);
}

void Asteroid::Update(float delta)
{
	SpaceObject::Update(delta);

	locationInfo.rotation += 0.05f;

}
