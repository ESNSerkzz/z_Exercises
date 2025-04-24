#include "Ball.h"

Ball::Ball()
{
}

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
	//ballCollision.Draw();
}

void Ball::Update(float delta)
{


	

	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		dataInfo.pos.x = GetMouseX();
		dataInfo.pos.y = GetMouseY();
	}
	
	else
	{
		dataInfo.pos.x += dataInfo.speed.x * delta;
		dataInfo.pos.y += dataInfo.speed.y * delta;
	}


	ballCollision.setPos(dataInfo.pos);

	//if (dataInfo.pos.y <= borderHeight)
	//{
	//	dataInfo.pos.y += dataInfo.speed.y;
	//	//dataInfo.pos.y += dataInfo.speed.y * delta;
	//}
	
	//if(ballCollision.isOverLapped())

}

void Ball::Bounce(float delta)
{
	dataInfo.speed.y = -dataInfo.speed.y;
	//dataInfo.speed.x = -dataInfo.speed.x;
	dataInfo.speed = Vector2Multiply(dataInfo.speed, {1.25, 1.25});
}
