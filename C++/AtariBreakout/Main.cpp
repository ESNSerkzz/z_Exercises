#include "raylib.h"
#include "raymath.h"
#include "Ball.h"
#include "BrickTiles.h"
#include "Paddle.h"
#include "Constants.h"
#include "iostream"
#include <fstream>
#include <string>
#include <vector>

std::ifstream mapFile;

std::vector<BrickTiles*>  LoadBricks(Vector2 topLeftCorner, Vector2 bottomRightCorner, const char* string);
void ReloadMap();
static void SetUp();
static void Update(float delta);
static void Collide(float delta);
static void Draw();

Paddle player = Paddle();
//Ball ball = Ball();

hitResult hitCollision;
Ball ball = Ball({ 0.0f, 200.0f });
std::vector <BrickTiles*> Bricks;


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
	int columns = 0;
	int row = 0;
	Vector2 BrickSize = {0, 1};
	
	for (int i = 0; i < (unsigned)strlen(_string); i++)
	{
		if (_string[i] == '\n' || _string[i] == '\0')
		{
			std::cout << std::endl << i << std::endl;
			BrickSize.x = (_bottomRightCorner.x - _topLeftCorner.x)/ i;
			BrickSize.y = (_bottomRightCorner.y - _topLeftCorner.y) / (strlen(_string) / (i + 1));
			columns = (i + 1);
			break;
		}
	}
	std::cout << "BrickSize x " << BrickSize.x << "\n" << "BrickSize y " << BrickSize.y << "\n";

	for (int i = 0; i < (unsigned)strlen(_string); i++)
	{
		if (_string[i] != '\n' && _string[i] != '\0')
		{
			if (_string[i] == '1')
			{
				returnBricks.push_back(new BrickTiles(
					{
						(_topLeftCorner.x + i * BrickSize.x) - (row * BrickSize.x * columns) ,
						_topLeftCorner.y + (row * BrickSize.y)
					},
					Vector2Subtract(BrickSize, { gapBetween, gapBetween })
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
	ReloadMap();
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
		
		Vector2 MiddleOfBox = Vector2Add(player.dataInfo.pos, Vector2Divide(player.dataInfo.size, { 2,2 }));
		Vector2 BoxToBallNormalise = Vector2Subtract(ball.dataInfo.pos, MiddleOfBox);
		BoxToBallNormalise = Vector2Normalize(BoxToBallNormalise);

	
		ball.dataInfo.vel = Vector2Scale(BoxToBallNormalise, Vector2Length(ball.dataInfo.vel));
	}

	for (auto i : Bricks)
	{
		if (ball.ballCollision.isOverlapped(i->BrickCollision, hitCollision)) 
		{
			if (Bricks.size() == 1)
			{
				ball.SetVel({ 0.0f, 250.0f });
				ball.ResetPos();
				player.AddScorePoints(150);
				ReloadMap();
			}

			ball.dataInfo.pos = Vector2Add(ball.dataInfo.pos, Vector2Scale(hitCollision.normal, hitCollision.penetrationDepth + 1.0f));
			player.AddScorePoints(25);
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
		ball.dataInfo.pos = { windowWidth / 2, windowHeight / 2 + 50 };
		player.playerScore = 0;
		ReloadMap();
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
	

	for (auto i : Bricks) i->Draw();

	

	DrawText(TextFormat("Score: %02i", player.playerScore), windowWidth/2 - 50, windowHeight - 50, 50, BLUE);

	EndDrawing();
}

void ReloadMap()
{
	srand(time(NULL));

	std::string mapFileName = "AtariMaps/map_";
	mapFileName.append(std::to_string((std::rand() % 3) + 1));
	mapFileName.append(".txt");
	

	mapFile = std::ifstream(mapFileName);

	std::string tempText;
	std::string brickMap;

	while (getline(mapFile, tempText))
	{
		std::cout << tempText << '\n';
		brickMap.append(tempText);
		brickMap.append(std::string("\n"));


	}


	Bricks = LoadBricks({ 50, 50 }, { windowWidth - 50, 500 }, brickMap.c_str());
}