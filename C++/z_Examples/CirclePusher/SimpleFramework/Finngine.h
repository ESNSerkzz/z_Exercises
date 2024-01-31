#pragma once

#include "Application.h"
#include "Thing.h"
#include <vector>


class Finngine : public Application
{
private:
	std::vector<Thing> things;


public:
	Finngine();

	void Update(float delta) override;

	void OnLeftClick() override;

};