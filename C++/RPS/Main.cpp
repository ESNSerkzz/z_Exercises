#include "RPS.h"

static void SetUp(void);
static void Update();

RPS player;


int main(void)
{
	SetUp();
	//Update();
}

void SetUp(void)
{
	//starting text
	std::cout << "ROCK (R), PAPER (P), SCISSORS (S)" << std::endl;
	player = RPS();

	player.takeInput();
	// inputs R P S
	// tells the user wether the input is correct or not. if not, ask to do it again. 
	
	
}

void Update()
{
	player.Update();
}
	
