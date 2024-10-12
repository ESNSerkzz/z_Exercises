#include "Player.h"

Player::Player()
{
	locationInfo =
	{
		{screenWidth / 2,
		screenHeight / 2
		},

		{
			0,0
		},
		
		0.0f,

	};
	tiles = MapGrid(SHIP);

	return;
}

void Player::Draw()
{
	
	
	tiles.Draw(locationInfo.rotation, {-20, -20}, locationInfo.pos);
	
}

void Player::Update(float delta)
{
	SpaceObject::Update(delta);
	//SpaceObject::Update(Player::playerObject.Draw());
}

void Player::Input(float delta)
{
	if (IsKeyDown(KEY_UP)) AddThrust(playerSpeed, delta);
	if (IsKeyDown(KEY_DOWN))AddThrust(-playerSpeed, delta);
	if (IsKeyDown(KEY_LEFT)) AddRotation(-torque, delta);
	if (IsKeyDown(KEY_RIGHT)) AddRotation(torque, delta);

}
