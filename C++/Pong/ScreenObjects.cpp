#include "ScreenObjects.h"

ScreenObjects::ScreenObjects()
{
	dataInfo =
	{
		{100, 100},
		{20, 60},
		paddleSpeed
		
	};
}

void ScreenObjects::Draw(void)
{
	DrawLineV({ 0,100 }, { screenWidth, 100 }, WHITE);
	DrawLineV({ 0, screenHeight - 100 }, { screenWidth, screenHeight - 100 }, WHITE);
	DrawLineV({ screenWidth / 2, 100 }, { screenWidth / 2, screenHeight - 100 }, WHITE);
	

}

void ScreenObjects::Update()
{
}
