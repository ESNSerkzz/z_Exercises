#include "Finngine.h"
#include "CollisionFunctions.h"

Finngine::Finngine()
{
	things.push_back(Thing(1, 2));

	things.push_back(Thing(-4, 1));
	things.push_back(Thing(-3, 1));
	things.push_back(Thing(-6, 4));
	things.push_back(Thing(1, 1));

	things[0].radius = 0.5f;
	things[1].radius = 1.5f;

}


void Finngine::Update(float delta)
{
	things[0].position = cursorPos;


	for (int iteration = 0; iteration < 10; iteration++)
	{
		std::vector<CollisionData> collisionDatums;
		for (int i = 0; i < things.size(); i++)
		{
			for (int j = i + 1; j < things.size(); j++)
			{
				collisionDatums.push_back(GetCollision(things[i], things[j]));
			}
		}
		for (CollisionData& thisData : collisionDatums)
		{
			thisData.PerformDepenetrationStep();
		}
	}


	for (Thing& thing : things)
	{
		thing.Update(delta);
	}

	
	

	for (Thing& thing : things)
	{
		thing.Draw(lines);
	}
}

void Finngine::OnLeftClick()
{
	things.push_back(Thing(cursorPos.x+0.1f, cursorPos.y));
}