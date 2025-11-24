#include "Ghosts.h"

Ghosts::Ghosts()
{
}

Ghosts::Ghosts(CC _collision, GhostType _gType, MapGrid* _ghostToMap, std::string filePath)
{
	collision = _collision;
	dir = Up;
	velocity = speed;
	currentFrame = 0;
	frameTimeLength = 5;
	gType = _gType;
	ghostToMap = _ghostToMap;
	currentBehaviour = CHASE;
	
	ghostSprite =  LoadTexture(filePath.c_str());
	
}

void Ghosts::Update(float delta)
{
	
	tileCoords ghostCoords = ghostToMap->GetCoords({ collision.pos.x, collision.pos.y});
	
	switch (currentBehaviour)
	{
	case SCATTER:
		switch (gType)
		{
		case RED_GHOST:
			//TODO walk to 26 , 4
			path = ghostToMap->dijkstrasPathing(ghostCoords, { 26, 5 });
			break;

		case PINK_GHOST:
			path = ghostToMap->dijkstrasPathing(ghostCoords, { 2,5 });
			break;
		case CYAN_GHOST:
			path = ghostToMap->dijkstrasPathing(ghostCoords, { 2, 32 });
			break;
		case ORANGE_GHOST:
			path = ghostToMap->dijkstrasPathing(ghostCoords,{ 26, 32 });
			break;
		default:
			break;
		}

		break;

	case CHASE:


		switch (gType)
		{
		case RED_GHOST:
			path = ghostToMap->dijkstrasPathing(ghostToMap->GetCoords(collision.pos), ghostToMap->GetCoords(pacman->circle.pos));
			break;
		case PINK_GHOST:
			if (pacman->dir == Right)
			path = ghostToMap->dijkstrasPathing(ghostToMap->GetCoords(collision.pos), ghostToMap->GetCoords(pacman->circle.pos));
			break;
		case CYAN_GHOST:
			path = ghostToMap->dijkstrasPathing(ghostToMap->GetCoords(collision.pos), ghostToMap->GetCoords(pacman->circle.pos));
			break;
		case ORANGE_GHOST:
			path = ghostToMap->dijkstrasPathing(ghostToMap->GetCoords(collision.pos), ghostToMap->GetCoords(pacman->circle.pos));
		default:
			break;
		}

		break;
	default:
		break;
	}


	if (path.size() > 1)
	{
		
		Vector2 ghostDistToTile = Vector2Subtract(Vector2Add(ghostToMap->posToCoords(path[1]), {16,16}), collision.pos);
		tileCoords pathDir;
		//the paths order is backwards
		pathDir.x = path[1].x - path[0].x;
		pathDir.y = path[1].y - path[0].y; 
		if (std::abs(ghostDistToTile.y) > std::abs(ghostDistToTile.x))
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

	HandleColisions();
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
		frameTimeLength = 50;
		currentFrame++;
		if(currentFrame > 1)
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

	for (int i = 0; i < path.size(); i++)
	{
		ghostToMap->GetTile(path[i]).DrawTile();
		

	}
	
	DrawTexturePro(ghostSprite, source, destPos, { collision.rad, collision.rad }, 0, WHITE);
	collision.Draw();
	//DrawTexture(ghostSprite, box.pos.x, box.pos.y, WHITE);
}

void Ghosts::HandleColisions()
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
