#include "Blocks.h"
#include "Collisions.h"
#include "Constants.h"
#include "ScreenGrid.h"

static void SetUp(void);
static void Update(float delta);
static void Draw(void);

int main(void)
{
	SetUp();
	while (!WindowShouldClose())
	{
		Draw();
		Update(GetFrameTime());
		EndDrawing();
	}
}

static void SetUp(void)
{
	InitWindow(screenWidth,screenHeight, "Window");
	SetTargetFPS(60);
}

static void Update(float delta)
{

}

static void Draw(void)
{
	BeginDrawing();
	ClearBackground(BLACK);
}
