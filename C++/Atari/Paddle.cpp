#include "Paddle.h"

Paddle::Paddle()
{
	dataInfo.pos = { windowWidth/2 - 100, 840 };
	dataInfo.size = { 200, 30 };
	dataInfo.vel = { 100, 100 };

	boxCollision = AABB(dataInfo.pos, dataInfo.size);
}

void Paddle::Input(float delta)
{
	if (dataInfo.pos.x <= windowWidth - dataInfo.size.x && IsKeyDown(KEY_D))
	{
		dataInfo.pos.x += 300 * delta;
		
	}

	if(dataInfo.pos.x >= 0 && IsKeyDown(KEY_A))
	{
		dataInfo.pos.x -= 300 * delta;
		
	}
	
}

void Paddle::Update()
{
	boxCollision.pos = dataInfo.pos;
	
}

void Paddle::Draw()
{
	DrawRectangleV(dataInfo.pos, dataInfo.size, BLUE);
	boxCollision.Draw();
}
