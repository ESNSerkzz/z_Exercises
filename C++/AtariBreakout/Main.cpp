#include "raylib.h"
#include "raymath.h"
#include "Ball.h"
#include "BrickTiles.h"
#include "Paddle.h"
#include "Constants.h"
#include "iostream"
#include <string.h>
#include <vector>

std::vector<BrickTiles*>  LoadBricks(Vector2 topLeftCorner, Vector2 bottomRightCorner, const char* string);
static void SetUp();
static void Update(float delta);
static void Collide(float delta);
static void Draw();

Paddle player = Paddle();
//Ball ball = Ball();

hitResult hitCollision;
Ball ball = Ball({ 0.0f, 80.0f });
std::vector <BrickTiles*> Bricks;
const char* brickPattern =
"0000000002"
"0111111102"
"0110001102"
"0111011102";

const char* brickPattern_2 =
"000000000102"
"011111110102"
"011000110102"
"011101110102"
"000000000002";

AABB leftBorder = AABB({ 0,0 }, { 2, windowHeight });
AABB rightBorder = AABB({windowWidth - 2, 0}, {2, windowHeight});
AABB topBorder = AABB({0,0}, {windowWidth, 2});
AABB bottomBorder = AABB({0, windowHeight - 100}, {windowWidth, 100});


int main()
{
	SetUp();
	while (!WindowShouldClose())
	{
		Collide(GetFrameTime());
		Update(GetFrameTime());
		Draw();
	}
}

std::vector<BrickTiles*> LoadBricks(Vector2 _topLeftCorner, Vector2 _bottomRightCorner, const char* _string)
{ 
	std::vector <BrickTiles*> returnBricks;
	returnBricks.push_back(new BrickTiles());
	int columns;
	int row = 0;
	Vector2 BrickSize;
	
	for (int i = 0; i < (unsigned)strlen(_string); i++)
	{
		if (_string[i] == '2')
		{
			//std::cout << std::endl << i << std::endl;
			BrickSize.x = (_bottomRightCorner.x - _topLeftCorner.x)/ i;
			BrickSize.y = (_bottomRightCorner.y - _topLeftCorner.y) / (strlen(_string) / (i + 1));
			columns = (i + 1);
			

			break;
		}


	}

	for (int i = 0; i < (unsigned)strlen(_string); i++)
	{
		if (_string[i] != '2')
		{
			if (_string[i] == '0')
			{
				returnBricks.push_back(new BrickTiles(
					{
						(_topLeftCorner.x + i * BrickSize.x) - (row * BrickSize.x * 10) ,
						_topLeftCorner.y + (row * BrickSize.y)
					},
					Vector2Subtract(BrickSize, { 2, 2 })
				));
			}
			
		}
		else
		{
			row++;
		}
	}

	return returnBricks;
}

void SetUp()
{
	InitWindow(windowWidth, windowHeight, "WindowScreen");
	Bricks = LoadBricks({ 50, 50 }, {windowWidth - 50, 500}, brickPattern_2);
}

void Update(float delta)
{
	ball.Update(delta);
	player.Update();
	player.Input(delta);
}

void Collide(float delta)
{
	if (ball.ballCollision.isOverlapped(player.boxCollision, hitCollision))
	{
		ball.dataInfo.pos = Vector2Add(ball.dataInfo.pos, Vector2Scale(hitCollision.normal, hitCollision.penetrationDepth + 1.0f));
		ball.dataInfo.vel.y = -ball.dataInfo.vel.y;
		//std::cout << hitCollision.penetrationDepth << std::endl;
		Vector2 MiddleOfBox = Vector2Add(player.dataInfo.pos, Vector2Divide(player.dataInfo.size, { 2,2 }));
		Vector2 BoxToBallNormalise = Vector2Subtract(ball.dataInfo.pos, MiddleOfBox);
		BoxToBallNormalise = Vector2Normalize(BoxToBallNormalise);

	
		ball.dataInfo.vel = Vector2Scale(BoxToBallNormalise, Vector2Length(ball.dataInfo.vel));
	}

	for (auto i : Bricks)
	{
		if (ball.ballCollision.isOverlapped(i->BrickCollision, hitCollision)) 
		{
			ball.dataInfo.pos = Vector2Add(ball.dataInfo.pos, Vector2Scale(hitCollision.normal, hitCollision.penetrationDepth + 1.0f));
			if (hitCollision.normal.x > 0.5 || hitCollision.normal.x < -0.5)
			{
				ball.dataInfo.vel.x *= -1;
			}
			else
			{
				ball.dataInfo.vel.y *= -1;
			}
			//think of the LoadBricks function. think about its parameters.
			
			i->deletable = true;
		
		}
		
	}
	if (ball.ballCollision.isOverlapped(bottomBorder, hitCollision)) 
	{
		std::cout << "lost\n";
	}

	if (ball.ballCollision.isOverlapped(leftBorder, hitCollision))
	{
		ball.dataInfo.pos = Vector2Add(ball.dataInfo.pos, Vector2Scale(hitCollision.normal, hitCollision.penetrationDepth + 1.0f));
		if (hitCollision.normal.x > 0.5 || hitCollision.normal.x < -0.5)
		{
			ball.dataInfo.vel.x *= -1;
		}
		else
		{
			ball.dataInfo.vel.y *= -1;
		}
	}
	if (ball.ballCollision.isOverlapped(rightBorder, hitCollision))
	{
		ball.dataInfo.pos = Vector2Add(ball.dataInfo.pos, Vector2Scale(hitCollision.normal, hitCollision.penetrationDepth + 1.0f));
		if (hitCollision.normal.x > 0.5 || hitCollision.normal.x < -0.5)
		{
			ball.dataInfo.vel.x *= -1;
		}
		else
		{
			ball.dataInfo.vel.y *= -1;
		}
	}

	if (ball.ballCollision.isOverlapped(topBorder, hitCollision))
	{
		ball.dataInfo.pos = Vector2Add(ball.dataInfo.pos, Vector2Scale(hitCollision.normal, hitCollision.penetrationDepth + 1.0f));
		if (hitCollision.normal.x > 0.5 || hitCollision.normal.x < -0.5)
		{
			ball.dataInfo.vel.x *= -1;
		}
		else
		{
			ball.dataInfo.vel.y *= -1;
		}
	}

	if (Bricks.size() > 0)
	{
		auto i = remove_if(Bricks.begin(), Bricks.end(),
			[&](BrickTiles* o)
			{
				return (o->deletable);
			}
		);

		if (i != Bricks.end())
		{
			Bricks.erase(i);
		}

		/*for (auto a : Bricks)
		{
			a->deletable = false;

			Bricks.push_back(a);
		}*/
	}
}

void Draw()
{

	BeginDrawing();
	ClearBackground(BLACK);


	//Map line.
	DrawLine(0, windowHeight - 100, windowWidth, windowHeight - 100, WHITE);
	topBorder.Draw(WHITE, true);
	leftBorder.Draw(WHITE, true);
	rightBorder.Draw(WHITE, true);
	bottomBorder.Draw(WHITE, false);

	player.Draw();
	ball.Draw();
	Vector2 MiddleOfBox = Vector2Add(player.dataInfo.pos, Vector2Divide(player.dataInfo.size, { 2,2 }));
	DrawCircleV(MiddleOfBox, 5, RED);
	
	DrawLineV(MiddleOfBox, ball.dataInfo.pos, RED);

	for (auto i : Bricks) i->Draw();

	DrawLineV(ball.dataInfo.pos, Vector2Add(ball.dataInfo.pos, Vector2Scale(hitCollision.normal, 50)), RED);

	EndDrawing();
}