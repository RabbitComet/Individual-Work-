#include <iostream>
#include "Logging/ConsoleLogger.h"
#include "Logging/FileLogger.h"
#include "Logging/FileWriter.h"
#include "../Characters/ICharacter.h"
#include "../Characters/ConsoleObserver.h"
#include "../Characters/FileObserver.h"

// Simple concrete character for testing
class TestCharacter : public ICharacter {
public:
    TestCharacter(int atk, int curHp, int maxHp, int mana, const std::string& name, int def)
        : ICharacter(atk, curHp, maxHp, mana, name, def) {}

    void specialMove(ICharacter& target) override {
        // special move: deal double attack
        target.takeDamage(this->attackPower * 2);
    }
};

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
        TestCharacter a(10, 50, 50, 10, "Alice", 2);
        TestCharacter b(8, 40, 40, 5, "Bob", 1);

        a.addObserver(&cObs);
        a.addObserver(&fObs);

        // Actions
        a.attack(b);          // should notify observers
        b.takeDamage(5);      // should notify observers on b
        a.heal();             // should notify observers
        a.specialMove(b);     // should NOT notify (per design)

        std::cout << "Observer test finished. Check test_log.txt and console output." << std::endl;
    } catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
        return 1;
    }

    return 0;
}
