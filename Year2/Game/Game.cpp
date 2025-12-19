#include "Game.h"
#include "../Logging/ConsoleLogger.h"
#include "../Logging/FileLogger.h"
#include "../Logging/FileWriter.h"
#include "../Logging/LogLevel.h"
#include "../Characters/ConsoleObserver.h"
#include "../Characters/FileObserver.h"
#include <iostream>
#include <limits>

Game::Game() {
    fileWriter = nullptr;
    factory = nullptr;
    addConsoleLogger();
    addFileLogger("game_log.txt");
    addConsoleObserver();
    addFileObserver();
    makeFactory();
}

Game::~Game() {
    for (auto* c : characters) delete c;
    delete factory;
    for (auto* o : observers) delete o;
    for (auto* l : loggers) delete l;
    delete fileWriter;
}

void Game::createCharacter() {
    if (!factory) {
        for(auto& logger : loggers){
            logger->log(LogLevel::WARNING, std::string("No Factory "));
        }
        return;
    }

    int type = 0;
    // repeat until a valid type is entered
    while (type != 1 && type != 2) {
        std::cout << "Choose character type (1=Paladin, 2=Heretic): ";
        if (!(std::cin >> type)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter 1 or 2." << std::endl;
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    }

    std::string name;
    // repeat until a non-empty name is provided
    while (true) {
        std::cout << "Enter name: ";
        std::getline(std::cin, name);
        if (!name.empty()) break;
        std::cout << "Name cannot be empty. Please enter a name." << std::endl;
    }

    ICharacter* c = factory->createCharacter(type, name);
    if (c) {
        characters.push_back(c);
    } else {
        
        for(auto& logger : loggers){
            logger->log(LogLevel::WARNING, std::string("Failed to create character type: ") + std::to_string(type));
        }
    }
}

void Game::startGame() {
    // create two characters interactively
    createCharacter();
    createCharacter();
}

bool Game::playTurn() {
    if (characters.empty()) {
        for(auto& logger : loggers){
            logger->log(LogLevel::WARNING, "No characters to play a turn");
        }
        return false;
    }

   for(auto& player: characters){
        int action = 0;
        while (action < 1 || action > 3) {
            std::cout << player->getName() << "'s turn. Choose action (1=attack, 2=special, 3=heal): ";
            if (!(std::cin >> action)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter 1, 2, or 3." << std::endl;
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        ICharacter& target = (player == characters[0]) ? *characters[1] : *characters[0];
        if (action == 1) {
            // attack the other character
            player->attack(target);
        } else if (action == 2) {
            // special move on the other character
            player->specialMove(target);
        } else if (action == 3) {
            // heal
            player->heal();
        }
        if(isGameOver()) return true;
   }
   return false;
}
bool Game::isGameOver() {
    int defeated = 0;
    for(auto& player: characters){
        if(player->getCurrentHealth()<=0){
            defeated++;
            for(auto& logger : loggers){
                logger->log(LogLevel::INFO, std::string(player->getName() + " has been defeated!"));
            }
        }
    }
    if(defeated==2){
        for(auto& logger : loggers){
                logger->log(LogLevel::INFO, std::string("It's a draw! Both players have been defeated."));
            }
            return true;
    }
    if(defeated==1){

                for(auto& logger : loggers){
                    logger->log(LogLevel::INFO, "Game is over!");
                }
        return true;
    }
    return false;
}

void Game::addConsoleLogger() {
    ILogger* console = new ConsoleLogger();
    loggers.push_back(console);
}

void Game::addFileLogger(const std::string& filename) {
    fileWriter = new FileWriter(filename);
    ILogger* fileLogger = new FileLogger(fileWriter);
    loggers.push_back(fileLogger);
}

void Game::addConsoleObserver() {
    ILogger* console = nullptr;
    if (!loggers.empty()) console = loggers[0];
    ICharacterObserver* obs = new ConsoleObserver(console);
    observers.push_back(obs);
}

void Game::addFileObserver() {
    ILogger* fileLogger = nullptr;
    if (loggers.size() > 1) fileLogger = loggers[1];
    ICharacterObserver* obs = new FileObserver(fileLogger);
    observers.push_back(obs);
}

void Game::makeFactory() {
    factory = new CharacterFactory(observers);
}
