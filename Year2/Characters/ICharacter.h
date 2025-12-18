#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include "ICharacterObserver.h"
#include "../Logging/LogLevel.h"

class ICharacter {
protected:
    int attackPower;
    int currentHealth;
    int maxHealth;
    int mana;
    std::string name;
    int defense;
    std::vector<ICharacterObserver*> observers;
    void notifyObservers(const std::string& action, LogLevel level);

public:
    // Constructors
    ICharacter() = delete;
    ICharacter(int attackPower, int currentHealth, int maxHealth, int mana, const std::string& name, int defense);

    // Observer management
    void addObserver(ICharacterObserver* observer);
    void removeObserver(ICharacterObserver* observer);

    // Accessors
    std::string getName() const;
    int getCurrentHealth() const;
    int getMaxHealth() const;
    int getMana() const;
    int getDefense() const;

    // Actions
    virtual void attack(ICharacter& target);
    virtual void specialMove(ICharacter& target) = 0;
    void takeDamage(int damage);
    void heal();
    

    // Destructor
    virtual ~ICharacter() = default;
};
