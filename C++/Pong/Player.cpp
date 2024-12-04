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
			paddleSpeed

		};
		colourSelection = BLUE;

	}
	if (playerID == 2) 
	{
		dataInfo =
		{
			{screenWidth - dataInfo.scaleSize.x - 20, screenHeight/2},
			{dataInfo.scaleSize},
			paddleSpeed

		};

		colourSelection = RED;
	}
	
}

void Player::Input()
{

}
