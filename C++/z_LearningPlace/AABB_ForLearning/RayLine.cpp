#include "RayLine.h"

RayLine::RayLine()
{
}

RayLine::RayLine(Vector2 start, Vector2 rayDir)
{
	ray_SP = start;
	ray_dir = rayDir;
}

void RayLine::Draw(Color c)
{
	DrawLineV(ray_SP, Vector2Add(ray_SP, ray_dir), c);

}
