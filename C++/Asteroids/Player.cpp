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
	for (auto& b : bullets)
	{
		b.Draw();
	}
	pathForPlayer.draw();
}

void Player::Update(float delta)
{
	SpaceObject::Update(delta);
	//SpaceObject::Update(Player::playerObject.Draw());
	locationInfo.deltaVelocity.x = locationInfo.deltaVelocity.x * 0.95;
	locationInfo.deltaVelocity.y = locationInfo.deltaVelocity.y * 0.95;

	for (auto& b : bullets)
	{
		b.Update(delta);
	}

	if (bullets.size() > 0)
	{
		auto i = remove_if(
			bullets.begin(),
			bullets.end(),
			[&](Bullets o) {
				return(o.bulletDeletable);
			}
		);

		if (i != bullets.end()) {
			bullets.erase(i);
		}

	}
	Vector2 trailOffset = locationInfo.pos;
	
	trailOffset.x -= sinf(locationInfo.rotation) * 50;
	trailOffset.y += cosf(locationInfo.rotation) * 50;
	/*{
	cosf(locationInfo.rotation) - sinf(locationInfo.rotation),
	sinf(locationInfo.rotation) + cosf(locationInfo.rotation)
	};*/

	

	pathForPlayer.insert(trailOffset);



}

void Player::Input(float delta)
{
	if (IsKeyDown(KEY_UP)) AddThrust(playerSpeed, delta);
	if (IsKeyDown(KEY_DOWN)) AddThrust(-playerSpeed, delta);
	if (IsKeyDown(KEY_LEFT)) AddRotation(-torque, delta);
	if (IsKeyDown(KEY_RIGHT)) AddRotation(torque, delta);
	if (IsKeyPressed(KEY_SPACE)) bullets.push_back(Bullets(&locationInfo, 20));

}
