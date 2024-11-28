#include "Paddles.h"

Paddles::Paddles()
{

}

Paddles::Paddles(Vector2 position, Vector2 size, float speed)
{
	position = dataInfo.pos;
	//size = dataInfo.size;
}

void Paddles::Update()
{

}

void Paddles::Draw()
{
	DrawRectangleV((dataInfo.pos), (dataInfo.scaleSize), RED);
}
