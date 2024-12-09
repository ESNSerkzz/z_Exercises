#include "Paddles.h"

Paddles::Paddles()
{
	colourSelection = WHITE;
}

Paddles::Paddles(Vector2 position, Vector2 size, float speed)
{
	//dataInfo.pos = position;
	//dataInfo.scaleSize = size ;

	
}

void Paddles::Update()
{
	
}

void Paddles::Draw()
{
	DrawRectangleV((dataInfo.pos), (dataInfo.scaleSize), colourSelection);
}
