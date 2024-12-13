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
	
	paddleCollision = AABB(dataInfo.pos, dataInfo.scaleSize);

}

void Player::Update(float delta)
{
	paddleCollision.setPos(dataInfo.pos);

}

void Player::Input(float delta)
{

	if (playerID == 1)
	{

		if (dataInfo.pos.y >= borderHeight)
		{
			if (IsKeyDown(KEY_W))
			{
				dataInfo.pos.y -= paddleSpeed;
			}
			
		}
		
		if (dataInfo.pos.y <= screenHeight - borderHeight - dataInfo.scaleSize.y)
		{
			if (IsKeyDown(KEY_S))
			{
				dataInfo.pos.y += paddleSpeed;
			}
		}

	}
	
	if (playerID == 2)
	{
		/* send frank Email asking about what i should prepare for Yr2 course and any...
		curriculum changes i should be aware of.*/
		if (dataInfo.pos.y >= borderHeight)
		{
			if (IsKeyDown(KEY_UP))
			{
				dataInfo.pos.y -= paddleSpeed;
				//todo: make IF so it doesn't exceed the border in height
			}

		}
		
		if (dataInfo.pos.y <= screenHeight - borderHeight - dataInfo.scaleSize.y)
		{
			if (IsKeyDown(KEY_DOWN))
			{
				dataInfo.pos.y += paddleSpeed;
			
			}
		}
	}
}
