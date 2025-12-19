#include <iostream>
#include "../Game/Game.h"

int main() {
    try {
        Game game;
        game.startGame();

        // main loop: play turns until checkPlayers reports the game ended
        bool state = false;
       do{
             state = game.playTurn();
        }while(!state);

    } catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
        return 1;
    }

    std::cin.ignore();

    return 0;
}

