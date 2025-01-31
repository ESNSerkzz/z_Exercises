#include "Ball.h"
#include "Constants.h"
#include "Paddles.h"
#include "Player.h"
#include "ScreenObjects.h"
#include <raymath.h>
#include <raylib.h>
#include <vector>
#include <string>
#include <iostream>


static void SetUp();
static void Update(float delta);
static void Input(float delta);
static void Draw();

Player player1 = Player(1);
Player player2 = Player(2);

Ball ball = Ball({-200, 0});

AABB topBorder = AABB({ 0,0 }, { screenWidth, borderHeight });
AABB bottomBorder = AABB({ 0, screenHeight - borderHeight }, { screenWidth, borderHeight });

int main(void)
{

	SetUp();
	while (!WindowShouldClose())
	{
		Input(GetFrameTime());
		Draw();
		Update(GetFrameTime());


	}

};

void SetUp()
{
	InitWindow(screenWidth, screenHeight, "Window");
	SetTargetFPS(60);

}

static void Input(float delta)
{
	player1.Input(delta);
	player2.Input(delta);

}


static void Update(float delta)
{
	player1.Update(delta);
	player2.Update(delta);
	ball.Update(delta);

	//topBorder.isOverLapped(ball.ballCollision);
	if (topBorder.isOverLapped(ball.ballCollision) || bottomBorder.isOverLapped(ball.ballCollision))
	{
		if (bottomBorder.isOverLapped(ball.ballCollision))
		{
			std::cout << "bottom" << std::endl;
		}
		else
		{
			std::cout << "top" << std::endl;
		}

		ball.Bounce(delta);
		ball.Update(delta);
		ball.Update(delta);
		//std::cout << "top" << std::endl;
	}

	//space between ball and paddle
	
	if (player1.paddleCollision.isOverLapped(ball.ballCollision))
	{

		Vector2 spaceBetween = Vector2Subtract(Vector2Add(player1.paddleCollision.pos, player1.paddleCollision.size), Vector2Divide(ball.ballCollision.size, { 2,2 }));
		Vector2 speed = Vector2Normalize(spaceBetween);
		speed = Vector2Invert(spaceBetween);
		
		std::cout << "paddle1" << std::endl;
		std::cout << "Distance = " << Vector2Length(spaceBetween) << "\n";
		
		


		std::cout << "Normalized distance = " << Vector2Length(speed) << "\n";
		ball.dataInfo.speed = { speed.x * spaceBetween.y * ballSpeed };
		ball.Update(delta);
		ball.Update(delta);
	}

	//if (player2.paddleCollision.isOverLapped(ball.ballCollision))
	//{
	//	std::cout << "paddle2" << std::endl;
	//	
	//	Vector2 spaceBetween = Vector2Subtract(player2.paddleCollision.pos, ball.ballCollision.pos);
	//	//Vector2 spaceBetween =
	//	//{ player2.paddleCollision.pos.x + player2.paddleCollision.size.x / 2 - ball.ballCollision.pos.x + ball.ballCollision.size.x / 2,
	//	//player2.paddleCollision.pos.y + player2.paddleCollision.size.y / 2 - ball.ballCollision.pos.y + ball.ballCollision.size.y / 2 };

	//	std::cout << "Distance = " << Vector2Length(spaceBetween) << "\n";

	//	Vector2 speed = Vector2Normalize(spaceBetween);

	//	speed = Vector2Invert(speed);

	//	

	//	std::cout << "Normalized distance = " << Vector2Length(speed) << "\n";
	//	ball.dataInfo.speed = { speed.x * ballSpeed, spaceBetween.y * ballSpeed };

	//	ball.Update(delta);
	//	ball.Update(delta);
	//}



}

static void Draw()
{
	BeginDrawing();
	ClearBackground(BLACK);
	//Map
	//edges
	DrawLineV({ 0,50 }, { screenWidth, 50 }, WHITE);
	DrawLineV({  0, screenHeight - 50}, {  screenWidth, screenHeight -50}, WHITE);
	//dividing line
	DrawLineV({ screenWidth / 2, 50 }, {screenWidth/2, screenHeight-50}, WHITE);

	//Player drawing
	player1.Draw();
	player2.Draw();

	topBorder.Draw();
	bottomBorder.Draw();

	ball.Draw();

	EndDrawing();
}
