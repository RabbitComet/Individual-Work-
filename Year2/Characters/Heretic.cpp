#include "Heretic.h"
#include "../Logging/LogLevel.h"

Heretic::Heretic(const std::string& name)
    : ICharacter(15, 85, 15, name, 5) {}

void Heretic::specialMove(ICharacter& target) {
    const int cost = 10;
    if (mana >= cost) {
        mana -= cost;
    } else {
        // sacrifice 5 HP to fuel the move
        currentHealth -= 5;
        if (currentHealth < 0) currentHealth = 0;
        notifyObservers(std::string(name + " sacrificed 5 HP to fuel the Sacrificial Strike"), LogLevel::WARNING);
    }

    int missing = maxHealth - currentHealth;
    int bonus = missing / 2; // half of missing health
    int damage = attackPower + bonus;

    notifyObservers(std::string(name + " used Sacrificial Strike on " + target.getName()), LogLevel::ACTION);
    target.takeDamage(damage);
}
