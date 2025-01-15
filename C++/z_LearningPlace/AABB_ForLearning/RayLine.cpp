#include "RayLine.h"

RayLine::RayLine()
{
}

RayLine::RayLine(Vector2 start, Vector2 end, float rayDir)
{
	ray_SP = start;
	ray_EP = end;
	dir = rayDir;
	rayDir = start.x, start.y - end.x, end.y;


}

void RayLine::Draw(Color c)
{
	DrawLineV(ray_SP, ray_EP, c);

}
