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

//std::vector<tileCoords> Ghosts::dijkstra(tileCoords _targetPos)
//{
//	std::vector<Tile> tilePath;
//	
//	
//}

void Ghosts::PathingMovement()
{
}

void Ghosts::Update(float delta)
{
	tileCoords pacmanCoords = { (int)pacman->circle.pos.x /32, (int)pacman->circle.pos.y/32 };
	std::vector<tileCoords> path = ghostToMap->dijkstrasPathing(
		{ (int)box.pos.x / 32, (int)box.pos.y / 32 },
		pacmanCoords
	);

	for (int i = 0 ; i < path.size(); i++)
	{
		ghostToMap->listOfTiles[path[i].x][path[i].y].TileCollision.Draw();
		
	}

	switch (currentBehaviour)
	{
	case SCATTER:
		switch (gType)
		{
		case RED_GHOST:
			//TODO walk to 26 , 4
			break;
		default:
			break;
		}

		break;
	default:
		break;
	}
}

void Ghosts::Draw()
{
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
	Rectangle destPos = { box.pos.x, box.pos.y, 32,32 };

	switch (gType)
	{
	case RED_GHOST:
		switch (dir)
		{
		case Right:
			if (currentFrame == 0)
			{
				source = { 456, 64, 16, 16 };
			}
			if (currentFrame == 1)
			{
				source = { 472, 64, 16, 16 };
			}
			break;
		case Left:
			if (currentFrame == 0)
			{
				source = { 488, 64, 16, 16 };
			}
			if (currentFrame == 1)
			{
				source = { 504, 64, 16, 16 };
			}
			break;
		case Up:
			if (currentFrame == 0)
			{
				source = { 520, 64, 16, 16 };
			}
			if (currentFrame == 1)
			{
				source = { 536, 64, 16, 16 };
			}
			break;
		case Down:
			if (currentFrame == 0)
			{
				source = { 552, 64, 16, 16 };
			}
			if (currentFrame == 1)
			{
				source = { 568, 64, 16, 16 };
			}
			break;
		}
	case PINK_GHOST:
		switch (dir)
		{
		case Right:
			if (currentFrame == 0)
			{
				source = { 456, 80, 16, 16 };
			}
			if (currentFrame == 1)
			{
				source = { 472, 80, 16, 16 };
			}
			break;
		case Left:
			if (currentFrame == 0)
			{
				source = { 488, 80, 16, 16 };
			}
			if (currentFrame == 1)
			{
				source = { 504, 80, 16, 16 };
			}
			break;
		case Up:
			if (currentFrame == 0)
			{
				source = { 520, 80, 16, 16 };
			}
			if (currentFrame == 1)
			{
				source = { 536, 80, 16, 16 };
			}
			break;
		case Down:
			if (currentFrame == 0)
			{
				source = { 552, 80, 16, 16 };
			}
			if (currentFrame == 1)
			{
				source = { 568, 80, 16, 16 };
			}
			break;
		}
	case CYAN_GHOST:
		switch (dir)
		{
		case Right:
			if (currentFrame == 0)
			{
				source = { 456, 96, 16, 16 };
			}
			if (currentFrame == 1)
			{
				source = { 472, 96, 16, 16 };
			}
			break;
		case Left:
			if (currentFrame == 0)
			{
				source = { 488, 96, 16, 16 };
			}
			if (currentFrame == 1)
			{
				source = { 504, 96, 16, 16 };
			}
			break;
		case Up:
			if (currentFrame == 0)
			{
				source = { 520, 96, 16, 16 };
			}
			if (currentFrame == 1)
			{
				source = { 536, 96, 16, 16 };
			}
			break;
		case Down:
			if (currentFrame == 0)
			{
				source = { 552, 96, 16, 16 };
			}
			if (currentFrame == 1)
			{
				source = { 568, 96, 16, 16 };
			}
			break;
		}
	case ORAGANE_GHOST:
		switch (dir)
		{
		case Right:
			if (currentFrame == 0)
			{
				source = { 456, 112, 16, 16 };
			}
			if (currentFrame == 1)
			{
				source = { 472, 112, 16, 16 };
			}
			break;
		case Left:
			if (currentFrame == 0)
			{
				source = { 488, 112, 16, 16 };
			}
			if (currentFrame == 1)
			{
				source = { 504, 112, 16, 16 };
			}
			break;
		case Up:
			if (currentFrame == 0)
			{
				source = { 520, 112, 16, 16 };
			}
			if (currentFrame == 1)
			{
				source = { 536, 112, 16, 16 };
			}
			break;
		case Down:
			if (currentFrame == 0)
			{
				source = { 552, 112, 16, 16 };
			}
			if (currentFrame == 1)
			{
				source = { 568, 112, 16, 16 };
			}
			break;
		}
		/*if (currentFrame = 1)
		{
			switch (dir)
			{
			case Right:
				source = { 472, 64, 16, 16 };
				break;
			case Left:
			}
		}
		break;*/
	}

	DrawTexturePro(ghostSprite, source, destPos, box.halfSize, 0, WHITE);
	//DrawTexture(ghostSprite, box.pos.x, box.pos.y, WHITE);
}
