#include "Trail.h"


trail::trail()
{
	maxSize = BulletStreamLength;
	startColour = 0x33FFA2FF;
	endColour = 0x0991E9FF;
}

trail::trail(int max_Size, uint32_t Colour_A, uint32_t Colour_B)
{
	maxSize = max_Size;
	startColour = Colour_A;
	endColour = Colour_B;
}

trail::~trail()
{
}

void trail::draw()
{
	
	
	for (int i = 0; i < points.size(); i++)
	{
		int j = (i + 1);
		
		if (j < points.size())
		{
			if (Vector2Distance(points[i], points[j]) > 100)
			{
				continue;
			}

			int fadeOff = ((points.size() - i) - 1) * (255 - 1) / (points.size() - 1);


			DrawLine
			(
				points[i].x,
				points[i].y,
				points[j].x,
				points[j].y,
				{ 0,0,255, (unsigned char)(fadeOff) }

			);

		}

	}
}

void trail::insert(Vector2 pos)
{

	points.insert(points.begin(), pos);

	if (points.size() > maxSize)
	{
		points.pop_back();
	}
}
