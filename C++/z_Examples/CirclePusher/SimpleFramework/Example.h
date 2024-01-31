#pragma once

#include "Application.h"
#include "Maths.h"

class Example : public Application
{
public:

	Example();

	void Update(float delta) override;

	void OnLeftClick() override;

};