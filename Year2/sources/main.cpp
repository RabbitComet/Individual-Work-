#include <iostream>
#include "Logging/ConsoleLogger.h"
#include "Logging/FileLogger.h"
#include "Logging/FileWriter.h"
#include "../Characters/ICharacter.h"
#include "../Characters/ConsoleObserver.h"
#include "../Characters/FileObserver.h"

#include "../Characters/Paladin.h"
#include "../Characters/Heretic.h"

int main() {
    try {
        ConsoleLogger console;
        console.log(LogLevel::INFO, "Console logger initialised");

        FileWriter writer("test_log.txt");
        FileLogger fileLogger(&writer);

        // Observers
        ConsoleObserver cObs(&console);
        FileObserver fObs(&fileLogger);

        // Create characters
        Paladin paladin("Uther");
        Heretic heretic("Morgana");

        paladin.addObserver(&cObs);
        paladin.addObserver(&fObs);
        heretic.addObserver(&cObs);
        heretic.addObserver(&fObs);

        console.log(LogLevel::INFO, "Starting Paladin vs Heretic test");

        // Basic interactions
        paladin.attack(heretic);
        heretic.attack(paladin);

        // Test special moves (Paladin costs 30 mana)
        paladin.specialMove(heretic); // should succeed
        paladin.specialMove(heretic); // likely insufficient mana -> WARNING

        // Test Heretic special (costs 10 mana or sacrifice if insufficient)
        heretic.specialMove(paladin); // should succeed
        heretic.specialMove(paladin); // may sacrifice HP if mana low

        // Heal actions
        paladin.heal();
        heretic.heal();

        std::cout << "Paladin/Heretic test finished. Check test_log.txt and console output." << std::endl;
    } catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
        return 1;
    }

    return 0;
}
