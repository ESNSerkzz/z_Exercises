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
	//TODO
	//create grid with co-ords, and draw lines from co-ord to co-ord
	//DrawCircle(locationInfo.pos.x, locationInfo.pos.y, 30, BLUE);
	tiles.Draw(locationInfo.rotation, {20, 20}, locationInfo.pos);
	//DrawRectangle(locationInfo.pos.x, locationInfo.pos.y, 50, 50, BLUE);
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
	if (IsKeyDown(KEY_LEFT)) AddRotation(torque, delta);
	if (IsKeyDown(KEY_RIGHT)) AddRotation(-torque, delta);
}
