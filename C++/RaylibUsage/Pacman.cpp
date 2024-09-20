#include "Pacman.h"
Pacman::Pacman() 
{
	box.halfSize = { 50,50 };
	box.pos = { 130, 150 };
	dir = Down;
	
	speed = .55;
	score = 0;
}

void Pacman::Update(bool canMove) 
{
	if (canMove) 
	{
	switch (dir)
		{
		case Up:
			box.pos.y = box.pos.y - speed;
			break;
		case Right:
			box.pos.x = box.pos.x + speed;
			break;
		case Down:
			box.pos.y = box.pos.y + speed;
			break;
		case Left:
			box.pos.x = box.pos.x - speed;
		}
	}

	

	if (IsKeyDown(KEY_W)) dir = Up;
	if (IsKeyDown(KEY_D)) dir = Right;
	if (IsKeyDown(KEY_S)) dir = Down;
	if (IsKeyDown(KEY_A)) dir = Left;

	/*if (AABB::GetDir = true)
	{
		;
	}*/
	

}
void Pacman::scoreAdder(int points)
{
	score = score + points;
}
void Pacman::Draw() 
{
	//Bootleg Pac-man
	DrawCircle(box.pos.x, box.pos.y, box.halfSize.x, YELLOW);
	//Pac-man mouth
	//DrawTriangle(Vector2{ 100, 200 }, Vector2{ 300, 400 }, Vector2{ 500, 600 }, RED);
}