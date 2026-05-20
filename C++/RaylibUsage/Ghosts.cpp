#include "Ghosts.h"

Ghosts::Ghosts()
{
}

Ghosts::Ghosts(CC _collision, GhostType _gType, MapGrid* _ghostToMap, std::string filePath, Pacman* _pacman, bool _debugState)
{
	collision = _collision;
	collision.pos.x += 16;
	dir = Up;
	velocity = speed;
	currentFrame = 0;
	frameTimeLength = 5;
	gType = _gType;
	ghostToMap = _ghostToMap;
	currentBehaviour = Behaviour::GAMESTART;
	pacman = _pacman;
	activeTarget = TileCoords(0, 0);
	scatterLoopIndex = 0;
	debugState = _debugState;
	

	switch (gType)
	{
	case RED_GHOST:
		
		scatterLoop.push_back(TileCoords(21, 4));
		scatterLoop.push_back(TileCoords(26, 4));
		scatterLoop.push_back(TileCoords(21, 8));

		break;
	case PINK_GHOST:
		
		scatterLoop.push_back(TileCoords(6, 4));
		scatterLoop.push_back(TileCoords(1, 4));
		scatterLoop.push_back(TileCoords(5, 8));

		break;
	case CYAN_GHOST:

		scatterLoop.push_back(TileCoords(6, 26));
		scatterLoop.push_back(TileCoords(1, 32));
		scatterLoop.push_back(TileCoords(12, 32));

		break;
	case ORANGE_GHOST:

		scatterLoop.push_back(TileCoords(21, 26));
		scatterLoop.push_back(TileCoords(26, 32));
		scatterLoop.push_back(TileCoords(15, 32));

		break;
	}
	ghostSprite = LoadTexture(filePath.c_str());
	
}

void Ghosts::Update(float delta)
{
	
	TileCoords ghostCoords = ghostToMap->GetCoordsV({ collision.pos.x, collision.pos.y});
	TileCoords targetTile;
	TileCoords TileInFrontOfPacman;
	
	
		switch (currentBehaviour)
		{

		case Behaviour::SCATTER:

			if (path.size() < 2)
			{
				scatterLoopIndex++;

				if (scatterLoopIndex >= scatterLoop.size())
				{
					scatterLoopIndex = 0;
				}
			}
			targetTile = scatterLoop[scatterLoopIndex];



			break;

		case Behaviour::CHASE:


			switch (gType)
			{
			case RED_GHOST:
				targetTile = ghostToMap->GetCoordsV(pacman->circle.pos);

				break;
			case PINK_GHOST:

				if (pacman->dir == Right)
				{
					targetTile = ghostToMap->GetCoordsV(pacman->circle.pos) + TileCoords(2, 0);
				}
				if (pacman->dir == Left)
				{
					targetTile = ghostToMap->GetCoordsV(pacman->circle.pos) + TileCoords(-2, 0);
				}
				if (pacman->dir == Down)
				{
					targetTile = ghostToMap->GetCoordsV(pacman->circle.pos) + TileCoords(0, 2);
				}
				if (pacman->dir == Up)
				{
					targetTile = ghostToMap->GetCoordsV(pacman->circle.pos) + TileCoords(-2, -2);
				}
				targetTile = ghostToMap->GetTileCoords(ghostToMap->closestEmptyTile(targetTile));
				break;

			case CYAN_GHOST:

				TileInFrontOfPacman = ghostToMap->GetCoordsV(pacman->circle.pos);

				if (pacman->dir == Right)
				{
					TileInFrontOfPacman.x += 2;
				}
				else if (pacman->dir == Left)
				{
					TileInFrontOfPacman.x -= 2;
				}
				if (pacman->dir == Up)
				{
					TileInFrontOfPacman.x -= 2;
					TileInFrontOfPacman.y -= 2;
				}
				else if (pacman->dir == Down)
				{
					TileInFrontOfPacman.y += 2;
				}


				targetTile = TileInFrontOfPacman - ghostToMap->GetCoordsV(redGhost->collision.pos);
				targetTile.Invert();
				targetTile = TileInFrontOfPacman - targetTile;

				/*if (targetTile.x > ghostToMap->columns -1)
				{
					targetTile.x = ghostToMap->columns - 2;
				}
				if(targetTile.x < 1)

				{
					targetTile.x = 1;
				}
				if (targetTile.y > ghostToMap->rows - 3)
				{
					targetTile.y = ghostToMap->rows - 4;
				}
				if (targetTile.y < 4)
				{
					targetTile.y = 4;
				}*/

				targetTile = ghostToMap->GetTileCoords(ghostToMap->closestEmptyTile(targetTile));


				break;


			case ORANGE_GHOST:

				//if within an 8 tile raduis
				if (Vector2Distance(collision.pos, pacman->circle.pos) >= 32 * 8)
				{
					targetTile = ghostToMap->GetCoordsV(pacman->circle.pos);

				}
				else
				{
					targetTile = TileCoords(26, 32);
				}

			default:
				break;
			}

		case Behaviour::FRIGHTENED:
			


			break;
		default:
			break;


		}
	
	
	

	if (path.size() > 1)
	{
		
		Vector2 ghostDistToTile = Vector2Subtract(Vector2Add(ghostToMap->VposToCoords(path[1]), {16,16}), collision.pos);
		//Vector2 ghostDistToTile = Vector2Subtract(ghostToMap->VposToCoords(path[1]), Vector2Add(collision.pos, {16, 16}));

		TileCoords pathDir;
		//the paths order is backwards
		pathDir.x = path[1].x - path[0].x;
		pathDir.y = path[1].y - path[0].y; 
		if (std::abs(ghostDistToTile.y) >= std::abs(ghostDistToTile.x))
		{
			if (ghostDistToTile.y < 0)
			{
				dir = Up;

			}
			else 
			{
				dir = Down;
			}

		}
		else
		{
			if (ghostDistToTile.x < 0)
			{
				dir = Left;

			}
			else
			{
				dir = Right;
			}
		}

		

		if (Vector2Distance(collision.pos, Vector2Add(ghostToMap->VposToCoords(path[1]), {16,16})) <= 8)
		{

			path.erase(path.begin());
		}

		//std::cout << "GhostDistTotile: " << ghostDistToTile.x << " " << ghostDistToTile.y << std::endl;
	}
	if (currentBehaviour == Behaviour::GAMESTART)
	{

		return;
	}

	switch (dir)
	{
	case Up:
		collision.pos.y = collision.pos.y - velocity * delta;
		break;
	case Down: 
		collision.pos.y = collision.pos.y + velocity * delta;
		break;
	case Left:
		collision.pos.x = collision.pos.x - velocity * delta;
		break;
	case Right:
		collision.pos.x = collision.pos.x + velocity * delta;
		break;

	}
	if (collision.pos.x < 0)
	{
		collision.pos.x = screenWidth;
	}
	if (collision.pos.x > screenWidth)
	{
		collision.pos.x = 0;
	}

	if (collision.pos.y < 0)
	{
		collision.pos.y = screenHeight;
	}
	if (collision.pos.y > screenHeight)
	{
		collision.pos.y = 0;
	}

	HandleCollisions();

	currentTileCoord = ghostToMap->GetCoordsV(collision.pos);
	if (activeTarget == targetTile)
	{

		return;
	}

	activeTarget = targetTile;
	path = ghostToMap->dijkstrasPathing(ghostToMap->GetCoordsV(collision.pos), targetTile);

}

void Ghosts::Draw()
{

	float topPos;
	if (gType == RED_GHOST) topPos = 64;
	if (gType == PINK_GHOST) topPos = 80;
	if (gType == CYAN_GHOST) topPos = 96;
	if (gType == ORANGE_GHOST) topPos = 112;
	frameTimeLength--;
	if (frameTimeLength == 0)
	{
		frameTimeLength = 10;
		currentFrame++;
		if(currentFrame > 1 && currentBehaviour != Behaviour::FRIGHTENED)
		{
			currentFrame = 0;
		}
		if (currentBehaviour == Behaviour::FRIGHTENED && currentFrame > 3)
		{

			currentFrame = 0;
		}
	}
	Rectangle source = {456, 64, 16, 16 };
	Rectangle destPos = { collision.pos.x, collision.pos.y, 32,32 };

	
	
		switch (dir)
		{
		case Right:
			if (currentFrame == 0)
			{
				source = { 456, topPos, 16, 16 };
			}
			if (currentFrame == 1)
			{
				source = { 472, topPos, 16, 16 };
			}
			break;
		case Left:
			if (currentFrame == 0)
			{
				source = { 488, topPos, 16, 16 };
			}
			if (currentFrame == 1)
			{
				source = { 504, topPos, 16, 16 };
			}
			break;
		case Up:
			if (currentFrame == 0)
			{
				source = { 520, topPos, 16, 16 };
			}
			if (currentFrame == 1)
			{
				source = { 536, topPos, 16, 16 };
			}
			break;
		case Down:
			if (currentFrame == 0)
			{
				source = { 552, topPos, 16, 16 };
			}
			if (currentFrame == 1)
			{
				source = { 568, topPos, 16, 16 };
			}
			break;
		}
		if (currentBehaviour == Behaviour::FRIGHTENED)
		{
			source = { (float)584 + (currentFrame * 16), 64, 16, 16 };
		}
	ghostToMap->DrawBox(currentTileCoord.x, currentTileCoord.y);

	DrawTexturePro(ghostSprite, source, destPos, { collision.rad, collision.rad }, 0, WHITE);
		if (!debugState) return;
	for (int i = 0; i < path.size(); i++)
	{
		ghostToMap->GetTile(path[i]).DrawTile(GREEN);
		
		
		if (path[i] == path.back())
		{
			ghostToMap->GetTile(path[i]).DrawTile(YELLOW);
		}

	}
	

	collision.Draw();
	//DrawTexture(ghostSprite, box.pos.x, box.pos.y, WHITE);
	if (gType == CYAN_GHOST) 
	{
		DrawLineV(collision.pos, ghostToMap->VposToCoords(activeTarget), RED);

	}
}

void Ghosts::HandleCollisions()
{
	std::vector<Tile> CollideableBricks = ghostToMap->BoxesAroundPoint(collision.pos);
	CollisionResults hitResult;

	for (auto brick : CollideableBricks)
	{
		if (brick.type == BRICK)
		{
			if (collision.isOverlapped(brick.TileCollision, hitResult))
			{
				collision.pos = Vector2Subtract(collision.pos, Vector2Scale(hitResult.normal, hitResult.pDepth * -1));
			}
		}
	}

}
