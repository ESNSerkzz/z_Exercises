#include "Player.h"

Player::Player(int player_ID)
{
	playerID = player_ID;
	
	if (playerID == 1)
	{
		dataInfo = 
		{
			{ 30 , screenHeight / 2 },
			{dataInfo.scaleSize},
			
			{0,0},

		};
		colourSelection = BLUE;

	}
	if (playerID == 2) 
	{
		dataInfo =
		{
			{screenWidth - dataInfo.scaleSize.x - 20, screenHeight/2},
			{dataInfo.scaleSize},
			{0,0},

		};

		colourSelection = RED;
	}
	
}

void Player::Update(float delta)
{
	
}

void Player::Input(float delta)
{

	if (playerID == 1)
	{
		
		if (IsKeyDown(KEY_W)) 
		{
			dataInfo.pos.y -= paddleSpeed ;
			
		}

		if (IsKeyDown(KEY_S))
		{
			dataInfo.pos.y += paddleSpeed;
			
		}
	}
	
	if (playerID == 2)
	{
		/* send frank Email asking about what i should prepare for Yr2 course and any...
		curriculum changes i should be aware of.*/
		if (IsKeyDown(KEY_UP))
		{
			dataInfo.pos.y -= paddleSpeed;
			//todo: make IF so it doesn't exceed the border in height
		}

		if (IsKeyDown(KEY_DOWN))
		{
			dataInfo.pos.y += paddleSpeed;
			
		}
	}
}
