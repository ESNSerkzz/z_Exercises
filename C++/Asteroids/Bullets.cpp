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

	deletable = false;
	////---------------------------------------------
	//for (int i = 0; i <= bulletsduration; i++)
	//{
	//	if (i == bulletsduration)
	//	{
	//		deletable = true;
	//	}
	//}

	//deletable = true;

	//if (deletable = true)
	//{

	//}
}   //=============================================

void Bullets::Draw()
{
	tiles.Draw(locationInfo.rotation, {-10,-10}, locationInfo.pos);
}
