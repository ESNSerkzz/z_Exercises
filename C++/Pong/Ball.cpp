#include "Ball.h"

Ball::Ball()
{
}

Ball::Ball(Vector2 startVel)
{
	dataInfo.speed = startVel;
	dataInfo.pos = { screenWidth / 2 ,  screenHeight / 2 };
	dataInfo.scaleSize = { 30, 30 };
	
	startVel =
	{
		dataInfo.pos.x + dataInfo.pos.x,
		dataInfo.pos.y + dataInfo.pos.y
	};
}

void Ball::Draw(void)
{
	// create instance of ball in main and draw / update
	// draw / update it here (good luck with the update)
}

void Ball::Update()
{

}
