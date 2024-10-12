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
	//TODO
	// construct the bullet image (see MapGrid.cpp to re-jog memory)
}
