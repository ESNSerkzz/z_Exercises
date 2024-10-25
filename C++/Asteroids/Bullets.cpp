#include "Bullets.h"

Bullets::Bullets(GameSpacePosition* pos, float speed)
{
	locationInfo =
	{
		pos->pos,
		{
			(speed * sinf(pos->rotation)) + pos->deltaVelocity.x ,
			(-speed * cosf(pos->rotation)) + pos->deltaVelocity.y
		},
		pos->rotation
	};
	tiles = MapGrid(BULLET);

	bulletAge = 0;

	deletable = false;

	

	//deletable = true;

	/*if (deletable = true)
	{

	}*/
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

	if (bulletAge > bulletsduration)
	{
		deletable = true;
	}
	path.insert(locationInfo.pos);
}
