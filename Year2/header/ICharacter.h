#pragma once

#include <string>

class ICharacter {
protected:
    int attack;
    int health;
    int mana;
    std::string name;
    int defense;

public:
    // Constructors
    ICharacter() = delete;
    ICharacter(int attack, int health, int mana, const std::string& name, int defense);

    // Accessors
    std::string getName() const;
    int getHealth() const;
    int getMana() const;
    int getDefense() const;

    // Actions
    virtual void attack(ICharacter& target) = 0;
    virtual void defend() = 0;

    // Destructor
    virtual ~ICharacter() = default;
};
