#include <raylib.h>
#include <raymath.h>
#include "AABB.h"
#include "iostream"

void SetUp();
void Update(float delta);
void Draw();

AABB pMouse;
AABB rectangle;
RayLine rayLine;
rayHitResult MhitResult;


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
	rayLine = RayLine({ {100, 250}, {300, 250}, });

}

void Update(float delta)
{
	//visual test (remove later or something)




	pMouse.UpdatePos({ (float) GetMouseX(), (float) GetMouseY() });
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		rayLine.ray_SP = GetMousePosition();
	}
	
	rayLine.ray_dir = Vector2Subtract(GetMousePosition(), rayLine.ray_SP);


}

void Draw()
{
	BeginDrawing();
	ClearBackground(BLACK);

	rectangle.Draw(WHITE);
	//pMouse.Draw(BLUE);
	rayLine.Draw(GREEN);

	
	/*if (rectangle.RectVsRect(pMouse))
	{
		rectangle.Draw(RED);
	}*/

	if (rectangle.RayVsRect(rayLine, MhitResult))
	{
		rectangle.Draw(RED);

		DrawRectangle(MhitResult.hitPos.x - 5, MhitResult.hitPos.y - 5, 10, 10, YELLOW);
		DrawLine(MhitResult.hitPos.x, MhitResult.hitPos.y, MhitResult.hitPos.x + (MhitResult.normal.x * 30), MhitResult.hitPos.y + (MhitResult.normal.y * 30), WHITE);

	}

	EndDrawing();
}