#include "Paddle.h"

Paddle::Paddle()
{
	dataInfo.pos = { windowWidth/2 - 100, windowHeight - 100 - 60 };
	dataInfo.size = { 200, 30 };
	
}

void Paddle::Input()
{
}

void Paddle::Update()
{
}

void Paddle::Draw()
{
	DrawRectangleV(dataInfo.pos, dataInfo.size, BLUE);
}
