#include "Thing.h"

Thing::Thing(float xPos, float yPos) : position(xPos, yPos) 
{

}

void Thing::Update(float delta) 
{

}

void Thing::Draw(LineRenderer* lines)
{

	lines->DrawCircle(position, raduis);
}