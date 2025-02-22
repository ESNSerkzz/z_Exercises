#include "Paddles.h"

Paddles::Paddles()
{
	colourSelection = WHITE;
}

Paddles::Paddles(Vector2 position, Vector2 size, float speed)
{
	
}

void Paddles::Update()
{
	
}

void Paddles::Draw()
{
	DrawRectangleV((dataInfo.pos), (dataInfo.scaleSize), colourSelection);
	//paddleCollision.Draw();
}

void Paddles::HitBall(Ball& ball)
{
	//when it hits the ball
	Vector2 spaceBetween = Vector2Subtract(
		Vector2Add(paddleCollision.pos, Vector2Divide(paddleCollision.size, { 2,2 })),
		Vector2Add(ball.ballCollision.pos, Vector2Divide(ball.ballCollision.size, { 2,2 })));
	Vector2 speed = Vector2Normalize(spaceBetween);
	speed = Vector2Rotate(speed, M_PI);



	//std::cout << "Normalized distance = " << Vector2Length(speed) << "\n";
	ball.dataInfo.speed = { speed.x * ballSpeed, speed.y * ballSpeed };

}


