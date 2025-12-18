#include "Paladin.h"
#include "../Logging/LogLevel.h"

// Paladin (was Warrior) implementation
Paladin::Paladin(const std::string& name)
    : ICharacter(20, 100, 50, name, 10) {}

void Paladin::specialMove(ICharacter& target) {
    const int cost = 30;
    if (mana < cost) {
        notifyObservers(std::string(name + " Tried to Smite " + target.getName() + " but God did not answer..."), LogLevel::WARNING);
        return;
    }
    // spend mana and deal double damage
    notifyObservers(std::string(name + " used Smite on " + target.getName()), LogLevel::ACTION);
    target.takeDamage(this->attackPower * 2);
    mana -= cost;
}
