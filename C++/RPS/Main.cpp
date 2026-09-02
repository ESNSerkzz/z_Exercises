#include "RPS.h"

static void SetUp(void);
static void Update();

RPS player;


int main(void)
{

	SetUp();
	Update();
}

void SetUp(void)
{
	
	std::cout << "ROCK (R), PAPER (P), SCISSORS (S)" << std::endl;
	std::cin >> player.inputChoice;
	player = RPS(player.inputChoice);
	
}

void Update()
{
	player.Update();
}
	
