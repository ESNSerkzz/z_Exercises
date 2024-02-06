#include "Engine.h"
#include "CollisionFunctions.h"

Engine::Engine() 
{
	things.push_back(Thing(1, 2));

	things.push_back(Thing(-4, 1));
	things.push_back(Thing(-3, 1));
	things.push_back(Thing(-6, 4));
	things.push_back(Thing(1, 1));

	things[0].radius = 0.5f;
	things[1].radius = 1.5f;
}

void Engine::Update(float delta) 
{
	// whereever the position of the mouse cusor is, thing will copy and follow its position.
	things[0].position = cursorPos;



	// just iterating it and looping its ten times.
	for (int iteration = 0; iteration < 10; iteration++)
	{
		/* making a vector / array / list about the position / instances of collision data.
		now its put into a "container" named collisionDatums that loops it, each times until it reaches the end of thing's array size. */
		std::vector<CollisionData> collisionDatums;
		for (int i = 0; i < things.size(); i++)
		{
			// continuing form the CollisionData's vector/ list. J starts one number down the list from "I" and counts onwards until is reaches the end of list size of "things"
			for (int j = i + 1; j < things.size(); j++)
			{
				//push_back goes to a previous spot on the vector list.
				//pushback is self explanatory. it actually pushes away from a collision detected.
				
				// ...! push_back compares thins1 and thing2's overlapAmount from GetCollision...unsure.
				collisionDatums.push_back(GetCollision(things[i], things[j]));
			}
		}
		for (CollisionData& thisData : collisionDatums)
		{
			thisData.PerformDepenetrationStep();
		}
	}

	// updating things actions/ data/ info, every frame
	for (Thing& thing : things)
	{
		thing.Update(delta);
	}

	// represents and draws on screen
	for (Thing& thing : things)
	{
		thing.Draw(lines);
	}
}

void Engine::OnLeftClick()
{
	things.push_back(Thing(cursorPos.x+0.1f, cursorPos.y));
}