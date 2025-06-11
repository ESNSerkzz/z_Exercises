#include "Ball.h"
#include "Constants.h"
#include "FieldAbilities.h"
#include "Paddles.h"
#include "Player.h"
#include "ScreenObjects.h"
#include <raymath.h>
#include <raylib.h>
#include <vector>
#include <string>
#include <iostream>

#define M_PI 3.14159



static void SetUp();
static void Update(float delta);
static void Input(float delta);
static void Draw();

Player player1 = Player(1);
Player player2 = Player(2);

Ball ball = Ball({-200, 0});

AABB topBorder = AABB({ 0,0 }, { screenWidth, borderHeight });
AABB bottomBorder = AABB({ 0, screenHeight - borderHeight }, { screenWidth, borderHeight });

std::vector <FieldAbilities*> PowerUpBoxes;
int rallyScore;

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
	rallyScore = 0;
	
	
	PowerUpBoxes.push_back(new FieldAbilities(0));
	PowerUpBoxes.push_back(new FieldAbilities(10));
	PowerUpBoxes.push_back(new FieldAbilities(50));
	PowerUpBoxes.push_back(new FieldAbilities(80));
	
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
	


	//reset ball to middle of screen
	if (ball.dataInfo.pos.x < 0 || ball.dataInfo.pos.x > screenWidth)
	{
		rallyScore = 0;
		if (ball.dataInfo.pos.x < 0)
		{
			player2.AddScore(1);
		}
		else
		{
			player1.AddScore(1);
		}
			
		ball = Ball({ -200, 0 });
	}


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
	}

	
	//space between ball and paddle

	
	if (player1.paddleCollision.isOverLapped(ball.ballCollision))
	{
		player1.HitBall(ball);
		ball.Update(delta);
		ball.Update(delta);

		rallyScore++;
		player1.PaddleRally(rallyScore);
		player2.PaddleRally(rallyScore);
	}

	if (player2.paddleCollision.isOverLapped(ball.ballCollision))
	{
		player2.HitBall(ball);
		ball.Update(delta);
		ball.Update(delta);
		rallyScore++;
		player1.PaddleRally(rallyScore);
		player2.PaddleRally(rallyScore);
	}	

	
	for (auto i : PowerUpBoxes)
	{
		
		if (i->abilityBox.isOverLapped(ball.ballCollision))
		{
			i->PowerUpAbility(&ball);
			i->deletable = true;
		}

		
	}
	if (PowerUpBoxes.size() > 0)
	{
		auto i = remove_if(PowerUpBoxes.begin(), PowerUpBoxes.end(),
			[&](FieldAbilities* o)
			{
				return (o->deletable);
			}
		);

		if (i != PowerUpBoxes.end())
		{
			PowerUpBoxes.erase(i);
		}

		
	}
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

	//PowerUpBox.Draw();

	for (auto i : PowerUpBoxes) i->Draw();

	//Player drawing
	player1.Draw();
	player2.Draw();

	ball.Draw();
	
	DrawText(TextFormat("Rally: %03i", rallyScore), screenWidth/ 2 - 100, 10, 50, YELLOW);
	DrawText(TextFormat("Score: %02i", player1.playerScore), 50, screenHeight - 50, 50, BLUE);
	DrawText(TextFormat("Score: %02i", player2.playerScore),screenWidth - 350, screenHeight - 50, 50, RED);

	EndDrawing();
}
