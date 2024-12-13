#include "Paddles.h"

Paddles::Paddles()
{
	colourSelection = WHITE;
}

Paddles::Paddles(Vector2 position, Vector2 size, float speed)
{
	

	
}

void Paddles::Update()
{
	
}

void Paddles::Draw()
{
	DrawRectangleV((dataInfo.pos), (dataInfo.scaleSize), colourSelection);
}
