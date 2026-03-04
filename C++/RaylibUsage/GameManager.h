#pragma once
#include "Constants.h"
#include "Pacman.h"
#include "Ghosts.h"


class GameManager
{
	//Spwan fruit
	//scatter & chase
	//starting Pause??
	//pacmans lives and death
	//wins state (collect all palletes)
	//ghosts flee from pacman
	//level changes

private:
	Pacman* pacman;
	std::vector<Ghosts*> ghosts;

public:

	bool GameStarted;
	GameManager() {};
	GameManager(Pacman* _pacman, Ghosts* _G1, Ghosts* _G2, Ghosts* _G3, Ghosts* _G4);

	void ChangeBehaviourState(Behaviour _beh);
	bool Paused(bool _TF);
	void Update(float delta);
	
};
