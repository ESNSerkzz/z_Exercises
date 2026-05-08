#include "GameManager.h"

GameManager::GameManager(MapGrid* _map, Pacman* _pacman, Ghosts* _G1, Ghosts* _G2, Ghosts* _G3, Ghosts* _G4)
{
    pacman = _pacman;
    ghosts.push_back(_G1);
    ghosts.push_back(_G2);
    ghosts.push_back(_G3);
    ghosts.push_back(_G4);
    GameStarted = false;

}

bool GameManager::GhostOverlap()
{
    for (auto& i : ghosts)
    {
        if (i->currentTileCoord == pacman->currentTileCoord) 
            return true;
    }
    return false;
}

void GameManager::ChangeBehaviourState(Behaviour _beh)
{

    for (int i = 0; i < ghosts.size(); i++)
    {
   
        ghosts[i]->currentBehaviour = _beh;
       
        if (ghosts[i]->currentBehaviour != Behaviour::FRIGHTENED)
        {
            ghosts[i]->velocity = speed;
            pacman->velocity = speed;
        }
        if (ghosts[i]->currentBehaviour == Behaviour::FRIGHTENED)
        {
            ghosts[i]->velocity = speed / 2;
            pacman->velocity = (speed * 1.1);
        }
    }

}

bool GameManager::Paused(bool _TF)
{
    bool paused = _TF;

    while (paused == true)
    {
        pacman->velocity = 0;
        //ghosts->velocity = 0;
    }

    return paused;
};

void GameManager::Update(float delta)
{
    if (GetTime() > fromStartTimer && !GameStarted)
    {
        GameStarted = true;
        pacman->isControllable = true;
        ChangeBehaviourState(Behaviour::SCATTER);
    }
    if (GetTime() > fromStartTimer + 7 && GetTime() < fromStartTimer + 27)
    {
        ChangeBehaviourState(Behaviour::CHASE);
    }
    if (GetTime() > fromStartTimer + 27 && GetTime() < 34 + fromStartTimer)
    {
        ChangeBehaviourState(Behaviour::SCATTER);

    }
    if (GetTime() > fromStartTimer + 34 && GetTime() < 54 + fromStartTimer)
    {
        ChangeBehaviourState(Behaviour::CHASE);
    }
    if (GetTime() > fromStartTimer + 54 && GetTime() < 59 + fromStartTimer)
    {
        ChangeBehaviourState(Behaviour::SCATTER);
    }
    if (GetTime() > fromStartTimer + 59 && GetTime() < 79 + fromStartTimer)
    {
        ChangeBehaviourState(Behaviour::CHASE);
    }
    if (GetTime() > fromStartTimer + 79 && GetTime() < 84 + fromStartTimer)
    {
        ChangeBehaviourState(Behaviour::SCATTER);
    }
    if (GetTime() > fromStartTimer + 84)
    {
        ChangeBehaviourState(Behaviour::CHASE);
    }

    if (pacman->powerTimeRemaining > 0.0f && GetTime() > fromStartTimer) 
    {
       ChangeBehaviourState(Behaviour::FRIGHTENED);
       //??
    }
    if (map->pallatesRemaining == 0)
    {

    }
    if (GhostOverlap())
    {
        std::cout << " overlapped" << std::endl;
    }
};
