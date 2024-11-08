#pragma once
#include "MapGrid.h"



MapGrid::MapGrid(imageType type)
{
	switch (type)
	{
	case SHIP:
		points.push_back({ 0,3 });
		points.push_back({ 2,-3 });
		points.push_back({ -2,-3 });
		break;


	case ASTEROID:
		points.push_back({ -4,-6 });
		points.push_back({ 4,-6 });
		points.push_back({ 9,-2 });
		points.push_back({ 9, 2 });
		points.push_back({ 4, 6 });
		points.push_back({ -4,6 });
		points.push_back({ -9,2 });
		points.push_back({ -9,-2 });
		break;

	case BULLET:
		points.push_back({ 0, 0 });
		points.push_back({ 1, -1 });
		points.push_back({ 0, 1 });
		points.push_back({ -1, -1 });
		break;


	default:
		break;


	}
}

MapGrid::MapGrid()
{

}
void MapGrid::Draw(float rotation, Vector2 scale, Vector2 pos)
{
	std::vector <std::pair <float, float>> transformedPoints;
	int verts = points.size();

	transformedPoints.resize(verts);

	for (int i = 0; i < verts; i++)
	{
		transformedPoints[i].first = points[i].first * cosf(rotation) - points[i].second * sinf(rotation);
		transformedPoints[i].second = points[i].first * sinf(rotation) + points[i].second * cosf(rotation);

		transformedPoints[i].first = transformedPoints[i].first * scale.x;
		transformedPoints[i].second = transformedPoints[i].second * scale.y;

		transformedPoints[i].first += pos.x;
		transformedPoints[i].second += pos.y;

	}

	for (int i = 0; i < verts; i++)
	{
		int j = (i + 1);
		DrawLine
		(
			transformedPoints[i % verts].first,
			transformedPoints[i % verts].second,
			transformedPoints[j % verts].first,
			transformedPoints[j % verts].second,
			RAYWHITE
		);
		DrawLine
		(
			transformedPoints[i % verts].first - screenWidth,
			transformedPoints[i % verts].second,
			transformedPoints[j % verts].first - screenWidth,
			transformedPoints[j % verts].second,
			RAYWHITE
		);

		DrawLine
		(
			transformedPoints[i % verts].first,
			transformedPoints[i % verts].second - screenHeight,
			transformedPoints[j % verts].first,
			transformedPoints[j % verts].second - screenHeight,
			RAYWHITE
		);
		DrawLine
		(
			transformedPoints[i % verts].first - screenWidth,
			transformedPoints[i % verts].second - screenHeight,
			transformedPoints[j % verts].first - screenWidth,
			transformedPoints[j % verts].second - screenHeight,
			RAYWHITE
		);

		DrawLine
		(
			transformedPoints[i % verts].first + screenWidth,
			transformedPoints[i % verts].second,
			transformedPoints[j % verts].first + screenWidth,
			transformedPoints[j % verts].second,
			RAYWHITE
		);

		DrawLine
		(
			transformedPoints[i % verts].first,
			transformedPoints[i % verts].second + screenHeight,
			transformedPoints[j % verts].first,
			transformedPoints[j % verts].second + screenHeight,
			RAYWHITE
		);
		DrawLine
		(
			transformedPoints[i % verts].first + screenWidth,
			transformedPoints[i % verts].second + screenHeight,
			transformedPoints[j % verts].first + screenWidth,
			transformedPoints[j % verts].second + screenHeight,
			RAYWHITE
		);
	}
}