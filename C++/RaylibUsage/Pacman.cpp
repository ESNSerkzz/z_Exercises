#include "Pacman.h"

//TODO - make another boxes around point but for the pallets instead and tie it to the score if you can



Pacman::Pacman()
{
}

Pacman::Pacman(MapGrid* _pacToMap)
{
	circle = CC({ 13.5*32, 20.5*32 }, 16.0f );
	dir = Right;
	currentFrame = 0;
	mouthOpenFrames = 5;
	
	velocity = speed;
	score = 0;
	pacmanSprite = LoadTexture("./PacmanAssets/assets.png");
	pacToMap = _pacToMap;
	isControllable = false;
	powerTimeRemaining = -1;
}

void Pacman::Input()
{
	
	int posX = circle.pos.x / 32;
	int posY = circle.pos.y / 32;
	
	if (isControllable == false)
		return;


	if (IsKeyDown(KEY_W))
	{
		//std::cout << "size X of map: " << sizeof(pacToMap->listOfTiles) << std::endl;
		if (posY - 1 >= 0 && posX >= 0 && posX + 1 < pacToMap->columns)
		{
			if (pacToMap->listOfTiles[posX][posY - 1].type != BRICK)
			{
				dir = Up;
			}
		}
		
	}

	if (IsKeyDown(KEY_D))
	{
		//std::cout << "type: " << pacToMap->listOfTiles[posX + 1][posY].type << std::endl;
		if (posX + 1 < pacToMap->columns)
		{
			if (pacToMap->listOfTiles[posX + 1][posY].type != BRICK)
			{
				dir = Right;
			}
		}
		
	}
	if (IsKeyDown(KEY_S))
	{
		if (posY + 1 < pacToMap->rows && posX >= 0 && posX + 1 < pacToMap->columns)
		{
			if (pacToMap->listOfTiles[posX][posY + 1].type != BRICK)
			{

				dir = Down;
			}
		}
		
	}
	if (IsKeyDown(KEY_A))
	{
		if (posX - 1 >= 0)
		{
			if (pacToMap->listOfTiles[posX - 1][posY].type != BRICK)
			{

				dir = Left;
			}
		}
		
	}
	
}
void Pacman::Update(float delta)
{

	if (isControllable == false)
		return;

	switch (dir)
	{
	case Up:
		circle.pos.y = circle.pos.y -= velocity * delta;
		//box.GetDir(box.pos);
		break;
	case Right:
		circle.pos.x = circle.pos.x += velocity * delta;
		break;
	case Down:
		circle.pos.y = circle.pos.y += velocity * delta;
		break;
	case Left:
		circle.pos.x = circle.pos.x -= velocity * delta;
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
			
			if (circle.isOverlapped(brickColliding[i].pallet->collision, pacmanHitResult))
			{
				pacToMap->listOfTiles[brickColliding[i].x / 32][brickColliding[i].y/32].type = EMPTY;
				
				switch (brickColliding[i].pallet->pType)
				{
				case(Pallete):
					pacToMap->pallatesRemaining--;
					scoreAdder(10);
					break;

				case(PowerPallete):
					pacToMap->pallatesRemaining--;
					scoreAdder(50);
					powerTimeRemaining = 6.00f;

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
	currentTileCoord = pacToMap->GetCoordsV(circle.pos);

	if (powerTimeRemaining > 0.0f)
	{
		powerTimeRemaining -= delta;
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
		mouthOpenFrames = 5;
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
	//circle.Draw();
}