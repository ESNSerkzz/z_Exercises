#include "Pacman.h"

//TODO - make another boxes around point but for the pallets instead and tie it to the score if you can



Pacman::Pacman(MapGrid* _pacToMap)
{
	circle = CC({ screenWidth / 2, screenHeight / 2 }, 16.0f );
	dir = Right;
	mouthOpenFrames = 5;
	
	velocity = 1.55f;
	score = 0;
	pacToMap = _pacToMap;
}

void Pacman::Input()
{
	
	//if (IsKeyPressed(KEY_W)) dir = Up;; // || IsKeyDown(KEY_W)) dir = Up;
	//if (IsKeyPressed(KEY_D)) dir = Right;
	//if (IsKeyPressed(KEY_S)) dir = Down;
	//if (IsKeyPressed(KEY_A)) dir = Left;
	

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
		CollisionResults pacmanHitResult = { false, {0,0}, {50,50}, 0.0f };
		if (brickColliding[i].type == BRICK)
		{
			if (circle.isOverlapped(brickColliding[i].TileCollision, pacmanHitResult))
			{

				
				circle.pos = Vector2Subtract(circle.pos, Vector2Scale(pacmanHitResult.normal, pacmanHitResult.pDepth * -1));
				
				
				
			}
		}
		if (brickColliding[i].type == PALLETE || brickColliding[i].type == POWERPALLETE)
		{
			
			if (circle.isOverlapped(brickColliding[i].pallet->box, pacmanHitResult))
			{
				pacToMap->listOfTiles[brickColliding[i].x / 32][brickColliding[i].y/32].type = EMPTY;
				


				switch (brickColliding[i].pallet->pType)
				{
				case(Pallete):
					scoreAdder(10);
					break;

				case(PowerPallete):
					scoreAdder(50);
					break;
				case(Fruit):
					scoreAdder(100);
					break;
				default:
					break;
				}
			
				
			}

			
		}
	}


}

void Pacman::scoreAdder(int _score)
{
	score = score + _score;
}
void Pacman::Draw()
{
	//Bootleg Pac-man
	DrawCircle(circle.pos.x, circle.pos.y, circle.rad, YELLOW);
	circle.Draw();
	//Pac-man mouth

	


	mouthOpenFrames--;
	if (mouthOpenFrames == 0)
	{
		mouthOpenFrames = 20;
		//flips booleans
		mouthIsOpen = !mouthIsOpen;

	}

	if (mouthIsOpen)
	{
		switch (dir)
		{
		case Right:
			DrawTriangle(circle.pos, { circle.pos.x + circle.rad + 2 , circle.pos.y + 15 }, { circle.pos.x + circle.rad + 2, circle.pos.y - 15 }, BLACK);
			break;
		case Left:
			DrawTriangle(circle.pos,  { circle.pos.x - circle.rad - 2, circle.pos.y - 15 }, { circle.pos.x - circle.rad - 2 , circle.pos.y + 15 }, BLACK);
			break;
		case Down:
			DrawTriangle(circle.pos,  { circle.pos.x - 15 , circle.pos.y + circle.rad + 2}, { circle.pos.x + 15, circle.pos.y + circle.rad + 2 }, BLACK);
			break;
		case Up:
			DrawTriangle(circle.pos,  { circle.pos.x + 15, circle.pos.y - circle.rad - 2 }, { circle.pos.x - 15 , circle.pos.y - circle.rad - 2 }, BLACK);
			break;

		default:
			break;

		}

	}
	else;
}