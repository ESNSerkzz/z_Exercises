#pragma once
#include <raylib.h>
#include "RayLine.h"

struct Rect
{
	Vector2 pos;
	Vector2 size;

};

class AABB
{
public:

	Rect box;
	RayLine ray;

	AABB();
	AABB(Rect rectangle);
	

	void Draw(Color c);
	void UpdatePos(Vector2 newPos);


	bool PointVsRect(Vector2 p)
	{
		return
			(p.x >= box.pos.x &&
			p.y >= box.pos.y &&
			p.x <= box.pos.x + box.size.x &&
			p.y <= box.pos.y + box.size.y);
	}

	bool RectVsRect(AABB r)
	{
		return(
			box.pos.x < r.box.pos.x + r.box.size.x &&
			box.pos.x + box.size.x > r.box.pos.x&&
			box.pos.y < r.box.pos.y + r.box.size.y &&
			box.pos.y + box.size.y > r.box.pos.y
			);

	}

	bool RayVsRect(RayLine ray, Rect rec, float t)
	{
		t = ray.ray_SP.x, ray.ray_SP.y + ray.dir * t;
		
		float nearP = rec.pos.x - ray.ray_SP.x &&  rec.pos.y - ray.ray_SP.y / ray.dir;
		float farP = rec.pos.x + rec.size.x - ray.ray_SP.x && rec.pos.y + rec.size.y - ray.ray_SP.y / ray.dir;
		
		// you were at the part were near point x was less than far point y.
		// (you were contemplating it like it's a circle, 
		// where the only time the near point x isn't less than far point y is when its 90 degrees right angle )
		/*return(
			
			);*/
		
	}


	/*bool MousePointUpdate(float delta) 
	{
		Vector2 pMouse = { float(GetMouseX()), float(GetMouseY()) };

		Rect rectangle = { { 200, 200 }, { 50, 80 } };
		Rect spot = { pMouse, {20, 20} };


		if (PointVsRect(rectangle, pMouse))
			DrawRectangleV(rectangle.pos, rectangle.size, YELLOW);
		else
			DrawRectangleV(rectangle.pos, rectangle.size, WHITE);
	}*/


};
