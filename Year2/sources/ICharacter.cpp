#include "../header/ICharacter.h"

ICharacter::ICharacter(int attack, int health, int mana, const std::string& name, int defense)
    : attack(attack), health(health), mana(mana), name(name), defense(defense) {}

std::string ICharacter::getName() const { return name; }
int ICharacter::getHealth() const { return health; }
int ICharacter::getMana() const { return mana; }
int ICharacter::getDefense() const { return defense; }
