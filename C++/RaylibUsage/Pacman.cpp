#include "Pacman.h"

//TODO - make another boxes around point but for the pallets instead and tie it to the score if you can



Pacman::Pacman()
{
}

Pacman::Pacman(MapGrid* _pacToMap)
{
	circle = CC({ screenWidth / 2, screenHeight / 2 }, 16.0f );
	dir = Right;
	currentFrame = 0;
	mouthOpenFrames = 5;
	
	velocity = 1.55f;
	score = 0;
	pacmanSprite = LoadTexture("./PacmanAssets/assets.png");
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
			brickColliding[i].TileCollision.Draw();
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

	mouthOpenFrames--;
	if (mouthOpenFrames == 0)
	{
		mouthOpenFrames = 10;
		//flips booleans
		currentFrame++;
		if (currentFrame > 4)
		{
			currentFrame = 1;
		}
	}
	float angle = 0;
	Rectangle source = { 488, 0, 15, 15 };
	Rectangle destPos = { circle.pos.x, circle.pos.y, 32,32 };
	if (currentFrame == 1)
	{
		source = { 488, 0, 15, 15 };
	}
	if (currentFrame == 2)
	{
		source = { 472, 0, 15, 15 };
	}
	if (currentFrame == 3)
	{
		source = { 456, 0, 15, 15 };
	}
	if (currentFrame == 4)
	{
		source = { 472, 0, 15, 15 };
	}
	
	switch (dir)
	{
	case Right:
		angle = 0;
		break;
	case Left:
		angle = 180;
		break;
	case Down:
		angle = 90;
		break;
	case Up:
		angle = 270;
		break;

	default:
		break;
	}

	DrawTexturePro(pacmanSprite, source, destPos, { circle.rad , circle.rad }, angle, WHITE);
	
	
}