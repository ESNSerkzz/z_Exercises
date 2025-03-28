#include "Ball.h"

Ball::Ball()
{
}

Ball::Ball(Vector2 startVel)
{
	dataInfo.pos = { windowWidth / 2, windowHeight / 2 };
	//dataInfo.pos = GetMousePosition();

	dataInfo.radius = 20;
	dataInfo.vel = startVel;
	startVel = { 0, 40 };
	
	ballCollision = CC(dataInfo.pos, dataInfo.radius);
}

void Ball::Update(float delta)
{
	ballCollision.pos = dataInfo.pos;
	dataInfo.pos = GetMousePosition();

	//dataInfo.pos = Vector2Add(Vector2Scale(dataInfo.vel, delta), dataInfo.pos);

}

void Ball::Draw()
{
	DrawCircleV(dataInfo.pos, dataInfo.radius, WHITE);
}
