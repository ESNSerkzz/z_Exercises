#include <raylib.h>
#include <raymath.h>
#include "AABB.h"


void SetUp();
void Update(float delta);
void Draw();

AABB pMouse;
AABB rectangle;
RayLine rayLine;


int main(void)
{
	SetUp();
	while (!WindowShouldClose())
	{
		Update(GetFrameTime());
		Draw();
		
	}
}

void SetUp()
{
	InitWindow(2000, 1200, "window");
	SetTargetFPS(60);

	pMouse = AABB({ {0,0},{100, 100} });
	rectangle = AABB({ { 200, 200 }, { 100, 100 } });
	rayLine = RayLine({ {100, 250}, {300, 250}, {rayLine.dir} });

}

void Update(float delta)
{
	pMouse.UpdatePos({ (float) GetMouseX(), (float) GetMouseY() });
	rayLine.ray_EP = { (float)GetMouseX(), (float)GetMouseY() };
}

void Draw()
{
	BeginDrawing();
	ClearBackground(BLACK);

	rectangle.Draw(WHITE);
	pMouse.Draw(BLUE);
	rayLine.Draw(GREEN);

	
	if (rectangle.RectVsRect(pMouse))
	{
		rectangle.Draw(RED);
	}

	//if (rectangle.RayVsRect(rayLine))

	EndDrawing();
}