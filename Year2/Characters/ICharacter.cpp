#include "ICharacter.h"
#include "ICharacterObserver.h"
#include "../Logging/LogLevel.h"

ICharacter::ICharacter(int attackPower, int currentHealth, int maxHealth, int mana, const std::string& name, int defense)
    : attackPower(attackPower), currentHealth(currentHealth), maxHealth(maxHealth), mana(mana), name(name), defense(defense) {}

std::string ICharacter::getName() const { return name; }
int ICharacter::getCurrentHealth() const { return currentHealth; }
int ICharacter::getMaxHealth() const { return maxHealth; }
int ICharacter::getMana() const { return mana; }
int ICharacter::getDefense() const { return defense; }

void ICharacter::takeDamage(int damage) {
    int net = damage - defense;
    if (net < 0) net = 0;
    currentHealth -= net;
    if (currentHealth < 0) currentHealth = 0;
    notifyObservers(std::string(name + " took " + std::to_string(net) + " damage"), LogLevel::ACTION);
}

void ICharacter::heal() {
    int amount = maxHealth / 10; // 10% of maxHealth
    if (amount <= 0) amount = 1;
    currentHealth += amount;
    if (currentHealth > maxHealth) currentHealth = maxHealth;
    notifyObservers(std::string(name + " healed for " + std::to_string(amount)), LogLevel::ACTION);
}

void ICharacter::attack(ICharacter& target) {
    target.takeDamage(this->attackPower);
    notifyObservers(std::string(name + " attacked " + target.getName()), LogLevel::ACTION);
}

void ICharacter::addObserver(ICharacterObserver* observer) {
    if (std::find(observers.begin(), observers.end(), observer) == observers.end())
        observers.push_back(observer);
}

void ICharacter::removeObserver(ICharacterObserver* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void ICharacter::notifyObservers(const std::string& action, LogLevel level) {
    for (auto* o : observers) {
        if (o) o->onAction(action, level);
    }
}
