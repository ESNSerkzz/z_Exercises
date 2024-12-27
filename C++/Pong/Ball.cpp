#include "Ball.h"

Ball::Ball(Vector2 startVel)
{
	dataInfo.speed = startVel;
	dataInfo.pos = { screenWidth / 2 ,  screenHeight / 2 };
	dataInfo.scaleSize = { 30, 30 };
	
	ballCollision = AABB(dataInfo.pos, dataInfo.scaleSize);
}

void Ball::Draw(void)
{

	DrawCircleV({dataInfo.pos.x + 15, dataInfo.pos.y + 15}, 15, WHITE);
	ballCollision.Draw();
}

void Ball::Update(float delta)
{

	ballCollision.setPos(dataInfo.pos);

	dataInfo.pos.x += dataInfo.speed.x * delta;
	dataInfo.pos.y += dataInfo.speed.y * delta;

	//if (dataInfo.pos.y <= borderHeight)
	//{
	//	dataInfo.pos.y += dataInfo.speed.y;
	//	//dataInfo.pos.y += dataInfo.speed.y * delta;
	//}
	
	//if(ballCollision.isOverLapped())

}

void Ball::verticalBounce(float delta)
{
	/*if (ballCollision.pos.y == borderHeight)
	{
	}*/
	dataInfo.speed.y = -dataInfo.speed.y;
	
	// try a switch case, see what happens
	

	//dataInfo.pos.y 

}
