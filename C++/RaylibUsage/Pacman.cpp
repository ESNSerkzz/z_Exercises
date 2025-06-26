#include "Pacman.h"
Pacman::Pacman() 
{
	box.halfSize = { 14,14 };
	box.pos = { screenWidth/2, screenHeight/2 };
	dir = Down;
	
	velocity = .55;
	score = 0;
}

void Pacman::Update() 
{
	bool canMove = false;
	if (IsKeyPressed(KEY_W)) dir = Up;
	if (IsKeyPressed(KEY_D)) dir = Right;
	if (IsKeyPressed(KEY_S)) dir = Down;
	if (IsKeyPressed(KEY_A)) dir = Left;
	
	if (canMove = true) 
	{
	switch (dir)
		{
		case Up:
			box.pos.y = box.pos.y - velocity;
			break;
		case Right:
			box.pos.x = box.pos.x + velocity;
			break;
		case Down:
			box.pos.y = box.pos.y + velocity;
			break;
		case Left:
			box.pos.x = box.pos.x - velocity;
		}
	}

	


	/*if (AABB::GetDir = true)
	{
		;
	}*/
	

}
//void Pacman::scoreAdder(int points)
//{
//	score = score + points;
//}
void Pacman::Draw()
{
	//Bootleg Pac-man
	DrawCircle(box.pos.x, box.pos.y, box.halfSize.x, YELLOW);

	DrawTriangle(Vector2{ box.pos }, Vector2{ box.pos  }, Vector2{ box.pos.x - 15, box.pos.y - 15 }, BLUE);
	//Pac-man mouth
}