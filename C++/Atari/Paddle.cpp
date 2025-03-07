#include "Paddle.h"

Paddle::Paddle()
{
	dataInfo.pos = { windowWidth/2 - 100, windowHeight - 100 - 60 };
	dataInfo.size = { 200, 30 };
	dataInfo.vel = 50;
}

void Paddle::Input()
{
	if (dataInfo.pos.x <= windowWidth)
	{
		if (IsKeyDown((KEY_D)))
		{
			dataInfo.pos.x += dataInfo.vel;
		}
	}
}

void Paddle::Update()
{

}

void Paddle::Draw()
{
	DrawRectangleV(dataInfo.pos, dataInfo.size, BLUE);
}
