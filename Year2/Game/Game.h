#pragma once

#include <vector>
#include "../Logging/ILogger.h"
#include "../Characters/ICharacterObserver.h"
#include "../Characters/ICharacter.h"
#include "CharacterFactory.h"

class FileWriter;

class Game {
public:
    Game();
    ~Game();
    // Start the game by creating two characters interactively
    void startGame();
    // Play one turn: each character chooses an action (1=attack,2=special,3=heal)
    bool playTurn();
    // Check players' health and log result; returns true if game ended
    bool isGameOver();
    // Prompt user and create a character (adds to internal vector)
    void createCharacter();

private:
    std::vector<ILogger*> loggers;
    std::vector<ICharacterObserver*> observers;
    std::vector<ICharacter*> characters;
    CharacterFactory* factory = nullptr;
    FileWriter* fileWriter = nullptr;

    // setup helpers
    void addConsoleLogger();
    void addFileLogger(const std::string& filename);
    void addConsoleObserver();
    void addFileObserver();
    void makeFactory();
};
