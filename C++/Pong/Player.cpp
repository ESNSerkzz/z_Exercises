#include "Player.h"
#include "Constants.h"

Player::Player(int player_ID)
{
	playerScore = 0;
	playerID = player_ID;
	
	if (playerID == 1)
	{
		dataInfo = 
		{
			{ 30 , screenHeight / 2 },
			{20, PaddleStartHeight},
			
			{0,0},

		};
		colourSelection = BLUE;

	}
	if (playerID == 2)
	{
		dataInfo =
		{
			{screenWidth - dataInfo.scaleSize.x - 20, screenHeight/2},
			{20 , PaddleStartHeight},
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
		
		if (dataInfo.pos.y >= borderHeight)
		{
			if (IsKeyDown(KEY_UP))
			{
				dataInfo.pos.y -= paddleSpeed;
				
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

void Player::PaddleRally(int rallyS)
{
	if (rallyS == 3)
	{
		paddleCollision.size.y = paddleCollision.size.y / 2;
		dataInfo.scaleSize.y = dataInfo.scaleSize.y / 2;
	}
	/*if (rallyS >= 5)
	{
		paddleCollision.size.y = paddleCollision.size.y / 1.2;
		dataInfo.scaleSize.y = dataInfo.scaleSize.y / 1.2;
	}
	if (rallyS >= 7)
	{
		paddleCollision.size.y = paddleCollision.size.y / 1.2;
		dataInfo.scaleSize.y = dataInfo.scaleSize.y / 1.2;
	}*/

}

void Player::AddScore(int score)
{
	playerScore = playerScore + score;
}
