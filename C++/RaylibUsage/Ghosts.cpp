#include "Ghosts.h"

Ghosts::Ghosts()
{
}

Ghosts::Ghosts(AABB _box, GhostType _gType, MapGrid* _ghostToMap, std::string filePath)
{
	box = _box;
	dir = Up;
	velocity = 2.0f;
	currentFrame = 0;
	frameTimeLength = 5;
	gType = _gType;
	ghostToMap = _ghostToMap;
	currentBehaviour = SCATTER;
	
	ghostSprite =  LoadTexture(filePath.c_str());
	
}

void Ghosts::Update(float delta)
{
	
	tileCoords ghostCoords = ghostToMap->GetCoords({ box.pos.x, box.pos.y + 48 });
	
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
			path = ghostToMap->dijkstrasPathing(ghostToMap->GetCoords(box.pos), ghostToMap->GetCoords(pacman->circle.pos));
			break;
		case PINK_GHOST:
			if (pacman->dir == Right)
			path = ghostToMap->dijkstrasPathing(ghostToMap->GetCoords(box.pos), ghostToMap->GetCoords(pacman->circle.pos));
			break;
		case CYAN_GHOST:
			//path = ghostToMap->dijkstrasPathing(ghostToMap->GetCoords(box.pos), { 2, 32 });
			break;
		case ORANGE_GHOST:
			//path = ghostToMap->dijkstrasPathing(ghostToMap->GetCoords(box.pos), { 26, 32 });
		default:
			break;
		}

		break;
	default:
		break;
	}


	if (path.size() > 1)
	{
		
		Vector2 ghostDistToTile = Vector2Subtract(ghostToMap->tileToPos(path[1]), box.pos);
		tileCoords pathDir;
		//the paths order is backwards
		pathDir.x = path[1].x - path[0].x;
		pathDir.y = path[1].y - path[0].y; 
		if (std::abs(ghostDistToTile.y) > std::abs(ghostDistToTile.x))
		{
			if (ghostDistToTile.y <= 0)
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
			if (ghostDistToTile.x <= 0)
			{
				dir = Left;

			}
			else
			{
				dir = Right;
			}
		}

		/*if (pathDir.x == 0 && pathDir.y == 1)
		{
			dir = Down;
		}
		if (pathDir.x == -1 && pathDir.y == 0)
		{
			dir = Left;
		}
		if (pathDir.x == 1 && pathDir.y == 0)
		{
			dir = Right;
		}*/

	}


	switch (dir)
	{
	case Up:
		box.pos.y = box.pos.y - velocity;
		break;
	case Down: 
		box.pos.y = box.pos.y + velocity;
		break;
	case Left:
		box.pos.x = box.pos.x - velocity;
		break;
	case Right:
		box.pos.x = box.pos.x + velocity;
		break;

	}

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
	Rectangle destPos = { box.pos.x + box.halfSize.x, box.pos.y + box.halfSize.y, 32,32 };

	
	
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
	
	DrawTexturePro(ghostSprite, source, destPos, box.halfSize, 0, WHITE);
	box.Draw();
	//DrawTexture(ghostSprite, box.pos.x, box.pos.y, WHITE);
}

void Ghosts::HandleColisions()
{
	std::vector<Tile> CollideableBricks = ghostToMap->BoxesAroundPoint(box.pos);
	
	for (auto brick : CollideableBricks)
	{

	}

}
