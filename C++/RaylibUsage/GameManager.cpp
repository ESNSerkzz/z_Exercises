#include "GameManager.h"

GameManager::GameManager(Pacman* _pacman, Ghosts* _G1, Ghosts* _G2, Ghosts* _G3, Ghosts* _G4)
{
    pacman = _pacman;
    ghosts.push_back(_G1);
    ghosts.push_back(_G2);
    ghosts.push_back(_G3);
    ghosts.push_back(_G4);
    GameStarted = false;

}

void GameManager::ChangeBehaviourState(Behaviour _beh)
{
    for (int i = 0; i < ghosts.size(); i++)
    {
        ghosts[i]->currentBehaviour = _beh;
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
    if (GetTime() > fromStartTimer + 27 && GetTime() < 34 + fromStartTimer  )
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

    if (pacman->powerTimeRemaining > 0) 
    {
        ChangeBehaviourState(Behaviour::FRIGHTENED);
    }
};
