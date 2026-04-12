#pragma once
#include "Constants.h"
#include "Pacman.h"
#include "Ghosts.h"
#include "MapGrid.h"


class GameManager
{
	//Spwan fruit
	
	
	//pacmans lives and death
	//wins state (collect all palletes)
	//ghosts flee from pacman
	//level changes

private:
	Pacman* pacman;
	MapGrid* map;
	std::vector<Ghosts*> ghosts;

public:

	bool GameStarted;
	GameManager() {};
	GameManager(MapGrid* _map, Pacman* _pacman, Ghosts* _G1, Ghosts* _G2, Ghosts* _G3, Ghosts* _G4);

	bool GhostOverlap();
	void ChangeBehaviourState(Behaviour _beh);
	bool Paused(bool _TF);
	void Update(float delta);
	
};
