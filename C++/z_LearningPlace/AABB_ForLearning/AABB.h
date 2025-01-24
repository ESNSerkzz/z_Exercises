#pragma once
#include <raylib.h>
#include "RayLine.h"
#include <algorithm>

struct Rect
{
	Vector2 pos;
	Vector2 size;

};

struct rayHitResult
{
	bool hit;
	Vector2 normal;
	Vector2 hitPos;
	float t;
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

	bool RayVsRect(RayLine ray, rayHitResult& hitResult)
	{
		
		
		Vector2 nearP = Vector2Subtract(box.pos, ray.ray_SP );
		nearP = Vector2Divide(nearP, ray.ray_dir);
		Vector2 farP = Vector2Subtract(Vector2Add(box.pos, box.size), ray.ray_SP); 
		farP = Vector2Divide(farP, ray.ray_dir);

		if (nearP.x > farP.x)
		{
			std::swap(farP.x, nearP.x);
		}
		if (nearP.y > farP.y)
		{
			std::swap(farP.y, nearP.y);
		}
		if (nearP.x > farP.y || nearP.y > farP.x) return false;
		

		float hitNear = std::max(nearP.x, nearP.y);
		float hitFar = std::min(farP.x, farP.y);

		if (hitFar < 0) return false;
		
		hitResult.hitPos = {
		ray.ray_SP.x + hitNear * ray.ray_dir.x, ray.ray_SP.y + hitNear * ray.ray_dir.y
		};
		if (nearP.x > nearP.y) 
		{
			if (ray.ray_dir.x < 0)
			{
				hitResult.normal = { 1, 0 };

			}
			else
			{
				hitResult.normal = { -1, 0 };
			}
		}

		else 
		{
			if (ray.ray_dir.y < 0)
			{
				hitResult.normal = { 0,1 };
			}
			else 
			{
				hitResult.normal = {0, -1};
			}

		}
		return (hitNear < 1);


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
