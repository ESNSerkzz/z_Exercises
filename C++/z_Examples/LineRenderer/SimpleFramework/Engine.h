#pragma once
#include "Application.h"
#include "Thing.h"
#include <vector>

class Engine : public Application
{
private:
	std::vector<Thing> things;


public:
	Engine();

	void Update(float delta) override;

	void OnLeftClick() override;
};

