#include "Bullets.h"

Bullets::Bullets(GameSpacePosition* pos, float speed)
{
	locationInfo =
	{
		pos->pos,
		{
			(speed * sinf(pos->rotation)),
			(-speed * cosf(pos->rotation))
		},
		pos->rotation
	};
	tiles = MapGrid(BULLET);

	bulletAge = 0;

	bulletDeletable = false;

	

	
}   

void Bullets::Draw()
{
	tiles.Draw(locationInfo.rotation, {-10,-10}, locationInfo.pos);
	path.draw();
}

void Bullets::Update(float delta)
{
	SpaceObject::Update(delta);
	bulletAge++;

	if (bulletAge > bulletsDuration)
	{
		bulletDeletable = true;
	}
	path.insert(locationInfo.pos);

	

}
