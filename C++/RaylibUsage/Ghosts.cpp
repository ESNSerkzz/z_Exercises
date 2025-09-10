#include "Ghosts.h"

Ghosts::Ghosts()
{
}

Ghosts::Ghosts(AABB _box, GhostType _gType, MapGrid* _ghostToMap, std::string filePath)
{
	box = _box;
	dir = Right;
	velocity = 2.0f;
	currentFrame = 0;
	frameTimeLength = 5;
	gType = _gType;
	ghostToMap = _ghostToMap;
	
	ghostSprite =  LoadTexture(filePath.c_str());
	
	
	
	
}

void Ghosts::PathingMovement()
{
}

void Ghosts::Update()
{
	/*
	if ()
	{
		std::cout << "File Found And Open" << std::endl;
	}*/
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

	if (currentFrame == 1)
	{
		source = { 472, 64, 16, 16 };
	}

	DrawTexturePro(ghostSprite, source, destPos, box.halfSize, 0, WHITE);
	//DrawTexture(ghostSprite, box.pos.x, box.pos.y, WHITE);
}
