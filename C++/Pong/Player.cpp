#include "Player.h"

Player::Player(int player_ID)
{
	playerID = player_ID;
	
	if (playerID == 1)
	{
		dataInfo = 
		{
			{ 30 , screenHeight / 2 },
			{20, 60},
			paddleSpeed

		};
		colourSelection = BLUE;

	}
	if (playerID == 2) 
	{
		dataInfo =
		{
			{screenWidth - 30, screenHeight/2},
			{20, 60},
			paddleSpeed

		};

		colourSelection = RED;
	}
	
}

void Player::Input()
{

}
