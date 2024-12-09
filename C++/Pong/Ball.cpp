#include "Ball.h"

Ball::Ball(Vector2 startVel)
{
	dataInfo.speed = startVel;
	dataInfo.pos = { screenWidth / 2 ,  screenHeight / 2 };
	dataInfo.scaleSize = { 30, 30 };
	
	
}

void Ball::Draw(void)
{
	// create instance of ball in main and draw / update
	// draw / update it here (good luck with the update)

	DrawCircleV(dataInfo.pos, 25, WHITE);

}

void Ball::Update(float delta)
{
	dataInfo.pos.x += dataInfo.speed.x * delta;
	dataInfo.pos.y += dataInfo.speed.y * delta;
}
