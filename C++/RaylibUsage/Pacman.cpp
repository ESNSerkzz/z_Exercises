#include "Pacman.h"

Pacman::Pacman(MapGrid* _pacToMap)
{
	circle = CC({ screenWidth / 2, screenHeight / 2 }, 14.0f );
	dir = Down;
	
	velocity = 5.55f;
	score = 0;
	pacToMap = _pacToMap;

}

void Pacman::Input()
{
	
	/*if (IsKeyPressed(KEY_W) || IsKeyDown(KEY_W)) dir = Up;
	if (IsKeyPressed(KEY_D)) dir = Right;
	if (IsKeyPressed(KEY_S)) dir = Down;
	if (IsKeyPressed(KEY_A)) dir = Left;*/
	//if (IsKeyDown(KEY_D)) dir = Right;

	if (IsKeyDown(KEY_W)) dir = Up;
	if (IsKeyDown(KEY_D)) dir = Right;
	if (IsKeyDown(KEY_S)) dir = Down;
	if (IsKeyDown(KEY_A)) dir = Left;
	
}
void Pacman::Update()
{
	bool canMove = true;
	if (canMove == true)
	{
		switch (dir)
		{
		case Up:
			circle.pos.y = circle.pos.y -= velocity;
			//box.GetDir(box.pos);
			break;
		case Right:
			circle.pos.x = circle.pos.x += velocity;
			break;
		case Down:
			circle.pos.y = circle.pos.y += velocity;
			break;
		case Left:
			circle.pos.x = circle.pos.x -= velocity;
		}
	}
	if (circle.pos.x < 0)
	{
		circle.pos.x = screenWidth;
	}
	if (circle.pos.x > screenWidth)
	{
		circle.pos.x = 0;
	}

	if (circle.pos.y < 0)
	{
		circle.pos.y = screenHeight;
	}
	if (circle.pos.y > screenHeight)
	{
		circle.pos.y = 0;
	}

	
	std::vector<Tile> brickColliding = pacToMap->BoxesAroundPoint(circle.pos);
	
	for (int i = 0; i < brickColliding.size(); i++)
	{
		if (brickColliding[i].type == BRICK)
		{
			CollisionResults pacmanHitResult = { false, {0,0}, {50,50}, 0.0f };
			if (circle.isOverlapped(brickColliding[i].TileCollision, pacmanHitResult))
			{

				brickColliding[i].TileCollision.Draw();
				circle.pos = Vector2Subtract(circle.pos, Vector2Scale(pacmanHitResult.normal, pacmanHitResult.pDepth * -1));
				DrawCircleLinesV(circle.pos, 0.5f, RED);
				DrawLineV(Vector2Add(Vector2Scale (pacmanHitResult.normal, 50), pacmanHitResult.pos), pacmanHitResult.pos , GREEN);
				
				//the pDepth. have a look at pongs and atariBreakout and compare/ 
			}
		}
	}


}
//void Pacman::scoreAdder(int points)
//{
//	score = score + points;
//}
void Pacman::Draw()
{
	//Bootleg Pac-man
	DrawCircle(circle.pos.x, circle.pos.y, circle.rad, YELLOW);
	circle.Draw();
	DrawTriangle(Vector2{ circle.pos }, Vector2{ circle.pos  }, Vector2{ circle.pos.x - 15, circle.pos.y - 15 }, BLUE);
	//Pac-man mouth
}